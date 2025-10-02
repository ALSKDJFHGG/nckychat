#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _loginDialog = new loginDialog();
    setCentralWidget(_loginDialog);
    _loginDialog->show();
    _registerDialog = new registerDialog();
    connect(_loginDialog, &loginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    connect(_registerDialog, &registerDialog::backLogin, this, &MainWindow::SlotSwitchLog);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (_loginDialog) {
        delete _loginDialog;
        _loginDialog = nullptr;
    }
    if (_registerDialog) {
        delete _registerDialog;
        _registerDialog = nullptr;
    }
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_registerDialog);
    _loginDialog->hide();
    _registerDialog->show();
}

void MainWindow::SlotSwitchLog()
{
    setCentralWidget(_loginDialog);
    _registerDialog->hide();
    _loginDialog->show();
}

