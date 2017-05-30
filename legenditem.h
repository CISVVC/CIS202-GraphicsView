#ifndef LEGENDITEM_H
#define LEGENDITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include "wave.h"



class LegendItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    explicit LegendItem(Wave* w,QObject* parent=0);
    QRectF boundingRect() const;
    bool isOn();
    bool on();
    void on(bool value);
    Wave* wave();

protected slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:
    void clicked(LegendItem*);

private:
    Wave* m_wave;
    bool toggle;
};

#endif // LEGENDITEM_H
