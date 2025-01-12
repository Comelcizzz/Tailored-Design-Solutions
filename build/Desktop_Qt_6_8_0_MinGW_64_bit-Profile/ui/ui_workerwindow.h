/********************************************************************************
** Form generated from reading UI file 'workerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERWINDOW_H
#define UI_WORKERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkerWindow
{
public:
    QTabWidget *WorkerTabs;
    QWidget *TabOrders;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnLoadOrders;
    QPushButton *btnTakeOrder;
    QListWidget *ordersListWidget;
    QWidget *TabWorkDetails;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *leMediaLink;
    QLineEdit *leOrderId;
    QTextEdit *teWorkDescription;
    QListWidget *acceptedOrdersListWidget;
    QPushButton *btnLoadActiveOrders;
    QPushButton *btnSaveDetails;
    QWidget *TabDoneOrders;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnLoadCompletedOrders;
    QListWidget *completedOrdersListWidget;
    QPushButton *btnSearchOrders;
    QLineEdit *leSearchWorker;

    void setupUi(QDialog *WorkerWindow)
    {
        if (WorkerWindow->objectName().isEmpty())
            WorkerWindow->setObjectName("WorkerWindow");
        WorkerWindow->resize(800, 600);
        WorkerWindow->setModal(true);
        WorkerTabs = new QTabWidget(WorkerWindow);
        WorkerTabs->setObjectName("WorkerTabs");
        WorkerTabs->setGeometry(QRect(0, 0, 800, 600));
        TabOrders = new QWidget();
        TabOrders->setObjectName("TabOrders");
        gridLayoutWidget = new QWidget(TabOrders);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(60, 50, 711, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnLoadOrders = new QPushButton(gridLayoutWidget);
        btnLoadOrders->setObjectName("btnLoadOrders");

        gridLayout->addWidget(btnLoadOrders, 2, 0, 1, 1);

        btnTakeOrder = new QPushButton(gridLayoutWidget);
        btnTakeOrder->setObjectName("btnTakeOrder");

        gridLayout->addWidget(btnTakeOrder, 3, 0, 1, 1);

        ordersListWidget = new QListWidget(gridLayoutWidget);
        ordersListWidget->setObjectName("ordersListWidget");

        gridLayout->addWidget(ordersListWidget, 1, 0, 1, 1);

        WorkerTabs->addTab(TabOrders, QString());
        TabWorkDetails = new QWidget();
        TabWorkDetails->setObjectName("TabWorkDetails");
        gridLayoutWidget_2 = new QWidget(TabWorkDetails);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(60, 70, 681, 401));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        leMediaLink = new QLineEdit(gridLayoutWidget_2);
        leMediaLink->setObjectName("leMediaLink");

        gridLayout_2->addWidget(leMediaLink, 3, 0, 1, 1);

        leOrderId = new QLineEdit(gridLayoutWidget_2);
        leOrderId->setObjectName("leOrderId");

        gridLayout_2->addWidget(leOrderId, 2, 0, 1, 1);

        teWorkDescription = new QTextEdit(gridLayoutWidget_2);
        teWorkDescription->setObjectName("teWorkDescription");

        gridLayout_2->addWidget(teWorkDescription, 4, 0, 1, 1);

        acceptedOrdersListWidget = new QListWidget(gridLayoutWidget_2);
        acceptedOrdersListWidget->setObjectName("acceptedOrdersListWidget");

        gridLayout_2->addWidget(acceptedOrdersListWidget, 0, 0, 1, 1);

        btnLoadActiveOrders = new QPushButton(gridLayoutWidget_2);
        btnLoadActiveOrders->setObjectName("btnLoadActiveOrders");

        gridLayout_2->addWidget(btnLoadActiveOrders, 1, 0, 1, 1);

        btnSaveDetails = new QPushButton(gridLayoutWidget_2);
        btnSaveDetails->setObjectName("btnSaveDetails");

        gridLayout_2->addWidget(btnSaveDetails, 5, 0, 1, 1);

        WorkerTabs->addTab(TabWorkDetails, QString());
        TabDoneOrders = new QWidget();
        TabDoneOrders->setObjectName("TabDoneOrders");
        gridLayoutWidget_3 = new QWidget(TabDoneOrders);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(100, 80, 621, 381));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        btnLoadCompletedOrders = new QPushButton(gridLayoutWidget_3);
        btnLoadCompletedOrders->setObjectName("btnLoadCompletedOrders");

        gridLayout_3->addWidget(btnLoadCompletedOrders, 1, 0, 1, 1);

        completedOrdersListWidget = new QListWidget(gridLayoutWidget_3);
        completedOrdersListWidget->setObjectName("completedOrdersListWidget");

        gridLayout_3->addWidget(completedOrdersListWidget, 0, 0, 1, 1);

        btnSearchOrders = new QPushButton(gridLayoutWidget_3);
        btnSearchOrders->setObjectName("btnSearchOrders");

        gridLayout_3->addWidget(btnSearchOrders, 3, 0, 1, 1);

        leSearchWorker = new QLineEdit(gridLayoutWidget_3);
        leSearchWorker->setObjectName("leSearchWorker");

        gridLayout_3->addWidget(leSearchWorker, 2, 0, 1, 1);

        WorkerTabs->addTab(TabDoneOrders, QString());

        retranslateUi(WorkerWindow);

        WorkerTabs->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(WorkerWindow);
    } // setupUi

    void retranslateUi(QDialog *WorkerWindow)
    {
        WorkerWindow->setWindowTitle(QCoreApplication::translate("WorkerWindow", "Worker Window", nullptr));
        WorkerWindow->setStyleSheet(QCoreApplication::translate("WorkerWindow", "\n"
"    QWidget {\n"
"        background-color: #2E2E2E;\n"
"        font-family: Arial, sans-serif;\n"
"        font-size: 12pt;\n"
"        color: white;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 10px;\n"
"        border-radius: 5px;\n"
"        border: none;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"    QLineEdit, QTextEdit {\n"
"        border: 1px solid #555;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        font-size: 12pt;\n"
"        background-color: #333;\n"
"        color: white;\n"
"    }\n"
"    QTabWidget {\n"
"        background-color: #3C3F41;\n"
"        border: 1px solid #555;\n"
"        color: white;\n"
"    }\n"
"    QTabBar::tab {\n"
"        background-color: #3C3F41;\n"
"        border: 1px solid #555;\n"
"        padding: 5px;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"        background-color: #4CAF50;\n"
"   "
                        "     border: 1px solid #4CAF50;\n"
"    }\n"
"    QListWidget {\n"
"        background-color: #333;\n"
"        color: white;\n"
"        border: 1px solid #555;\n"
"    }\n"
"    QListWidget::item:selected {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"    }\n"
"   ", nullptr));
        btnLoadOrders->setText(QCoreApplication::translate("WorkerWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        btnTakeOrder->setText(QCoreApplication::translate("WorkerWindow", "\320\222\320\267\321\217\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        WorkerTabs->setTabText(WorkerTabs->indexOf(TabOrders), QCoreApplication::translate("WorkerWindow", "Orders", nullptr));
        leMediaLink->setText(QCoreApplication::translate("WorkerWindow", "\320\237\320\276\321\201\320\270\320\273\320\260\320\275\320\275\321\217 \320\275\320\260 \320\274\320\265\320\264\321\226\320\260\320\264\320\260\320\275\321\226", nullptr));
        leMediaLink->setPlaceholderText(QCoreApplication::translate("WorkerWindow", "Media Link", nullptr));
        leOrderId->setText(QCoreApplication::translate("WorkerWindow", "ID \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        leOrderId->setPlaceholderText(QCoreApplication::translate("WorkerWindow", "Order ID", nullptr));
        teWorkDescription->setHtml(QCoreApplication::translate("WorkerWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\320\277\320\270\321\201 \320\262\320\270\320\272\320\276\320\275\320\260\320\275\320\276\321\227 \321\200\320\276\320\261\320\276\321\202\320\270</p></body></html>", nullptr));
        teWorkDescription->setPlaceholderText(QCoreApplication::translate("WorkerWindow", "Work Description", nullptr));
        btnLoadActiveOrders->setText(QCoreApplication::translate("WorkerWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        btnSaveDetails->setText(QCoreApplication::translate("WorkerWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\264\320\265\321\202\320\260\320\273\321\226", nullptr));
        WorkerTabs->setTabText(WorkerTabs->indexOf(TabWorkDetails), QCoreApplication::translate("WorkerWindow", "Work Details", nullptr));
        btnLoadCompletedOrders->setText(QCoreApplication::translate("WorkerWindow", "\320\222\321\201\321\226 \320\262\320\270\320\272\320\276\320\275\320\260\320\275\321\226 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        btnSearchOrders->setText(QCoreApplication::translate("WorkerWindow", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        leSearchWorker->setText(QCoreApplication::translate("WorkerWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\264\320\260\320\275\321\226 \320\264\320\273\321\217 \320\277\320\276\321\210\321\203\320\272\321\203", nullptr));
        WorkerTabs->setTabText(WorkerTabs->indexOf(TabDoneOrders), QCoreApplication::translate("WorkerWindow", "Done Orders", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkerWindow: public Ui_WorkerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERWINDOW_H
