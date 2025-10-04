#include "registerdialog.h"
#include "ui_registerdialog.h"

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->repwdEdit->setEchoMode(QLineEdit::Password);
    //connect(ui->backButton, &QPushButton::clicked, this, &registerDialog::backLogin);
}

registerDialog::~registerDialog()
{
    delete ui;
}
