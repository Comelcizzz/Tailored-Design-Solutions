/********************************************************************************
** Form generated from reading UI file 'customerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERWINDOW_H
#define UI_CUSTOMERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *TabCreateOrder;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDateTimeEdit *dateTimeEdit;
    QVBoxLayout *verticalLayout;
    QLineEdit *leUserGreeting;
    QLineEdit *lePhone;
    QLineEdit *leAddress;
    QPushButton *btnCreate;
    QWidget *TabOrderHistory;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnLoadOrders;
    QListWidget *orderListWidget;

    void setupUi(QDialog *CustomerWindow)
    {
        if (CustomerWindow->objectName().isEmpty())
            CustomerWindow->setObjectName("CustomerWindow");
        CustomerWindow->resize(860, 540);
        CustomerWindow->setModal(true);
        tabWidget = new QTabWidget(CustomerWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 860, 540));
        TabCreateOrder = new QWidget();
        TabCreateOrder->setObjectName("TabCreateOrder");
        gridLayoutWidget = new QWidget(TabCreateOrder);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(70, 70, 631, 271));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        dateTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        dateTimeEdit->setObjectName("dateTimeEdit");

        gridLayout->addWidget(dateTimeEdit, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        leUserGreeting = new QLineEdit(gridLayoutWidget);
        leUserGreeting->setObjectName("leUserGreeting");

        verticalLayout->addWidget(leUserGreeting);

        lePhone = new QLineEdit(gridLayoutWidget);
        lePhone->setObjectName("lePhone");

        verticalLayout->addWidget(lePhone);

        leAddress = new QLineEdit(gridLayoutWidget);
        leAddress->setObjectName("leAddress");

        verticalLayout->addWidget(leAddress);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        btnCreate = new QPushButton(gridLayoutWidget);
        btnCreate->setObjectName("btnCreate");

        gridLayout->addWidget(btnCreate, 1, 0, 1, 2);

        tabWidget->addTab(TabCreateOrder, QString());
        TabOrderHistory = new QWidget();
        TabOrderHistory->setObjectName("TabOrderHistory");
        gridLayoutWidget_2 = new QWidget(TabOrderHistory);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(60, 50, 541, 391));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnLoadOrders = new QPushButton(gridLayoutWidget_2);
        btnLoadOrders->setObjectName("btnLoadOrders");

        gridLayout_2->addWidget(btnLoadOrders, 1, 0, 1, 1);

        orderListWidget = new QListWidget(gridLayoutWidget_2);
        orderListWidget->setObjectName("orderListWidget");

        gridLayout_2->addWidget(orderListWidget, 0, 0, 1, 1);

        tabWidget->addTab(TabOrderHistory, QString());

        retranslateUi(CustomerWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CustomerWindow);
    } // setupUi

    void retranslateUi(QDialog *CustomerWindow)
    {
        CustomerWindow->setWindowTitle(QCoreApplication::translate("CustomerWindow", "Customer Window", nullptr));
        CustomerWindow->setStyleSheet(QCoreApplication::translate("CustomerWindow", "\n"
"    QWidget {\n"
"        background-color: #2E2E2E;\n"
"        color: white;\n"
"        font-family: Arial, sans-serif;\n"
"    }\n"
"    QLineEdit, QDateTimeEdit {\n"
"        border: 1px solid #555;\n"
"        border-radius: 5px;\n"
"        padding: 5px;\n"
"        background-color: #333;\n"
"        color: white;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 10px;\n"
"        border-radius: 5px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"    QTabWidget {\n"
"        background-color: #3C3F41;\n"
"        color: white;\n"
"    }\n"
"    QTabBar::tab {\n"
"        background-color: #3C3F41;\n"
"        border: 1px solid #555;\n"
"        padding: 5px;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"        background-color: #4CAF50;\n"
"        border: 1px solid #4CAF50;\n"
"    }\n"
"    QListWidget {\n"
"        background-color: #333;\n"
"        color: white;\n"
"        border:"
                        " 1px solid #555;\n"
"    }\n"
"    QListWidget::item:selected {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"    }\n"
"   ", nullptr));
        leUserGreeting->setText(QCoreApplication::translate("CustomerWindow", "\320\257\320\272 \320\264\320\276 \320\262\320\260\321\201 \320\267\320\262\320\265\321\200\321\202\320\260\321\202\320\270\321\201\321\214?", nullptr));
        lePhone->setText(QCoreApplication::translate("CustomerWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\321\203", nullptr));
        leAddress->setText(QCoreApplication::translate("CustomerWindow", "\320\220\320\264\321\200\320\265\321\201\321\201\320\260 \320\276\320\261'\321\224\320\272\321\202\321\203", nullptr));
        btnCreate->setText(QCoreApplication::translate("CustomerWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabCreateOrder), QCoreApplication::translate("CustomerWindow", "Create Order", nullptr));
        btnLoadOrders->setText(QCoreApplication::translate("CustomerWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabOrderHistory), QCoreApplication::translate("CustomerWindow", "Order History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerWindow: public Ui_CustomerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERWINDOW_H
