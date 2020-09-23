#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include <QtGui>
#include <QString>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
using namespace std;

extern QSqlDatabase db;

class SqlConnect
{
public:
    SqlConnect();
    bool openDatabase();
    void testDataBase();
    QSqlDatabase getDatabase();



};

#endif // SQLCONNECT_H
