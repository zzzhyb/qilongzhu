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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("攻击图系统"));
    //定义申明控件
    DataImport=new QPushButton;
    Run=new QPushButton;
    Quicker=new QPushButton;
    Slower=new QPushButton;

   //连接信号槽
    connect(DataImport,SIGNAL(clicked()),this,SLOT(on_DataImport_clicked()));
    connect(Run,SIGNAL(clicked()),this,SLOT(on_Run_clicked()));
    connect(Quicker,SIGNAL(clicked()),this,SLOT(on_Quicker_clicked()));
    connect(Slower,SIGNAL(clicked()),this,SLOT(on_Slower_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//核心代码
    Painter static changeflag = Painter();

void MainWindow::paintEvent(QPaintEvent *event)
{

    //printf("%d\n",changeflag.flag);
    if(changeflag.flag==1)//只有当flag变为1时，才会生成攻击图
    {
    int i=0;
    int sum=0;

    //初始化攻击图
    AttackGraph node = AttackGraph();
    node.initGraph();

    QPainter painter(this); // 创建QPainter一个对象
    QPen pen;
    pen.setColor(Qt::blue);             //画笔
    painter.setPen(pen);

    QBrush bruch(Qt::FDiagPattern);     // 画刷
    painter.setBrush(bruch);

    //遍历结点数据
    QVector<Node>::iterator it;
    QPointF pos[1000];//初始化坐标结点数组
    for(it = node.nodeList.begin(),i=0; it < node.nodeList.end(); it++,i++){
        //pos[i].setX(it->getPosX());                           //获取结点的横坐标
        //pos[i].setY(it->getPosY());                           //获取结点的纵坐标
        //printf("%d,%d",pos[i].x(),pos[i].y());
        pos[i].setX(rand()%2000);                               //获取结点的横坐标
        pos[i].setY(rand()%1000);                               //获取结点的纵坐标
        sum++;
        }


    painter.drawPolyline(pos,100);


    QLineF line[1000];

    for(i=0;i<sum/2;i++)
    {
        line[i].setP1(pos[i]);
        line[i].setP2(pos[sum-i]);
    }

    painter.drawLines(line,500);
    painter.drawPoints(pos,100);

    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    for(it = node.nodeList.begin(),i=0; it < node.nodeList.end()&&i<sum; it++,i++)//为每个结点生成一个圆
    {
        painter.drawEllipse(pos[i].x(),pos[i].y(),10,10);
        painter.drawText(pos[i].x(),pos[i].y()-5,it->getHostid());
    }

}

}

void MainWindow::on_DataImport_clicked(bool checked)
{
    SqlConnect sqlConnect = SqlConnect();
    sqlConnect.testDataBase();
}

void MainWindow::on_Run_clicked(bool checked)
{
    changeflag.Change(changeflag.flag);
    //printf("%d\n",changeflag.flag);
}

void MainWindow::on_Quicker_clicked(bool checked)
{

}

void MainWindow::on_Slower_clicked(bool checked)
{

}
