
#ifndef BARRIERS_H
#define BARRIERS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class Barriers: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    int WidthBarrier, HeightBarrier, X, Y;

    Barriers(int X, int Y, int WidthBarrier, int HeightBarrier);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


};

#endif // BARRIERS_H
