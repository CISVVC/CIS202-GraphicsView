#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    QPen pen;
    pen.setWidth(2);
    QBrush brush(QColor(0,0,255));
    rectangle = scene->addRect(0,0,100,100,pen,brush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::rotateRectangle(int degrees)
{
    rectangle->setRotation(degrees);
}

void MainWindow::updateRotation()
{
    int degrees = ui->lineEdit->text().toInt();
    rotateRectangle(degrees);
}

