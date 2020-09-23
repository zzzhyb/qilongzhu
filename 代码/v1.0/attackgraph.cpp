#include "attackgraph.h"
#include "time.h"
AttackGraph::AttackGraph()
{
    nodeCount = 0;
    initGraph();
}

bool AttackGraph::initGraph()
{
    QSqlQuery query(db);
    QString qstr = "select source, Destination, Protocol, count(*) as data_num "
                   "from dbo.mondaym "
                   "group by source, Destination, Protocol "
                   "order by data_num desc";
    if(!query.exec(qstr)){
        qDebug()<<"数据库查询失败01"<<endl;
        return false;
    }
    QString srcstr, dststr, prostr;
    int num;
    while(query.next()){
        srcstr = query.value(0).toString();
        dststr = query.value(1).toString();
        prostr = query.value(2).toString();
        num = query.value(3).toInt();

        //qDebug()<<srcstr<<","<<dststr<<","<<prostr<<","<<num<<endl;

        int srcid = addNode(srcstr);
        int dstid = addNode(dststr);

        //qDebug()<<srcid<<","<<dstid<<endl;

        addArc(srcid, dstid, prostr, num);
        addNodePosition(srcid);

    }

    return true;
}

int AttackGraph::addNode(QString nodestr)
{
    //如果可以找到节点，直接输出id
    QVector<Node>::iterator it;
    for(it = nodeList.begin(); it < nodeList.end(); it++){
        if(it->getHostid() == nodestr){
            return it->getId();
        }
    }

    //如果找不到节点，添加该节点并输出id
    Node n = Node(++nodeCount, nodestr);
    nodeList.append(n);
    return nodeCount;
}

void AttackGraph::addNodePosition(int src)
{
   //srand(time(nullptr));
   nodeList[src-1].SetPosX(rand()%2000);
   nodeList[src-1].SetPosY(rand()%700);
}

void AttackGraph::addArc(int src, int dst, QString prostr, int num)
{
    nodeList[src-1].addArc(dst, prostr, num);
    return;
}

