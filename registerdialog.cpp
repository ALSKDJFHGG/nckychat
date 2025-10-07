#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"

registerDialog::registerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerDialog)
{
    ui->setupUi(this);
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->repwdEdit->setEchoMode(QLineEdit::Password);
    ui->error_tip->setProperty("state", "normal");
    repolish(ui->error_tip);

    connect(ui->vaildButton, QPushButton::clicked, this, &registerDialog::on_vaildButton_clicked);
}

registerDialog::~registerDialog()
{
    delete ui;
}

void registerDialog::on_vaildButton_clicked()
{
    auto email_text = ui->emailEdit->text();
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (emailRegex.match(email_text).hasMatch()) {
        ui->error_tip->setText("");
        ui->error_tip->setProperty("state", "normal");
    }else {
        ui->error_tip->setText("邮箱格式错误");
        ui->error_tip->setProperty("state", "error");
    }
    repolish(ui->error_tip);
}

