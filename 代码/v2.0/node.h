#ifndef NODE_H
#define NODE_H
#include <QString>
#include <QVector>

struct arc{
    int hdst;
    QString proto;
    int datanum;
};

class Node
{
public:
    Node();
    Node(int id, QString hostid);
    Node(int id, QString hostid, QVector<struct arc> arcList);
    Node(int id, QString hostid, QVector<struct arc> arcList, QVector<QString> vuls);

    int getId() const;
    void setId(int value);

    int getPosX() const;
    void SetPosX(int X);

    int getPosY() const;
    void SetPosY(int Y);

    QString getHostid() const;
    void setHostid(const QString &value);

    QVector<struct arc> getArcList() const;
    void setArcList(const QVector<struct arc> &value);

    QVector<QString> getVuls() const;
    void setVuls(const QVector<QString> &value);

    void addArc(int hdst, QString proto, int datanum);

private:
    int id;
    int posX,posY;
    QString hostid;
    QVector<struct arc> arcList;
    QVector<QString> vuls;

};

#endif // NODE_H
