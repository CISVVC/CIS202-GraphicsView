#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
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
    m_sinewave = new Wave([] (double d){return sin(d);});
    m_cosinewave = new Wave([](double d){return cos(d);},QColor(255,128,0));
    m_scene->addItem(m_sinewave);
    m_sinewave->setFlag(QGraphicsItem::ItemIsMovable, true);
    m_scene->addItem(m_cosinewave);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawAxes() {
    m_scene->addLine(0,0,m_xres * 360,0);
    m_scene->addLine(0,m_yres,0,-m_yres);
}

void MainWindow::drawCircle() {
   m_circle = new CircleAnim();
   m_scene->addItem(m_circle);
   m_circle->setPos(QPointF(0,-2.25*m_yres));
}


void MainWindow::incDeg() {
    int inc = 5;
    m_circle->nextStep(5);
    m_sinewave->nextStep(5);
    m_cosinewave->nextStep(5);
    m_scene->update();
}

void MainWindow::setSpeed(int speed) {
    m_speed = speed;
    m_timer->setInterval(speed);
}


