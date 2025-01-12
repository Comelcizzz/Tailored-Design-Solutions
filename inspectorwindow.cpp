#include "inspectorwindow.h"
#include "ui_inspectorwindow.h"
#include "databasemanager.h"
#include <QDate>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

InspectorWindow::InspectorWindow(Auth& auth, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::InspectorWindow),
    auth(auth)
{
    ui->setupUi(this);
    setWindowTitle("Inspector Window");

    connect(ui->btnLoadOrders, &QPushButton::clicked, this, &InspectorWindow::loadOrders);
    connect(ui->btnTakeOrder, &QPushButton::clicked, this, &InspectorWindow::on_btnTakeOrder_clicked);
    connect(ui->btnSaveDetails, &QPushButton::clicked, this, &InspectorWindow::on_btnSaveDetails_clicked);
    connect(ui->btnLoadCompletedOrders, &QPushButton::clicked, this, &InspectorWindow::loadCompletedOrders);

    loadInspectorOrders();
}

InspectorWindow::~InspectorWindow()
{
    delete ui;
}

void InspectorWindow::loadOrders() {
    ui->ordersListWidget->clear();

    QList<OrderDetails> ordersList;

    DatabaseManager &dbManager = DatabaseManager::instance("database.db");

    if (!dbManager.loadOrdersForInspector(ordersList)) {
        QMessageBox::warning(this, "Error", "Failed to load pending orders.");
        return;
    }

    if (ordersList.isEmpty()) {
        QMessageBox::information(this, "No Orders", "There are no pending orders for inspection.");
    } else {
        for (const OrderDetails &order : ordersList) {
            QString orderInfo = QString("Order ID: %1 | Customer: %2 | Address: %3")
            .arg(order.getOrderId())
                .arg(order.getUserEmail())
                .arg(order.getAddress());

            ui->ordersListWidget->addItem(orderInfo);
        }
    }
}

void InspectorWindow::on_btnTakeOrder_clicked() {
    QListWidgetItem* selectedItem = ui->ordersListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Error", "Please select an order to take.");
        return;
    }

    QString orderDetails = selectedItem->text();
    int orderId = orderDetails.split(" | ")[0].split(": ")[1].toInt();

    qDebug() << "Order ID selected: " << orderId;

    DatabaseManager &dbManager = DatabaseManager::instance();

    if (!dbManager.isConnected()) {
        QMessageBox::critical(this, "Error", "Database connection is not available.");
        return;
    }

    if (!dbManager.takeOrderForInspector(orderId, auth.getCurrentUserEmail())) {
        QMessageBox::critical(this, "Error", "Failed to update order status. Please try again.");
        return;
    }

    ui->leOrderId->setText(QString::number(orderId));
    QMessageBox::information(this, "Success", "Order status updated successfully.");

    ui->ordersListWidget->clear();

    loadOrders();
}

void InspectorWindow::updateOrderStatus(int orderId, const QString &status)
{

}

void InspectorWindow::on_btnSaveDetails_clicked()
{
    int customerOrderId = ui->leOrderId->text().toInt();
    QString mediaLink = ui->leMediaLink->text().trimmed();
    QString workDescription = ui->teWorkDescription->toPlainText().trimmed();
    QString requiredMaterials = ui->teRequiredMaterials->toPlainText().trimmed();

    if (customerOrderId <= 0 || mediaLink.isEmpty() || workDescription.isEmpty() || requiredMaterials.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields must be filled.");
        return;
    }

    QString inspectorEmail = auth.getCurrentUserEmail();

    DatabaseManager& dbManager = DatabaseManager::instance();
    if (!dbManager.saveDetailsForInspector(customerOrderId, mediaLink, workDescription, requiredMaterials, inspectorEmail)) {
        QMessageBox::critical(this, "Error", "Failed to save inspector details.");
        qDebug() << "Error: Failed to save inspector details.";
    } else {
        QMessageBox::information(this, "Success", "Work details saved successfully.");
        qDebug() << "Success: Work details saved successfully.";
    }
}

void InspectorWindow::loadInspectorOrders() {
    ui->lwOrders->clear();

    QString inspectorEmail = auth.getCurrentUserEmail();

    QVector<OrderDetails> orders;
    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.loadInspectorOrdersForInspector(inspectorEmail, orders)) {
        QMessageBox::warning(this, "Error", "Failed to load orders.");
        return;
    }

    if (orders.isEmpty()) {
        return;
    }

    for (const OrderDetails &order : orders) {
        QString orderDetails = QString("ID: %1 | User: %2 (%3) | Status: %4 | Address: %5 | Phone: %6\n"
                                       "Description: %7\n"
                                       "Media Link: %8\n"
                                       "Date: %9")
                                   .arg(order.getOrderId())
                                   .arg(order.getUserEmail())
                                   .arg(order.getUserName())
                                   .arg(order.getStatus())
                                   .arg(order.getAddress())
                                   .arg(order.getPhone())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getMediaLink())
                                   .arg(order.getOrderDate());

        ui->lwOrders->addItem(orderDetails);
    }
}

void InspectorWindow::loadCompletedOrders() {
    ui->lwCompletedOrders->clear();

    QString inspectorEmail = auth.getCurrentUserEmail();

    QVector<OrderDetails> orders;
    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.loadCompletedOrdersForInspector(inspectorEmail, orders)) {
        QMessageBox::warning(this, "Error", "Failed to load completed orders.");
        return;
    }

    if (orders.isEmpty()) {
        QMessageBox::information(this, "No Orders", "No completed orders found.");
        return;
    }

    for (const OrderDetails &order : orders) {
        QString orderDetails = QString("ID: %1 | User: %2 (%3) | Status: %4 | Address: %5 | Phone: %6\n"
                                       "Media Link: %7\nWork Description: %8\nRequired Materials: %9\nOrder Date: %10")
                                   .arg(order.getOrderId())
                                   .arg(order.getUserEmail())
                                   .arg(order.getUserName())
                                   .arg(order.getStatus())
                                   .arg(order.getAddress())
                                   .arg(order.getPhone())
                                   .arg(order.getMediaLink())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getRequiredMaterials())
                                   .arg(order.getOrderDate());

        ui->lwCompletedOrders->addItem(orderDetails);
    }
}

void InspectorWindow::on_btnLoadOrdersInProgress_clicked()
{
    loadInspectorOrders();
}

void InspectorWindow::on_btnLoadOrders_clicked()
{

}

void InspectorWindow::on_btnSearchInspector_clicked()
{
    ui->lwCompletedOrders->clear();
    QString searchText = ui->leSearch->text().trimmed();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter search criteria.");
        return;
    }
    loadSearchResults(searchText);
}

void InspectorWindow::loadSearchResults(const QString &searchText)
{
    QVector<OrderDetails> orders;
    DatabaseManager& dbManager = DatabaseManager::instance();

    if (!dbManager.searchOrdersForInspector(searchText, orders)) {
        QMessageBox::warning(this, "Error", "Failed to load search results.");
        return;
    }

    if (orders.isEmpty()) {
        QMessageBox::information(this, "No Results", "No orders match your search criteria.");
        return;
    }

    for (const OrderDetails &order : orders) {
        QString orderDetails = QString("ID: %1 | User: %2 (%3) | Status: %4 | Address: %5 | Phone: %6\n"
                                       "Description: %7\n"
                                       "Media Link: %8\n"
                                       "Date: %9")
                                   .arg(order.getOrderId())
                                   .arg(order.getUserEmail())
                                   .arg(order.getUserName())
                                   .arg(order.getStatus())
                                   .arg(order.getAddress())
                                   .arg(order.getPhone())
                                   .arg(order.getWorkDescription())
                                   .arg(order.getMediaLink())
                                   .arg(order.getOrderDate());

        ui->lwCompletedOrders->addItem(orderDetails);
    }
}

void InspectorWindow::on_btnDeleteOrder_clicked() {
    QListWidgetItem* selectedItem = ui->ordersListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Selection Error", "Please select an order to delete.");
        return;
    }

    QString orderDetails = selectedItem->text();
    int orderId = orderDetails.split(" | ")[0].split(": ")[1].toInt();

    if (orderId <= 0) {
        QMessageBox::warning(this, "Invalid Order", "Invalid order ID.");
        return;
    }

    DatabaseManager& dbManager = DatabaseManager::instance();
    QSqlDatabase db = dbManager.getDatabase();
    QSqlQuery query(db);

    query.prepare("UPDATE customerorder SET status = 'Deleted' WHERE id = :orderId");
    query.bindValue(":orderId", orderId);

    if (query.exec()) {
        QMessageBox::information(this, "Success", "Order marked as deleted successfully.");
        delete selectedItem;
    } else {
        qDebug() << "Database error: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to mark order as deleted: " + query.lastError().text());
    }
}

void InspectorWindow::on_btnLoadCompletedOrders_clicked()
{

}

