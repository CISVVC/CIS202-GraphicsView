#include "circleanim.h"
#include <cmath>

typedef QPair<QPointF,QPointF> PointPair;

CircleAnim::CircleAnim() :
    m_current(0),
    m_radius(50),
    m_csize(5)
{
    m_unitcircle = getUnitCircle();
}

QRectF CircleAnim::boundingRect() const{
    return QRectF(0,0,100,100);
}

void CircleAnim::nextStep(int inc) {
    if(m_current < 360) {
       m_current+=inc;
    }
    else {
        m_current = 0;
    }
}

double CircleAnim::getRad() {
    return m_current * M_PI / 180.0;
}

void CircleAnim::drawCircle(QPainter* painter) {
    painter->drawPath(m_unitcircle);
}

QPainterPath CircleAnim::getUnitCircle() {
    int ticksize = 3;
    QPainterPath qp;
    qp.addEllipse(QPoint(0,0),m_radius,m_radius);
    QVector<PointPair> points;
    // 0
    points.append(PointPair(
            QPointF(m_radius-ticksize,0),
            QPointF(m_radius+ticksize,0)
                      ));
    //pi/4
    points.append(PointPair(
                        QPointF(m_radius*cos(M_PI/4)-ticksize,-m_radius*sin(M_PI/4)+ticksize),
                        QPointF(m_radius*cos(M_PI/4)+ticksize,-m_radius*sin(M_PI/4)-ticksize)
                      ));
    // pi/2
    points.append(PointPair(
                    QPointF(0,-m_radius-ticksize),
                    QPointF(0,-m_radius+ticksize)
                      ));
    // 3pi/4
    points.append(PointPair(
            QPointF(m_radius*cos(3*M_PI/4)-ticksize,-m_radius*sin(M_PI/4)-ticksize),
            QPointF(m_radius*cos(3*M_PI/4)+ticksize,-m_radius*sin(M_PI/4)+ticksize)
                      ));
    // 180
    points.append(PointPair(
            QPointF(-m_radius-ticksize,0),
            QPointF(-m_radius+ticksize,0)
                      ));
    // 3pi/2
    points.append(PointPair(
        QPointF(0,m_radius-ticksize),
        QPointF(0,m_radius+ticksize)
                      ));
    // 3pi/2
    points.append(PointPair(
        QPointF(m_radius*cos(5*M_PI/4)-ticksize,-m_radius*sin(5*M_PI/4)+ticksize),
        QPointF(m_radius*cos(5*M_PI/4)+ticksize,-m_radius*sin(5*M_PI/4)-ticksize)
                      ));
    // 7pi/4
    points.append(PointPair(
            QPointF(m_radius*cos(7*M_PI/4)-ticksize,-m_radius*sin(7*M_PI/4)-ticksize),
            QPointF(m_radius*cos(7*M_PI/4)+ticksize,-m_radius*sin(7*M_PI/4)+ticksize)
                      ));

   // build the tick marks
    for(auto pair : points) {
        qp.moveTo(pair.first);
        qp.lineTo(pair.second);
    }

    return qp;
}

void CircleAnim::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    double rad = getRad();
    //drawCircle(painter);
    painter->drawPath(m_unitcircle);
    painter->drawLine(QPoint(0,0),
                      QPoint(m_radius*cos(rad),-m_radius*sin(rad)));
    painter->setBrush(Qt::blue);
    painter->drawEllipse(QPoint(m_radius*cos(rad),-m_radius*sin(rad)),m_csize,m_csize);
}
