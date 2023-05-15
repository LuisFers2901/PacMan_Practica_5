
#include "barriers.h"


Barriers::Barriers(int X, int Y, int WidthBarrier, int HeightBarrier, int Color)
{
    PixMap = new QPixmap(":/Images/Sprite-WithoutBackground.png");
    this-> X = X;
    this-> Y = Y;
    this-> WidthBarrier = WidthBarrier;
    this-> HeightBarrier = HeightBarrier;
    this-> Color = Color;
    ColorHex.setNamedColor("#FFB7AE");
}

QRectF Barriers::boundingRect() const
{
    return QRectF(X, Y, WidthBarrier, HeightBarrier);
}

void Barriers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (Color) {
    case 0:
        painter->setBrush(Qt::transparent);
        painter->setPen(Qt::NoPen);
        break;
    case 1:
        painter->setBrush(ColorHex);
        break;
    case 2:
        painter->setBrush(Qt::black);

    case 4:
        painter->drawPixmap((-WidthBarrier)/2, (-HeightBarrier)/2, *PixMap, 0, 1, WidthBarrier, HeightBarrier);

    }
    if(Color == 3){
        painter->setBrush(ColorHex);
        painter->drawEllipse(boundingRect());
    }
    else{
        painter->drawRect(boundingRect());
    }
}

