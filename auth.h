#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

class Auth : public QWidget {
    Q_OBJECT

public:
    explicit Auth(QWidget* parent = nullptr);

    Auth(const Auth&);

    ~Auth();

    bool isEmailExists(const QString& email);
    bool registerUser(const QString& firstName, const QString& lastName,
                      const QString& email, const QString& password,
                      const QString& userType);
    bool loginUser(const QString& email, const QString& password);
    QString getCurrentUserEmail() const;

private:
    QSqlDatabase db;
    QString currentUserEmail;

    void showError(const QSqlError& error);
};

#endif // AUTH_H
