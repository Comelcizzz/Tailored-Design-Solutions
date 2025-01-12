/********************************************************************************
** Form generated from reading UI file 'inspectorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSPECTORWINDOW_H
#define UI_INSPECTORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InspectorWindow
{
public:
    QTabWidget *tabWidget;
    QWidget *TabOrders;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *btnTakeOrder;
    QPushButton *btnLoadOrders;
    QListWidget *ordersListWidget;
    QPushButton *btnDeleteOrder;
    QWidget *TabWorkDetails;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListWidget *lwOrders;
    QLineEdit *leOrderId;
    QTextEdit *teWorkDescription;
    QTextEdit *teRequiredMaterials;
    QPushButton *btnSaveDetails;
    QPushButton *btnLoadOrdersInProgress;
    QLineEdit *leMediaLink;
    QSpacerItem *verticalSpacer;
    QWidget *TabDoneOrders;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QListWidget *lwCompletedOrders;
    QPushButton *btnSearchInspector;
    QPushButton *btnLoadCompletedOrders;
    QLineEdit *leSearch;

    void setupUi(QDialog *InspectorWindow)
    {
        if (InspectorWindow->objectName().isEmpty())
            InspectorWindow->setObjectName("InspectorWindow");
        InspectorWindow->resize(800, 600);
        InspectorWindow->setModal(true);
        tabWidget = new QTabWidget(InspectorWindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 800, 600));
        TabOrders = new QWidget();
        TabOrders->setObjectName("TabOrders");
        gridLayoutWidget_2 = new QWidget(TabOrders);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(150, 50, 541, 431));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnTakeOrder = new QPushButton(gridLayoutWidget_2);
        btnTakeOrder->setObjectName("btnTakeOrder");

        gridLayout_2->addWidget(btnTakeOrder, 4, 0, 1, 1);

        btnLoadOrders = new QPushButton(gridLayoutWidget_2);
        btnLoadOrders->setObjectName("btnLoadOrders");

        gridLayout_2->addWidget(btnLoadOrders, 2, 0, 1, 1);

        ordersListWidget = new QListWidget(gridLayoutWidget_2);
        ordersListWidget->setObjectName("ordersListWidget");

        gridLayout_2->addWidget(ordersListWidget, 1, 0, 1, 1);

        btnDeleteOrder = new QPushButton(gridLayoutWidget_2);
        btnDeleteOrder->setObjectName("btnDeleteOrder");

        gridLayout_2->addWidget(btnDeleteOrder, 5, 0, 1, 1);

        tabWidget->addTab(TabOrders, QString());
        TabWorkDetails = new QWidget();
        TabWorkDetails->setObjectName("TabWorkDetails");
        gridLayoutWidget = new QWidget(TabWorkDetails);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(110, 20, 641, 531));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lwOrders = new QListWidget(gridLayoutWidget);
        lwOrders->setObjectName("lwOrders");

        gridLayout->addWidget(lwOrders, 0, 0, 1, 1);

        leOrderId = new QLineEdit(gridLayoutWidget);
        leOrderId->setObjectName("leOrderId");

        gridLayout->addWidget(leOrderId, 3, 0, 1, 1);

        teWorkDescription = new QTextEdit(gridLayoutWidget);
        teWorkDescription->setObjectName("teWorkDescription");

        gridLayout->addWidget(teWorkDescription, 5, 0, 1, 1);

        teRequiredMaterials = new QTextEdit(gridLayoutWidget);
        teRequiredMaterials->setObjectName("teRequiredMaterials");

        gridLayout->addWidget(teRequiredMaterials, 7, 0, 1, 1);

        btnSaveDetails = new QPushButton(gridLayoutWidget);
        btnSaveDetails->setObjectName("btnSaveDetails");

        gridLayout->addWidget(btnSaveDetails, 9, 0, 1, 1);

        btnLoadOrdersInProgress = new QPushButton(gridLayoutWidget);
        btnLoadOrdersInProgress->setObjectName("btnLoadOrdersInProgress");

        gridLayout->addWidget(btnLoadOrdersInProgress, 1, 0, 1, 1);

        leMediaLink = new QLineEdit(gridLayoutWidget);
        leMediaLink->setObjectName("leMediaLink");

        gridLayout->addWidget(leMediaLink, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        tabWidget->addTab(TabWorkDetails, QString());
        TabDoneOrders = new QWidget();
        TabDoneOrders->setObjectName("TabDoneOrders");
        gridLayoutWidget_3 = new QWidget(TabDoneOrders);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(90, 70, 541, 411));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lwCompletedOrders = new QListWidget(gridLayoutWidget_3);
        lwCompletedOrders->setObjectName("lwCompletedOrders");

        gridLayout_3->addWidget(lwCompletedOrders, 0, 0, 1, 1);

        btnSearchInspector = new QPushButton(gridLayoutWidget_3);
        btnSearchInspector->setObjectName("btnSearchInspector");

        gridLayout_3->addWidget(btnSearchInspector, 3, 0, 1, 1);

        btnLoadCompletedOrders = new QPushButton(gridLayoutWidget_3);
        btnLoadCompletedOrders->setObjectName("btnLoadCompletedOrders");

        gridLayout_3->addWidget(btnLoadCompletedOrders, 1, 0, 1, 1);

        leSearch = new QLineEdit(gridLayoutWidget_3);
        leSearch->setObjectName("leSearch");

        gridLayout_3->addWidget(leSearch, 2, 0, 1, 1);

        tabWidget->addTab(TabDoneOrders, QString());

        retranslateUi(InspectorWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(InspectorWindow);
    } // setupUi

    void retranslateUi(QDialog *InspectorWindow)
    {
        InspectorWindow->setWindowTitle(QCoreApplication::translate("InspectorWindow", "Inspector Window", nullptr));
        InspectorWindow->setStyleSheet(QCoreApplication::translate("InspectorWindow", "\n"
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
        btnTakeOrder->setText(QCoreApplication::translate("InspectorWindow", "\320\222\320\267\321\217\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        btnLoadOrders->setText(QCoreApplication::translate("InspectorWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        btnDeleteOrder->setText(QCoreApplication::translate("InspectorWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabOrders), QCoreApplication::translate("InspectorWindow", "Orders", nullptr));
        leOrderId->setText(QCoreApplication::translate("InspectorWindow", "ID \320\267\320\260\320\274\320\276\320\262\320\273\320\265\320\275\320\275\321\217", nullptr));
        leOrderId->setPlaceholderText(QCoreApplication::translate("InspectorWindow", "Order ID", nullptr));
        teWorkDescription->setHtml(QCoreApplication::translate("InspectorWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\236\320\277\320\270\321\201 \321\200\320\276\320\261\320\276\321\202\320\270</p></body></html>", nullptr));
        teWorkDescription->setPlaceholderText(QCoreApplication::translate("InspectorWindow", "Work Description", nullptr));
        teRequiredMaterials->setHtml(QCoreApplication::translate("InspectorWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Arial','sans-serif'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\237\320\276\321\202\321\200\321\226\320\261\320\275\321\226 \320\274\320\260\321\202\320\265\321\200\321\226\320\260\320\273\320\270</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        teRequiredMaterials->setPlaceholderText(QCoreApplication::translate("InspectorWindow", "Required Materials", nullptr));
        btnSaveDetails->setText(QCoreApplication::translate("InspectorWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\264\320\265\321\202\320\260\320\273\321\226", nullptr));
        btnLoadOrdersInProgress->setText(QCoreApplication::translate("InspectorWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\320\270 \320\264\320\260\320\275\321\226123", nullptr));
        leMediaLink->setText(QCoreApplication::translate("InspectorWindow", "\320\237\320\276\321\201\320\270\320\273\320\260\320\275\320\275\321\217 \320\275\320\260 \320\274\320\265\320\264\321\226\320\260\320\262\320\274\321\226\321\201\321\202", nullptr));
        leMediaLink->setPlaceholderText(QCoreApplication::translate("InspectorWindow", "Media Link", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabWorkDetails), QCoreApplication::translate("InspectorWindow", "Work Details", nullptr));
        btnSearchInspector->setText(QCoreApplication::translate("InspectorWindow", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        btnLoadCompletedOrders->setText(QCoreApplication::translate("InspectorWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\320\270 \320\267\320\260\320\262\320\265\321\200\321\210\320\265\320\275\321\226 \321\200\320\276\320\261\320\276\321\202\320\270", nullptr));
        leSearch->setText(QCoreApplication::translate("InspectorWindow", "\320\222\320\262\320\265\320\264\321\226\321\202\321\214 \320\264\320\260\320\275\321\226 \320\264\320\273\321\217 \320\277\320\276\321\210\321\203\320\272\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(TabDoneOrders), QCoreApplication::translate("InspectorWindow", "Done Orders", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InspectorWindow: public Ui_InspectorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSPECTORWINDOW_H
