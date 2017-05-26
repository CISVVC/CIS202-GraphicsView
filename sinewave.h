#ifndef SINEWAVE_H
#define SINEWAVE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class SineWave : public QGraphicsItem {
public:
    SineWave();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void incCurrent();
    double getRad();
private:
    int m_current,m_xres,m_yres;
};

#endif // SINEWAVE_H
