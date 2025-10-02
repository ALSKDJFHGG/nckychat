#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qss(":/style/qlwh.qss");
    if (qss.open(QFile::ReadOnly)){
        qDebug("open file success");
        QString style = QLatin1String(qss.readAll());
        a.setStyleSheet(style);
        qss.close();
    }else {
        qDebug("open file fail");
    }

    MainWindow w;
    w.show();
    return a.exec();
}
