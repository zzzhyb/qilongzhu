#include "mainwindow.h"
#include <QApplication>
#include "sqlconnect.h"
#include "attackgraph.h"
#include <QApplication>
#include <QFrame>
#include <QCoreApplication>
#include <QtSql/QtSql>
#include "painter.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //连接数据库
    SqlConnect sqlConnect = SqlConnect();
    if(!sqlConnect.openDatabase()){
        return a.exec();
    }

           w.show();
    return a.exec();
}
