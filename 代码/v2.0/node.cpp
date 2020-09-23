#include "node.h"

Node::Node()
{
    id = 0;
    hostid = "";
}

Node::Node(int id, QString hostid)
{
    this->id = id;
    this->hostid = hostid;
}

Node::Node(int id, QString hostid, QVector<struct arc> arcList)
{
    Node(id, hostid);
    this->arcList = arcList;
}

Node::Node(int id, QString hostid, QVector<struct arc> arcList, QVector<QString> vuls)
{
    Node(id, hostid, arcList);
    this->vuls = vuls;
}

int Node::getId() const
{
    return id;
}

void Node::setId(int value)
{
    id = value;
}

int Node::getPosX() const
{
    return posX;
}

void Node::SetPosX(int X)
{
    posX=X;
}

int Node::getPosY() const
{
    return posY;
}

void Node::SetPosY(int Y)
{
    posY=Y;
}

QString Node::getHostid() const
{
    return hostid;
}

void Node::setHostid(const QString &value)
{
    hostid = value;
}

QVector<QString> Node::getVuls() const
{
    return vuls;
}

void Node::setVuls(const QVector<QString> &value)
{
    vuls = value;
}

QVector<struct arc> Node::getArcList() const
{
    return arcList;
}

void Node::setArcList(const QVector<struct arc> &value)
{
    arcList = value;
}

void Node::addArc(int hdst, QString proto, int datanum)
{
    //如果这条边已经存在，把新的数据包数据加进去
    QVector<struct arc>::iterator it;
    for(it = arcList.begin(); it < arcList.end(); it++){
        if(it->hdst == hdst && it->proto == proto){
            it->datanum += datanum;
            return;
        }
    }

    //如果这条边不存在，新建一条边
    struct arc tempArc;
    tempArc.hdst = hdst;
    tempArc.proto = proto;
    tempArc.datanum = datanum;
    arcList.append(tempArc);
    return;
}

