#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <QMessageBox>
#include <QRegularExpression>

SignUpWindow::SignUpWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SignUpWindow),
    auth(parent)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow() {
    delete ui;
}

void SignUpWindow::on_registerButton_clicked() {

    QString firstName = ui->firstNameInput->text().trimmed();
    QString lastName = ui->lastNameInput->text().trimmed();
    QString email = ui->emailInput->text().trimmed();
    QString password = ui->passwordInput->text();
    QString confirmPassword = ui->confirmPasswordInput->text();

    QString userType;
    if (ui->radioButtonWorker->isChecked()) {
        userType = "Worker";
    } else if (ui->radioButtonInspector->isChecked()) {
        userType = "Inspector";
    } else if (ui->radioButtonCustomer->isChecked()) {
        userType = "Customer";
    } else {
        QMessageBox::warning(this, "Error", "Please select a user type!");
        return;
    }

    if (firstName.isEmpty() || firstName.length() < 2 || firstName.length() > 50) {
        QMessageBox::warning(this, "Error", "First name must be between 2 and 50 characters!");
        return;
    }

    if (lastName.isEmpty() || lastName.length() < 2 || lastName.length() > 50) {
        QMessageBox::warning(this, "Error", "Last name must be between 2 and 50 characters!");
        return;
    }

    QRegularExpression emailRegex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Error", "Please enter a valid email address!");
        return;
    }

    if (password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Error", "Password fields cannot be empty!");
        return;
    }
    if (password != confirmPassword) {
        QMessageBox::warning(this, "Error", "Passwords do not match!");
        return;
    }
    if (password.length() < 8) {
        QMessageBox::warning(this, "Error", "Password must be at least 8 characters long!");
        return;
    }
    QRegularExpression passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d).{8,}$");
    if (!passwordRegex.match(password).hasMatch()) {
        QMessageBox::warning(this, "Error", "Password must contain at least one uppercase letter, one lowercase letter, and one digit!");
        return;
    }

    if (auth.registerUser(firstName, lastName, email, password, userType)) {
        QMessageBox::information(this, "Success", "Registration successful!");
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Registration failed. Please try again.");
    }
}
