#include "circleanim.h"
#include <cmath>

CircleAnim::CircleAnim() {
    m_current = 0;
}

QRectF CircleAnim::boundingRect() const{
    return QRectF(0,0,100,100);
}

void CircleAnim::incCurrent() {
    if(m_current < 360) {
       m_current++;
    }
    else {
        m_current = 0;
    }
}

double CircleAnim::getRad() {
    return m_current * M_PI / 180.0;
}

void CircleAnim::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int radius = 100;
    int c_size = 10;
    painter->drawEllipse(QPoint(0,0),radius,radius);
    double rad = getRad();
    painter->drawLine(QPoint(0,0),
                      QPoint(radius*cos(rad),-radius*sin(rad)));
    painter->setBrush(Qt::blue);
    painter->drawEllipse(QPoint(radius*cos(rad),-radius*sin(rad)),c_size,c_size);
}
