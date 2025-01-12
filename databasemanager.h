#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "orderdetails.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QList>
#include <QString>
#include <QVector>

class DatabaseManager {
public:
    static DatabaseManager& instance(const QString& dbPath = "database.db");
    bool isConnected() const;
    QSqlDatabase getDatabase() const;

    bool createUsersTable();
    bool createCustomerOrdersTable();
    bool createInspectorOrdersTable();
    bool createWorkerOrdersTable();

    bool saveCustomerOrder(const OrderDetails &order);
    bool loadCustomerOrders(const QString &email, QVector<OrderDetails> &orders);

    bool loadOrdersForInspector(QList<OrderDetails>& ordersList);
    bool takeOrderForInspector(int orderId, const QString &inspectorEmail);
    bool updateOrderStatusForInspector(int orderId, const QString &status, const QString &inspectorEmail);
    bool saveDetailsForInspector(int customerOrderId, const QString &mediaLink, const QString &workDescription, const QString &requiredMaterials, const QString &inspectorEmail);
    bool loadInspectorOrdersForInspector(const QString &inspectorEmail, QVector<OrderDetails> &orders);
    bool loadCompletedOrdersForInspector(const QString &inspectorEmail, QVector<OrderDetails> &orders);

    bool loadAvaibleOrdersForWorkers(QList<OrderDetails>& ordersList);
    bool loadAcceptedOrdersForWorkers(const QString &workerEmail, QList<OrderDetails> &ordersList);
    bool acceptOrderForWorkers(int orderId, const QString &workerEmail);
    bool saveWorkDetailsForWorkers(int orderId, const QString& workDescription, const QString& mediaLink, const QString& workerEmail);
    bool getWorkDetailsForWorkers(int orderId, OrderDetails &order);
    bool loadCompletedOrdersForWorkers(const QString &workerEmail, QList<OrderDetails> &completedOrders);

    bool searchOrdersForInspector(const QString &searchText, QVector<OrderDetails> &orders);
    bool searchAvailableOrdersForWorker(const QString &searchText, QList<OrderDetails> &orders);

    ~DatabaseManager();

private:
    QSqlDatabase db;

    explicit DatabaseManager(const QString& dbPath);

    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;
};

#endif // DATABASEMANAGER_H
