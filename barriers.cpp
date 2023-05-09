
#include "barriers.h"


Barriers::Barriers(int X, int Y, int WidthBarrier, int HeightBarrier)
{
    this-> X = X;
    this-> Y = Y;
    this-> WidthBarrier = WidthBarrier;
    this-> HeightBarrier = HeightBarrier;
}

QRectF Barriers::boundingRect() const
{
    return QRectF(X, Y, WidthBarrier, HeightBarrier);
}

void Barriers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::transparent);
    //painter->setPen(Qt::NoPen);

    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

