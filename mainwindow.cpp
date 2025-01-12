#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , signUpWindow(nullptr)
    , signInWindow(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("Welcome to Tailored Design Solutions");
}

MainWindow::~MainWindow()
{
    delete ui;
    if (signUpWindow) delete signUpWindow;
    if (signInWindow) delete signInWindow;
}

void MainWindow::on_signUp_clicked()
{
    if (!signUpWindow) {
        signUpWindow = new SignUpWindow();
    }
    signUpWindow->exec();
}

void MainWindow::on_signIn_clicked()
{
    if (!signInWindow) {
        signInWindow = new SignInWindow();
    }
    signInWindow->exec();
}

void MainWindow::on_exit_clicked()
{
    close();
}
