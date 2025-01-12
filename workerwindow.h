#ifndef WORKERWINDOW_H
#define WORKERWINDOW_H

#include <QDialog>
#include "auth.h"

namespace Ui {
class WorkerWindow;
}

class WorkerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerWindow(Auth& auth, QDialog *parent = nullptr);
    ~WorkerWindow();

private slots:
    void loadAvailableOrders();
    void loadAcceptedOrders();
    void acceptOrder();
    void saveWorkDetails();
    void viewOrderDetails();
    void loadCompletedOrders();

    void on_btnLoadCompletedOrders_clicked();

    void on_btnLoadActiveOrders_clicked();

    void on_btnSaveDetails_clicked();

    void on_btnLoadOrders_clicked();

    void on_btnSearchOrders_clicked();

private:
    Ui::WorkerWindow *ui;
    Auth auth;
};

#endif // WORKERWINDOW_H
