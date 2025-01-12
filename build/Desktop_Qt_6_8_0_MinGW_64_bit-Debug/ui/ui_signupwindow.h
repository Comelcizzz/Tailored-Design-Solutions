/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QPushButton *registerButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *radioButtonWorker;
    QRadioButton *radioButtonCustomer;
    QLineEdit *firstNameInput;
    QLineEdit *confirmPasswordInput;
    QRadioButton *radioButtonInspector;
    QLineEdit *lastNameInput;
    QLineEdit *passwordInput;
    QLineEdit *emailInput;

    void setupUi(QDialog *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName("SignUpWindow");
        SignUpWindow->resize(578, 535);
        SignUpWindow->setModal(true);
        registerButton = new QPushButton(SignUpWindow);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(220, 320, 161, 51));
        gridLayoutWidget = new QWidget(SignUpWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(150, 80, 301, 232));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonWorker = new QRadioButton(gridLayoutWidget);
        radioButtonWorker->setObjectName("radioButtonWorker");

        gridLayout->addWidget(radioButtonWorker, 2, 1, 1, 1);

        radioButtonCustomer = new QRadioButton(gridLayoutWidget);
        radioButtonCustomer->setObjectName("radioButtonCustomer");

        gridLayout->addWidget(radioButtonCustomer, 4, 1, 1, 1);

        firstNameInput = new QLineEdit(gridLayoutWidget);
        firstNameInput->setObjectName("firstNameInput");

        gridLayout->addWidget(firstNameInput, 1, 0, 1, 1);

        confirmPasswordInput = new QLineEdit(gridLayoutWidget);
        confirmPasswordInput->setObjectName("confirmPasswordInput");

        gridLayout->addWidget(confirmPasswordInput, 5, 0, 1, 1);

        radioButtonInspector = new QRadioButton(gridLayoutWidget);
        radioButtonInspector->setObjectName("radioButtonInspector");

        gridLayout->addWidget(radioButtonInspector, 3, 1, 1, 1);

        lastNameInput = new QLineEdit(gridLayoutWidget);
        lastNameInput->setObjectName("lastNameInput");

        gridLayout->addWidget(lastNameInput, 2, 0, 1, 1);

        passwordInput = new QLineEdit(gridLayoutWidget);
        passwordInput->setObjectName("passwordInput");

        gridLayout->addWidget(passwordInput, 4, 0, 1, 1);

        emailInput = new QLineEdit(gridLayoutWidget);
        emailInput->setObjectName("emailInput");

        gridLayout->addWidget(emailInput, 3, 0, 1, 1);


        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QDialog *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "Sign Up", nullptr));
        SignUpWindow->setStyleSheet(QCoreApplication::translate("SignUpWindow", "\n"
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
"    QRadioButton {\n"
"        color: white;\n"
"    }\n"
"   ", nullptr));
        registerButton->setText(QCoreApplication::translate("SignUpWindow", "\320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\270", nullptr));
        radioButtonWorker->setText(QCoreApplication::translate("SignUpWindow", "\320\237\321\200\320\260\321\206\321\226\320\262\320\275\320\270\320\272", nullptr));
        radioButtonCustomer->setText(QCoreApplication::translate("SignUpWindow", "\320\227\320\260\320\274\320\276\320\262\320\275\320\270\320\272", nullptr));
        firstNameInput->setText(QCoreApplication::translate("SignUpWindow", "\320\206\320\274'\321\217", nullptr));
        confirmPasswordInput->setText(QCoreApplication::translate("SignUpWindow", "\320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\266\320\265\320\275\320\275\321\217 \320\277\320\260\321\200\320\276\320\273\321\216", nullptr));
        radioButtonInspector->setText(QCoreApplication::translate("SignUpWindow", "\320\224\320\270\320\267\320\260\320\271\320\275\320\265\321\200", nullptr));
        lastNameInput->setText(QCoreApplication::translate("SignUpWindow", "\320\244\320\260\320\274\321\226\320\273\321\226\321\217", nullptr));
        passwordInput->setText(QCoreApplication::translate("SignUpWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        emailInput->setText(QCoreApplication::translate("SignUpWindow", "\320\225\320\273\320\265\320\272\321\202\321\200\320\276\320\275\320\260 \320\260\320\264\321\200\320\265\321\201\321\201\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H
