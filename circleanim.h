#ifndef CIRCLEANIM_H
#define CIRCLEANIM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class CircleAnim : public QGraphicsItem {
public:
    CircleAnim();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void nextStep(int inc);
    double getRad();
    void drawCircle(QPainter *painter);
    QPainterPath getUnitCircle();
private:
    int m_current;
    int m_radius,m_csize;
    QPainterPath m_unitcircle;
};

#endif // CIRCLEANIM_H
