#include "sqlconnect.h"

QSqlDatabase db;

SqlConnect::SqlConnect()
{

}

bool SqlConnect::openDatabase()
{
    QString serverName = "DESKTOP-8AJNFCB";
    QString dbName = "AttackGraph";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//连接到ODBC驱动
    QString dsn = QString("Driver={SQL Server};Server=%1;Database=%2;Trusted_Connection=yes").arg(serverName).arg(dbName);
    db.setDatabaseName(dsn);
    if(db.open())
    {
        printf("connect to server successfully\n");
        return true;
        //db.close();
    }
    else
    {
        printf("connect to server failed\n");
        printf("%s\n",db.lastError().text().toLatin1().data());
        return false;
    }


}

void SqlConnect::testDataBase()
{
    QSqlQuery query(db); //查询Card表并输出，测试能否正常操作数据库
    query.exec("select source, Destination, Protocol, count(*) as data_num from dbo.mondaym "
               "group by source, Destination, Protocol order by data_num desc");
    while(query.next())
    {
        //qDebug()<<query.value(0).toInt()<<endl;
        qDebug()<<query.value(0).toString()
               <<", "<<query.value(1).toString()
              <<", "<<query.value(2).toString()
             <<", "<<query.value(3).toString()<<endl;
    }
}
