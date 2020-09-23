#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "attackgraph.h"
#include "sqlconnect.h"
#include "node.h"
#include "painter.h"
#include <QPainter>
#include <QRect>
#include <QPaintEvent>
#include <QBrush>
#include <QFont>

int  Painter::Change(int &flag)
{
       flag=1;
       return flag;

}


