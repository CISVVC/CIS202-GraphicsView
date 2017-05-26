#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene();
    ui->graphicsView->setScene(m_scene);
    m_xres = 2;
    m_yres = 100;
    m_speed = 500;
    drawAxes();
    drawCircle();
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&MainWindow::incDeg);
    m_timer->start(50);
    m_sinewave = new SineWave();
    m_cosinewave = new CosineWave();
    m_scene->addItem(m_sinewave);
    m_scene->addItem(m_cosinewave);

    //rectangle = m_scene->addRect(0,0,100,100,pen,brush);
    //rectangle->setFlag(QGraphicsItem::ItemIsMovable, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateRectangle(int degrees)
{
    rectangle->setRotation(degrees);
}

void MainWindow::drawAxes() {
    m_scene->addLine(0,0,m_xres * 360,0);
    m_scene->addLine(0,2*m_yres,0,-2*m_yres);
}

void MainWindow::drawCircle() {
   //auto c = m_scene->addEllipse(QRectF(0,0,100,100));
   m_circle = new CircleAnim();
   m_scene->addItem(m_circle);
   m_circle->setPos(QPointF(0,-3*m_yres));
}


void MainWindow::drawSine() {
    m_scene->addItem(m_sinewave);
    //p->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void MainWindow::drawCosine() {
    QPainterPath qp;
    QPointF lastPoint = QPointF(0.0,0.0);
    for(int d = 0;d<360;d++) {
       qp.moveTo(lastPoint);
       QPointF nextPoint = QPointF(m_xres * d,-1*m_yres * cos(d*M_PI/180.0));
       qp.lineTo(nextPoint);
       lastPoint = nextPoint;
    }
    m_scene->addPath(qp);

}

void MainWindow::drawTan() {
    QPainterPath qp;
    QPointF lastPoint = QPointF(0.0,0.0);
    for(int d = 0;d<360;d++) {
       qp.moveTo(lastPoint);
       QPointF nextPoint = QPointF(m_xres * d,-1*m_yres * tan(d*M_PI/180.0));
       qp.lineTo(nextPoint);
       lastPoint = nextPoint;
    }
    m_scene->addPath(qp);

}

void MainWindow::incDeg() {
    m_circle->incCurrent();
    m_sinewave->incCurrent();
    m_cosinewave->incCurrent();
    m_scene->update();
}

void MainWindow::setSpeed(int speed) {
    m_speed = speed;
    m_timer->setInterval(speed);
}


