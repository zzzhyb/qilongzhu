#ifndef PAINTER_H
#define PAINTER_H

#endif // PAINTER_H
#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPainter>
#include <QRect>
#include <QPoint>
#include <QDebug>

class Painter {

public :
    //重写重绘事件
    int flag=0;
    int Change(int &flag);

};
