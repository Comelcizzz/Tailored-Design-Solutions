#ifndef INSPECTORWINDOW_H
#define INSPECTORWINDOW_H

#include <QDialog>
#include "auth.h"

namespace Ui {
class InspectorWindow;
}

class InspectorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InspectorWindow(Auth& auth, QDialog *parent = nullptr);
    ~InspectorWindow();

private slots:
    void loadOrders();
    void on_btnTakeOrder_clicked();
    void on_btnSaveDetails_clicked();
    void loadInspectorOrders();
    void on_btnLoadOrdersInProgress_clicked();
    void on_btnLoadOrders_clicked();
    void loadCompletedOrders();
    void loadSearchResults(const QString &searchText);
    void updateOrderStatus(int orderId, const QString& status);

    void on_btnSearchInspector_clicked();

    void on_btnDeleteOrder_clicked();

    void on_btnLoadCompletedOrders_clicked();

private:
    Ui::InspectorWindow *ui;
    Auth auth;
};

#endif // INSPECTORWINDOW_H
