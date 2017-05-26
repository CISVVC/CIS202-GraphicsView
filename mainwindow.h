#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "circleanim.h"
#include "coswave.h"
#include "sinewave.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTimer *m_timer;
    int m_speed;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void drawSine();
    void drawCosine();
    void drawTan();
    void incDeg();
    void setSpeed(int speed);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    int m_xres,m_yres;
    QGraphicsRectItem *rectangle;
    void rotateRectangle(int degrees);
    void drawAxes();
    void drawCircle();
    CircleAnim *m_circle;
    SineWave *m_sinewave;
    CosineWave *m_cosinewave;
};

#endif // MAINWINDOW_H
