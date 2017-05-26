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
    void incCurrent();
    double getRad();
private:
    int m_current;
};

#endif // CIRCLEANIM_H
