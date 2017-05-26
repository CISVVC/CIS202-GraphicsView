#ifndef COSINEWAVE_H
#define COSINEWAVE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class CosineWave : public QGraphicsItem {
public:
    CosineWave();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void incCurrent();
    double getRad();
private:
    int m_current,m_xres,m_yres;
};

#endif // COSINEWAVE_H
