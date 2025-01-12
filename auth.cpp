#include "auth.h"
#include "databasemanager.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

Auth::Auth(QWidget* parent) : QWidget(parent) {
    QString dbPath = "database.db";
    if (!DatabaseManager::instance().isConnected()) {
        qDebug() << "Database connection failed.";
        showError(DatabaseManager::instance().getDatabase().lastError());
    }
}

Auth::Auth(const Auth& other)
    : QWidget(other.parentWidget()),
      db(other.db),
      currentUserEmail(other.currentUserEmail)
{}

bool Auth::isEmailExists(const QString& email) {
    auto db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);

    query.prepare("SELECT COUNT(*) FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    qDebug() << "Error checking email existence:" << query.lastError().text();
    return false;
}

Auth::~Auth() {}

bool Auth::registerUser(const QString& firstName, const QString& lastName,
                        const QString& email, const QString& password,
                        const QString& userType) {
    auto db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);

    query.prepare("SELECT COUNT(*) FROM users WHERE email = :email");
    query.bindValue(":email", email);

    if (!query.exec() || !query.next() || query.value(0).toInt() > 0) {
        qDebug() << "Error: User with email" << email << "already exists or query failed.";
        return false;
    }

    query.prepare("INSERT INTO users (firstName, lastName, email, password, userType) "
                  "VALUES (:firstName, :lastName, :email, :password, :userType)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":email", email);
    query.bindValue(":password", password);
    query.bindValue(":userType", userType);

    if (!query.exec()) {
        qDebug() << "Error registering user:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Auth::loginUser(const QString& email, const QString& password) {
    auto db = DatabaseManager::instance().getDatabase();
    QSqlQuery query(db);

    query.prepare("SELECT * FROM users WHERE email = :email AND password = :password");
    query.bindValue(":email", email);
    query.bindValue(":password", password);

    if (query.exec() && query.next()) {
        currentUserEmail = email;
        qDebug() << "Login successful for user:" << email;
        return true;
    }

    qDebug() << "Login failed for user:" << email;
    return false;
}

void Auth::showError(const QSqlError& error) {
    qDebug() << "Database Error:" << error.text();

}

QString Auth::getCurrentUserEmail() const {
    return currentUserEmail;
}
