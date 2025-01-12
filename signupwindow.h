#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QWidget>
#include "auth.h"

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog {
    Q_OBJECT

public:
    explicit SignUpWindow(QDialog *parent = nullptr);
    ~SignUpWindow();

private slots:
    void on_registerButton_clicked();

private:
    Ui::SignUpWindow *ui;
    Auth auth;
};

#endif // SIGNUPWINDOW_H
