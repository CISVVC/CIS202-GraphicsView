#include "wave.h"
#include <cmath>
typedef QPair<QPointF,QPointF> PointPair;

Wave::Wave(QString equation,fN fn,const QColor &c) :
    m_equation(equation),
    m_function(fn),
    m_current(0),
    m_xres(2),
    m_yres(100),
    m_color(c)
{
    /*
    // If we want pictures instead moving along the curve
    m_logo(QPixmap(":/logo.png").scaled(QSize(30,62),Qt::KeepAspectRatio)),
    m_pi_image(QPixmap(":/pi-symbol.png").scaled(QSize(30,62),Qt::KeepAspectRatio))
    */
    m_curve = getCurve();
}


QPainterPath Wave::getCurve() {
    QPainterPath qp;
    QPointF lastPoint = QPointF(0.0,0.0);
    for(int d = 0;d<360;d++) {
       qp.moveTo(lastPoint);
       QPointF nextPoint = QPointF(m_xres * d,-1*m_yres * m_function(d*M_PI/180.0));
       qp.lineTo(nextPoint);
       lastPoint = nextPoint;
    }
    return qp;
}

QRectF Wave::boundingRect() const{
    return QRectF(-360,-360,360,360);
}

void Wave::nextStep(int inc) {
    if(m_current < 360) {
       m_current+=inc;
    }
    else {
        m_current = 0;
    }
}

double Wave::getRad() {
    return m_current * M_PI / 180.0;
}

QString Wave::equation() {
   return m_equation;
}

QColor Wave::color() {
    return m_color;
}

QPainterPath Wave::getUnitCircle(QPointF cp) {
    int ticksize = 3;
    int m_radius = 10;
    QPainterPath qp;
    qp.addEllipse(cp,m_radius,m_radius);
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
        qp.moveTo(cp+pair.first);
        qp.lineTo(cp+pair.second);
    }
    qp.addEllipse(cp,2,2);

    return qp;
}

void Wave::drawCircle(QPainter *painter,QPointF cp) {
    painter->drawPath(getUnitCircle(cp));
}

void Wave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    int radius = 100;
    int ball_radius = 30;
    int c_size = 5;
    double rad = getRad();
    painter->setPen(QPen(m_color,0.5));
    painter->drawPath(m_curve);
    painter->setPen(Qt::red);
    //painter->setBrush(Qt::red);
    QPointF cp = QPointF(m_xres*m_current,-m_yres*m_function(getRad()));
//    painter->drawEllipse(cp,c_size,c_size);
//    painter->drawPixmap(cp,m_logo);
//    painter->drawPixmap(cp+QPointF(35,0),m_pi_image);
    drawCircle(painter,cp);
    painter->drawLine(cp,cp+QPoint(ball_radius*cos(rad),-ball_radius*sin(rad)));
    painter->setBrush(Qt::blue);
    painter->drawEllipse(cp+QPoint(ball_radius*cos(rad),-ball_radius*sin(rad)),c_size,c_size);
}
