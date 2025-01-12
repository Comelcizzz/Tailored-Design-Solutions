/********************************************************************************
** Form generated from reading UI file 'signinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINWINDOW_H
#define UI_SIGNINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *loginButton;
    QLineEdit *passwordInput;
    QLineEdit *emailInput;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *SignInWindow)
    {
        if (SignInWindow->objectName().isEmpty())
            SignInWindow->setObjectName("SignInWindow");
        SignInWindow->resize(539, 399);
        SignInWindow->setModal(true);
        gridLayoutWidget = new QWidget(SignInWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(190, 100, 201, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        loginButton = new QPushButton(gridLayoutWidget);
        loginButton->setObjectName("loginButton");

        gridLayout->addWidget(loginButton, 3, 0, 1, 1);

        passwordInput = new QLineEdit(gridLayoutWidget);
        passwordInput->setObjectName("passwordInput");
        passwordInput->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordInput, 1, 0, 1, 1);

        emailInput = new QLineEdit(gridLayoutWidget);
        emailInput->setObjectName("emailInput");

        gridLayout->addWidget(emailInput, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(SignInWindow);

        QMetaObject::connectSlotsByName(SignInWindow);
    } // setupUi

    void retranslateUi(QDialog *SignInWindow)
    {
        SignInWindow->setWindowTitle(QCoreApplication::translate("SignInWindow", "Sign In", nullptr));
        SignInWindow->setStyleSheet(QCoreApplication::translate("SignInWindow", "\n"
"    QDialog {\n"
"        background-color: #2E2E2E;\n"
"        color: white;\n"
"        font-family: Arial, sans-serif;\n"
"    }\n"
"    QLineEdit {\n"
"        background-color: #444444;\n"
"        color: white;\n"
"        border: 1px solid #666;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #4CAF50;\n"
"        color: white;\n"
"        padding: 12px 24px;\n"
"        border-radius: 5px;\n"
"        border: none;\n"
"        font-size: 14px;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #45a049;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #388E3C;\n"
"    }\n"
"   ", nullptr));
        loginButton->setText(QCoreApplication::translate("SignInWindow", "\320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\270", nullptr));
        passwordInput->setText(QCoreApplication::translate("SignInWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        emailInput->setText(QCoreApplication::translate("SignInWindow", "\320\225\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\260 \320\260\320\264\321\200\320\265\321\201\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInWindow: public Ui_SignInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINWINDOW_H
