/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *signUp;
    QPushButton *exit;
    QPushButton *signIn;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(220, 80, 391, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        signUp = new QPushButton(gridLayoutWidget);
        signUp->setObjectName("signUp");

        gridLayout->addWidget(signUp, 2, 0, 1, 1);

        exit = new QPushButton(gridLayoutWidget);
        exit->setObjectName("exit");

        gridLayout->addWidget(exit, 5, 0, 1, 1);

        signIn = new QPushButton(gridLayoutWidget);
        signIn->setObjectName("signIn");

        gridLayout->addWidget(signIn, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        MainWindow->setStyleSheet(QCoreApplication::translate("MainWindow", "\n"
"    QMainWindow {\n"
"        background-color: #2E2E2E;\n"
"        color: white;\n"
"        font-family: Arial, sans-serif;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 12px 24px;\n"
"        border-radius: 5px;\n"
"        border: none;\n"
"        font-size: 14px;\n"
"        text-align: center;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #388E3C;\n"
"    }\n"
"    QMenuBar {\n"
"        background-color: #3C3F41;\n"
"        color: white;\n"
"    }\n"
"    QMenuBar::item {\n"
"        background-color: #3C3F41;\n"
"        color: white;\n"
"    }\n"
"    QMenuBar::item:selected {\n"
"        background-color: #4CAF50;\n"
"    }\n"
"    QStatusBar {\n"
"        background-color: #333;\n"
"        color: white;\n"
"    }\n"
"   ", nullptr));
        signUp->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\321\224\321\201\321\202\321\200\320\260\321\206\321\226\321\217", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\321\205\321\226\320\264", nullptr));
        signIn->setText(QCoreApplication::translate("MainWindow", "\320\222\321\205\321\226\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
