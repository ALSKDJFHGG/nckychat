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

    connect(_loginDialog, &loginDialog::switchRegister, this, &MainWindow::SlotSwitchReg);
    _registerDialog = new registerDialog();
    // connect(_registerDialog, &registerDialog::backLogin, this, &MainWindow::SlotSwitchLog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SlotSwitchReg()
{
    setCentralWidget(_registerDialog);
    _loginDialog->hide();
    _registerDialog->show();
}



