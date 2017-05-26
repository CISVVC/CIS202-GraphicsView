#include "sinewave.h"
#include <cmath>

SineWave::SineWave() {
    m_current = 0;
    m_xres = 2;
    m_yres = 100;
}

QRectF SineWave::boundingRect() const{
    return QRectF(0,0,100,100);
}

void SineWave::incCurrent() {
    if(m_current < 360) {
       m_current++;
    }
    else {
        m_current = 0;
    }
}

double SineWave::getRad() {
    return m_current * M_PI / 180.0;
}

void SineWave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int radius = 100;
    int c_size = 10;
    double rad = getRad();
    QPainterPath qp;
    QPointF lastPoint = QPointF(0.0,0.0);
    for(int d = 0;d<360;d++) {
       qp.moveTo(lastPoint);
       QPointF nextPoint = QPointF(m_xres * d,-1*m_yres * sin(d*M_PI/180.0));
       qp.lineTo(nextPoint);
       lastPoint = nextPoint;
    }
    painter->drawPath(qp);
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPoint(m_xres*m_current,-m_yres*sin(getRad())),c_size,c_size);
}
