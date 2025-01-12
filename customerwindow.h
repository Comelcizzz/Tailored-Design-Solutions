#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QDialog>
#include <QSqlDatabase>
#include "databasemanager.h"
#include "auth.h"

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QDialog
{
    Q_OBJECT

public:
     explicit CustomerWindow(Auth& auth, QDialog *parent = nullptr);
    ~CustomerWindow();

private slots:
    void on_btnCreate_clicked();
    void on_btnLoadOrders_clicked();

private:
    Ui::CustomerWindow *ui;
    QSqlDatabase db;
    Auth auth;

    bool createDatabaseConnection(const QString &dbPath);
    void saveOrder(const OrderDetails &order);
    void loadOrders(const QString &email);
};

#endif // CUSTOMERWINDOW_H
