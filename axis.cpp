#include "axis.h"


Axis::Axis(int xres, int yres, int xticks, int yticks,QObject* parent) :
    QObject(parent),
    m_xres(xres),
    m_yres(yres),
    m_xticks(xticks),
    m_yticks(yticks)
{

}

QRectF Axis::boundingRect() const {
    return QRectF(-360,-360,360,360);
}

void Axis::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
    painter->drawLine(0,0,m_xres * 360,0);
    painter->drawLine(0,m_yres,0,-m_yres);

}
