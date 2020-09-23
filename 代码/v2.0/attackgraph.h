#ifndef ATTACKGRAPH_H
#define ATTACKGRAPH_H
#include "node.h"
#include "sqlconnect.h"
#include <QtGui>
#include <QString>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QtSql>
#include <QMessageBox>
using namespace std;

class AttackGraph
{
public:
    AttackGraph();
    bool initGraph();
    int addNode(QString nodestr);
    void addArc(int src, int dst, QString prostr, int num);
    void addNodePosition(int src);

//private:
    int nodeCount;
    QVector<Node> nodeList;

};

#endif // ATTACKGRAPH_H
