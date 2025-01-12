#include "customerwindow.h"
#include "ui_customerwindow.h"
#include "databasemanager.h"
#include "auth.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QRegularExpression>

CustomerWindow::CustomerWindow(Auth& auth, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::CustomerWindow),
    auth(auth)
{
    ui->setupUi(this);
    setWindowTitle("Customer Window");

    QString currentUserEmail = auth.getCurrentUserEmail();
    qDebug() << "Current user email: " << currentUserEmail;

    if (!createDatabaseConnection("database.db")) {
        QMessageBox::warning(this, "Error", "Failed to connect to the database.");
    }
}

CustomerWindow::~CustomerWindow()
{
    db.close();
    delete ui;
}

bool CustomerWindow::createDatabaseConnection(const QString &dbPath) {
    DatabaseManager& dbManager = DatabaseManager::instance(dbPath);

    if (!dbManager.isConnected()) {
        qDebug() << "Database connection failed.";
        return false;
    }

    qDebug() << "Database connection established successfully.";
    return true;
}

void CustomerWindow::on_btnCreate_clicked()
{
    QString userEmail = auth.getCurrentUserEmail();
    QString address = ui->leAddress->text().trimmed();
    QString phone = ui->lePhone->text().trimmed();
    QDateTime orderDate = ui->dateTimeEdit->dateTime();
    QString userGreeting = ui->leUserGreeting->text().trimmed();

    QDateTime currentDateTime = QDateTime::currentDateTime();

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(userEmail).hasMatch()) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }

    if (address.isEmpty() || address.length() < 5) {
        QMessageBox::warning(this, "Invalid Address", "Please enter a valid address with at least 5 characters.");
        return;
    }

    QRegularExpression phoneRegex("^\\+?[0-9]{10,15}$");
    if (!phoneRegex.match(phone).hasMatch()) {
        QMessageBox::warning(this, "Invalid Phone", "Please enter a valid phone number (10-15 digits).");
        return;
    }

    if (orderDate <= currentDateTime.addDays(3) || orderDate >= currentDateTime.addYears(2)) {
        QMessageBox::warning(this, "Invalid Date", "The order date must be at least 3 days in advance and no more than 2 years in the future.");
        return;
    }

    int hour = orderDate.time().hour();
    if (hour < 8 || hour >= 20) {
        QMessageBox::warning(this, "Invalid Time", "Orders can only be placed between 08:00 and 20:00.");
        return;
    }

    if (userGreeting.isEmpty() || userGreeting.length() > 50) {
        QMessageBox::warning(this, "Invalid Greeting", "Please enter a valid greeting (1-50 characters).");
        return;
    }

    OrderDetails order(userEmail, address, phone, orderDate.toString("yyyy-MM-dd hh:mm:ss"), userGreeting);

    saveOrder(order);
}

void CustomerWindow::saveOrder(const OrderDetails &order) {
    if (!auth.isEmailExists(order.getUserEmail())) {
        QMessageBox::warning(this, "Error", "The provided email does not exist in the database.");
        qDebug() << "Email does not exist:" << order.getUserEmail();
        return;
    }

    DatabaseManager &dbManager = DatabaseManager::instance("database.db");

    if (!dbManager.saveCustomerOrder(order)) {
        QMessageBox::warning(this, "Error", "Failed to save the order. Please try again later.");
        qDebug() << "Order saving failed for email:" << order.getUserEmail();
        return;
    }

    QMessageBox::information(this, "Success", "Order has been placed successfully.");
}

void CustomerWindow::on_btnLoadOrders_clicked() {
    QString currentUserEmail = auth.getCurrentUserEmail();
    qDebug() << "Current user email: " << currentUserEmail;
    loadOrders(currentUserEmail);
}

void CustomerWindow::loadOrders(const QString &email) {
    ui->orderListWidget->clear();

    QVector<OrderDetails> orders;
    DatabaseManager &dbManager = DatabaseManager::instance("database.db");

    if (!dbManager.loadCustomerOrders(email, orders)) {
        QMessageBox::warning(this, "Error", "Failed to load orders. Please try again later.");
        qDebug() << "Failed to load orders for email:" << email;
        return;
    }

    if (orders.isEmpty()) {
        QMessageBox::information(this, "No Orders", "There are no orders for the given user in the database.");
    } else {
        for (const OrderDetails &order : orders) {
            QString orderInfo = QString(
                                    "User Email: %1\nAddress: %2\nPhone: %3\nOrder Date: %4\nStatus: %5\nUser Greeting: %6\n"
                                    "Inspector Email: %7\nWorker Email: %8")
                                    .arg(order.getUserEmail())
                                    .arg(order.getAddress())
                                    .arg(order.getPhone())
                                    .arg(order.getOrderDate())
                                    .arg(order.getStatus().isEmpty() ? "Pending" : order.getStatus())
                                    .arg(order.getUserGreeting())
                                    .arg(order.getInspectorEmail().isEmpty() ? "N/A" : order.getInspectorEmail())
                                    .arg(order.getWorkerEmail().isEmpty() ? "N/A" : order.getWorkerEmail());

            ui->orderListWidget->addItem(orderInfo);
        }
    }
}
