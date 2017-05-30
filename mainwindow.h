#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QTimer>
#include "circleanim.h"
#include "wave.h"
#include "legenditem.h"

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

protected:
    void resizeEvent(QResizeEvent *event) override;

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
    QVector<Wave*> m_waves;
    void makeWaves();
    void drawLegend();
    void setWaveVisible(LegendItem*);
};

#endif // MAINWINDOW_H
