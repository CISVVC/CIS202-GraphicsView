#ifndef AXIS_H
#define AXIS_H

#include <QGraphicsItem>
#include <QPainter>

class Axis : public QObject,public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Axis(int xres,int yres,int xticks,int yticks,QObject* parent=0);
    QRectF boundingRect() const;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    int m_xres,m_yres,m_xticks,m_yticks;
};

#endif // AXIS_H
