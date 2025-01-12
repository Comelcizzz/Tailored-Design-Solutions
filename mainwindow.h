#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signupwindow.h"
#include "signinwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_signUp_clicked();
    void on_signIn_clicked();
    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    SignUpWindow *signUpWindow;
    SignInWindow *signInWindow;
};

#endif // MAINWINDOW_H
