#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<cmath>
#include "axis.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    m_scene = new QGraphicsScene(QRectF(-360,-360,360,360));

    ui->graphicsView->setScene(m_scene);
    m_xres = 2;
    m_yres = 100;
    m_speed = 600;
    drawCircle();
    makeWaves();
    for(auto w : m_waves) {
        m_scene->addItem(w);
        w->setPos(w->pos()-QPointF(600,100));
    }
    drawAxes();
    drawLegend();
    m_timer = new QTimer();
    connect(m_timer,&QTimer::timeout,this,&MainWindow::nextStep);
    m_timer->start(50);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawAxes() {
    //m_scene->addLine(-600,-100,m_xres * 360,-100);
    //m_scene->addLine(-600,m_yres-100,-600,-m_yres-100);
    Axis *axis = new Axis(m_xres,m_yres*2,8,8);
    m_scene->addItem(axis);
    axis->setPos(-600,-100);
}

void MainWindow::drawCircle() {
   m_circle = new CircleAnim();
   m_scene->addItem(m_circle);
   m_circle->setPos(QPointF(-600,-3.5*m_yres));
}

void MainWindow::makeWaves() {
    m_waves.append(
        new Wave("sine(d)",[] (double d){return sin(d);},QColor(0x8a,0x2b,0xe2)) // blueviolet
   );
    m_waves.append(
        new Wave("2*sine(d)",[] (double d){return 2*sin(d);},QColor(0,0,0x8b)) // DarkBlue
   );
    m_waves.append(
        new Wave("sine(2*d)",[] (double d){return sin(2*d);})
   );
   m_waves.append(
        new Wave("sine(110*d)",[] (double d){return sin(110*d);},QColor(0,0xce,0xd1)) // DarkTurquoise
   );
   m_waves.append(
        new Wave("sine(880*d)",[] (double d){return sin(880*d);},QColor(0,0x0,0x8b)) // DarkBlue
   );
    m_waves.append(
        new Wave("cosine(d)",[](double d){return cos(d);},QColor(255,128,0))
   );
    m_waves.append(
        new Wave("cosine(3*d)",[](double d){return cos(3*d);},QColor(255,128,0))
   );

}

void MainWindow::drawLegend() {
    int i=0;
    int cx = 15;
    int offset = -500;
    for(auto w : m_waves) {
        LegendItem *t = new LegendItem(w);
        connect(t,&LegendItem::clicked,this,&MainWindow::setWaveVisible);
        t->setPos(-600,offset+cx*i-11);
        m_scene->addItem(t);
        if(i != 0) {
            t->on(false);
            setWaveVisible(t);
        }
        i++;
    }

}

void MainWindow::setWaveVisible(LegendItem *legend) {
    if(legend->isOn()) {
        legend->wave()->setVisible(true);
    }
    else {
        legend->wave()->setVisible(false);
    }
}

void MainWindow::nextStep() {
    int inc = 5;
    for(auto w : m_waves) {
        w->nextStep(inc);
    }
    m_circle->nextStep(inc);
    m_scene->update();
}

void MainWindow::setSpeed(int speed) {
    m_speed = speed;
    m_timer->setInterval(speed);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    //ui->graphicsView->fitInView(ui->graphicsView->sceneRect(), Qt::KeepAspectRatio);
}


