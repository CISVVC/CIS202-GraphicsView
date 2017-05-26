#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "circleanim.h"
#include "wave.h"

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
    void nextStep();
    void setSpeed(int speed);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    int m_xres,m_yres;
    QGraphicsRectItem *rectangle;
    void drawAxes();
    void drawCircle();
    CircleAnim *m_circle;
    Wave *m_sinewave;
    Wave *m_cosinewave;
};

#endif // MAINWINDOW_H
