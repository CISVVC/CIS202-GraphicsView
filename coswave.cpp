#include "coswave.h"
#include <cmath>

CosineWave::CosineWave() {
    m_current = 0;
    m_xres = 2;
    m_yres = 100;
}

QRectF CosineWave::boundingRect() const{
    return QRectF(0,0,100,100);
}

void CosineWave::incCurrent() {
    if(m_current < 360) {
       m_current++;
    }
    else {
        m_current = 0;
    }
}

double CosineWave::getRad() {
    return m_current * M_PI / 180.0;
}

void CosineWave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int radius = 100;
    int c_size = 10;
    double rad = getRad();
    QPainterPath qp;
    QPointF lastPoint = QPointF(0.0,0.0);
    for(int d = 0;d<360;d++) {
       qp.moveTo(lastPoint);
       QPointF nextPoint = QPointF(m_xres * d,-m_yres * cos(d*M_PI/180.0));
       qp.lineTo(nextPoint);
       lastPoint = nextPoint;
    }
    painter->setPen(Qt::magenta);
    painter->drawPath(qp);
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPoint(m_xres*m_current,-m_yres*cos(getRad())),c_size,c_size);
}
