#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QWidget>
#include "auth.h"
#include "inspectorwindow.h"
#include "customerwindow.h"
#include "workerwindow.h"

namespace Ui {
class SignInWindow;
}

class SignInWindow : public QDialog {
    Q_OBJECT

public:
    explicit SignInWindow(QDialog *parent = nullptr);
    ~SignInWindow();
    void showError(const QString &message);

private slots:
    void on_loginButton_clicked();

private:
    Ui::SignInWindow *ui;
    Auth auth;
};

#endif // SIGNINWINDOW_H
