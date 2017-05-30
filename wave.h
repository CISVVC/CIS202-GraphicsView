#ifndef WAVE_H
#define WAVE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
typedef double(*fN)(double);
class Wave : public QGraphicsItem {
public:
    Wave(QString equation,fN fn,const QColor &c=QColor(0,0,255));
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void nextStep(int inc);
    double getRad();
    QString equation();
    QColor color();
    QPainterPath getCurve();
    QPainterPath getUnitCircle(QPointF cp);
    void drawCircle(QPainter *painter,QPointF cp);
private:
    QString m_equation;
    int m_current,m_xres,m_yres;
    QPixmap m_logo;
    QPixmap m_pi_image;
    QPainterPath m_curve;
    QColor m_color;
    fN m_function;
};

#endif // WAVE_H
