#include "legenditem.h"
#include<QDebug>


LegendItem::LegendItem(Wave* wave,QObject *parent) :
    QObject(parent),
    QGraphicsItem(),
    m_wave(wave),
    toggle(true) {

}

QRectF LegendItem::boundingRect() const {
    return QRectF(0,0,m_wave->equation().length()*10,10);
}

bool LegendItem::isOn() {
    return toggle;
}

bool LegendItem::on() {
    return toggle;
}

void LegendItem::on(bool value) {
    toggle = value;
}

Wave *LegendItem::wave() {
    return m_wave;
}

void LegendItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    toggle = !toggle;
    emit clicked(this);
    QGraphicsItem::mousePressEvent(event);
}

void LegendItem::paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget) {
    painter->setPen(m_wave->color());
    if(isOn()) {
        painter->setBrush(m_wave->color());
    }
    painter->drawRect(QRectF(0,0,5,5));
    painter->setPen(Qt::black);
    painter->drawText(QPointF(10,7),QString(" - ") + m_wave->equation());
}
