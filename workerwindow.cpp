#include "workerwindow.h"
#include "ui_workerwindow.h"
#include "databasemanager.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

WorkerWindow::WorkerWindow(Auth& auth, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::WorkerWindow),
    auth(auth)
{
    ui->setupUi(this);
    setWindowTitle("Worker Panel");

    connect(ui->btnLoadOrders, &QPushButton::clicked, this, &WorkerWindow::loadAvailableOrders);
    connect(ui->btnTakeOrder, &QPushButton::clicked, this, &WorkerWindow::acceptOrder);
    connect(ui->btnSaveDetails, &QPushButton::clicked, this, &WorkerWindow::saveWorkDetails);
    connect(ui->btnLoadCompletedOrders, &QPushButton::clicked, this, &WorkerWindow::loadCompletedOrders);
    connect(ui->btnLoadActiveOrders, &QPushButton::clicked, this, &WorkerWindow::loadAcceptedOrders);

    loadAvailableOrders();
}

WorkerWindow::~WorkerWindow()
{
    delete ui;
}

void WorkerWindow::loadAvailableOrders() {
    ui->ordersListWidget->clear();

    QList<OrderDetails> ordersList;

    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.loadAvaibleOrdersForWorkers(ordersList)) {
        QMessageBox::warning(this, "Error", "Failed to load available orders.");
        return;
    }

    if (ordersList.isEmpty()) {
        QMessageBox::information(this, "No Orders", "There are no available orders.");
    } else {
        for (const OrderDetails& order : ordersList) {
            QString orderDetails = QString(
                                       "ID: %1 | Customer: %2 | Address: %3\n"
                                       "Inspector: %4 | Work Description: %5 | Media: %6")
                                       .arg(order.getOrderId())
                                       .arg(order.getCustomerEmail())
                                       .arg(order.getAddress())
                                       .arg(order.getInspectorEmail())
                                       .arg(order.getWorkDescription().isEmpty() ? "N/A" : order.getWorkDescription())
                                       .arg(order.getMediaLink().isEmpty() ? "N/A" : order.getMediaLink());

            ui->ordersListWidget->addItem(orderDetails);
        }
    }
}

void WorkerWindow::loadAcceptedOrders()
{
    ui->acceptedOrdersListWidget->clear();

    QList<OrderDetails> ordersList;

    QString workerEmail = auth.getCurrentUserEmail();

    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.loadAcceptedOrdersForWorkers(workerEmail, ordersList)) {
        QMessageBox::warning(this, "Error", "Failed to load accepted orders.");
        return;
    }

    for (const OrderDetails& order : ordersList) {
        QString orderDetails = QString(
                                   "ID: %1 | Customer: %2 | Address: %3 | Phone: %4\n"
                                   "Work Description: %5\nMedia Link: %6\nStatus: %7\nOrder Date: %8\nInspector: %9"
                                   )
                                   .arg(order.getOrderId())
                                   .arg(order.getCustomerEmail())
                                   .arg(order.getAddress())
                                   .arg(order.getPhone())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getMediaLink())
                                   .arg(order.getStatus())
                                   .arg(order.getOrderDate())
                                   .arg(order.getInspectorEmail());

        ui->acceptedOrdersListWidget->addItem(orderDetails);
    }
}

void WorkerWindow::acceptOrder()
{
    QListWidgetItem* selectedItem = ui->ordersListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Error", "Please select an order to accept.");
        return;
    }

    QString orderDetails = selectedItem->text();
    int orderId = orderDetails.split(" | ")[0].split(": ")[1].toInt();

    DatabaseManager& dbManager = DatabaseManager::instance();
    if (!dbManager.acceptOrderForWorkers(orderId, auth.getCurrentUserEmail())) {
        QMessageBox::critical(this, "Error", "Failed to accept order.");
        return;
    }

    ui->leOrderId->setText(QString::number(orderId));
    QMessageBox::information(this, "Success", "Order accepted successfully.");

    ui->ordersListWidget->clear();

    loadAvailableOrders();
}

void WorkerWindow::saveWorkDetails()
{
    int orderId = ui->leOrderId->text().toInt();
    QString workDescription = ui->teWorkDescription->toPlainText();
    QString mediaLink = ui->leMediaLink->text();

    if (orderId <= 0 || mediaLink.isEmpty() || workDescription.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled.");
        return;
    }


    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.saveWorkDetailsForWorkers(orderId, workDescription, mediaLink, auth.getCurrentUserEmail())) {
        QMessageBox::critical(this, "Error", "Failed to save work details.");
        return;
    }

    QMessageBox::information(this, "Success", "Work details saved and order marked as Done.");
}

void WorkerWindow::viewOrderDetails()
{
    QListWidgetItem* selectedItem = ui->acceptedOrdersListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Error", "Please select an order to view.");
        return;
    }

    QString orderDetailsText = selectedItem->text();
    int orderId = orderDetailsText.split(" | ")[0].split(": ")[1].toInt();

    OrderDetails orderDetails;

    DatabaseManager& dbManager = DatabaseManager::instance();
    if (!dbManager.getWorkDetailsForWorkers(orderId, orderDetails)) {
        QMessageBox::warning(this, "Error", "Failed to retrieve order details.");
        return;
    }

    QString detailsMessage = QString(
                                 "Order ID: %1\nCustomer Email: %2\nAddress: %3\nPhone: %4\nOrder Date: %5\nStatus: %6\n"
                                 "Inspector: %7\nWork Description: %8\nMedia Link: %9")
                                 .arg(orderDetails.getOrderId())
                                 .arg(orderDetails.getCustomerEmail())
                                 .arg(orderDetails.getAddress())
                                 .arg(orderDetails.getPhone())
                                 .arg(orderDetails.getOrderDate())
                                 .arg(orderDetails.getStatus())
                                 .arg(orderDetails.getInspectorEmail())
                                 .arg(orderDetails.getWorkDescription())
                                 .arg(orderDetails.getMediaLink());

    QMessageBox::information(this, "Order Details", detailsMessage);
}

void WorkerWindow::loadCompletedOrders()
{
    ui->completedOrdersListWidget->clear();
    QList<OrderDetails> completedOrders;

    DatabaseManager& dbManager = DatabaseManager::instance();
    if (!dbManager.loadCompletedOrdersForWorkers(auth.getCurrentUserEmail(), completedOrders)) {
        QMessageBox::warning(this, "Error", "Failed to load completed orders.");
        return;
    }
    \
    for (const OrderDetails& order : completedOrders) {
        QString orderDetails = QString(
                                   "ID: %1 | Customer: %2 | Address: %3\n"
                                   "Inspector: %4 | Work Description: %5 | Media: %6"
                                   )
                                   .arg(order.getOrderId())
                                   .arg(order.getCustomerEmail())
                                   .arg(order.getAddress())
                                   .arg(order.getInspectorEmail())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getMediaLink());

        ui->completedOrdersListWidget->addItem(orderDetails);
    }
}

void WorkerWindow::on_btnLoadCompletedOrders_clicked()
{
    loadCompletedOrders();
}

void WorkerWindow::on_btnLoadActiveOrders_clicked()
{
    loadAcceptedOrders();
}

void WorkerWindow::on_btnSaveDetails_clicked()
{

}

void WorkerWindow::on_btnLoadOrders_clicked()
{

}

void WorkerWindow::on_btnSearchOrders_clicked()
{
    ui->completedOrdersListWidget->clear();

    QString searchText = ui->leSearchWorker->text().trimmed();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter search criteria.");
        return;
    }

    QList<OrderDetails> ordersList;
    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.searchAvailableOrdersForWorker(searchText, ordersList)) {
        QMessageBox::warning(this, "Error", "Failed to load search results.");
        return;
    }

    if (ordersList.isEmpty()) {
        QMessageBox::information(this, "No Results", "No orders match your search criteria.");
        return;
    }

    for (const OrderDetails& order : ordersList) {
        QString orderDetails = QString(
                                   "Order ID: %1\n"
                                   "Customer: %2\n"
                                   "Address: %3\n"
                                   "Phone: %4\n"
                                   "Order Date: %5\n"
                                   "Work Description: %6\n"
                                   "Media Link: %7\n"
                                   "Status: %8\n")
                                   .arg(order.getOrderId())
                                   .arg(order.getUserEmail())
                                   .arg(order.getAddress())
                                   .arg(order.getPhone())
                                   .arg(order.getOrderDate())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getMediaLink())
                                   .arg(order.getStatus());

        ui->completedOrdersListWidget->addItem(orderDetails);
    }
}
