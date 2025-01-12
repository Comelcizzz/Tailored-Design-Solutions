#include "signinwindow.h"
#include "ui_signinwindow.h"
#include "workerwindow.h"
#include "customerwindow.h"
#include "inspectorwindow.h"
#include "databasemanager.h"

SignInWindow::SignInWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SignInWindow),
    auth(parent)
{
    ui->setupUi(this);
    setWindowTitle("Sign In");

    DatabaseManager& dbManager = DatabaseManager::instance("database.db");

    if (!dbManager.isConnected()) {
        showError("Failed to connect to the database.");
    }
}

SignInWindow::~SignInWindow() {
    delete ui;
}

void SignInWindow::on_loginButton_clicked() {
    Auth auth;

    QString email = ui->emailInput->text();
    QString password = ui->passwordInput->text();

    qDebug() << "Attempting to log in with email:" << email;

    if (auth.loginUser(email, password)) {
        QSqlQuery query;
        query.prepare("SELECT userType FROM users WHERE email = :email");
        query.bindValue(":email", email);

        if (query.exec() && query.next()) {
            QString userType = query.value(0).toString();
            qDebug() << "User type:" << userType;

            this->accept();

            if (userType == "Worker") {
                WorkerWindow *workerWindow = new WorkerWindow(auth);
                workerWindow->show();
            } else if (userType == "Customer") {
                CustomerWindow *customerWindow = new CustomerWindow(auth);
                customerWindow->show();
            } else if (userType == "Inspector") {
                InspectorWindow *inspectorWindow = new InspectorWindow(auth);
                inspectorWindow->show();
            } else {
                QMessageBox::warning(this, "Error", "Unknown user type.");
            }
        } else {
            QMessageBox::warning(this, "Error", "Failed to retrieve user type.");
        }
    } else {
        qDebug() << "Login failed for user:" << email;
        QMessageBox::warning(this, "Error", "Invalid email or password.");
    }
}

void SignInWindow::showError(const QString &message)
{
    qDebug() << "Error:" << message;
    QMessageBox::warning(this, "Error", message);
}
