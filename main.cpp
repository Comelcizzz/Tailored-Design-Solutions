#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QIcon>
#include "databasemanager.h"

void initializeDatabase(const QString& dbPath) {
    DatabaseManager& dbManager = DatabaseManager::instance(dbPath);

    if (!dbManager.isConnected()) {
        qDebug() << "Database connection failed!";
        return;
    }

    if (dbManager.createUsersTable()) {
        qDebug() << "Users table initialized successfully.";
    } else {
        qDebug() << "Failed to initialize 'users' table.";
    }

    if (dbManager.createCustomerOrdersTable()) {
        qDebug() << "Customer orders table initialized successfully.";
    } else {
        qDebug() << "Failed to initialize 'customerorder' table.";
    }

    if (dbManager.createInspectorOrdersTable()) {
        qDebug() << "Inspector orders table initialized successfully.";
    } else {
        qDebug() << "Failed to initialize 'inspectororders' table.";
    }

    if (dbManager.createWorkerOrdersTable()) {
        qDebug() << "Worker orders table initialized successfully.";
    } else {
        qDebug() << "Failed to initialize 'workerorders' table.";
    }
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Auth auth;
    initializeDatabase("database.db");
    MainWindow w;
    w.show();
    return a.exec();
}
