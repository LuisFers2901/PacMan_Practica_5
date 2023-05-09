#include "eghosts.h"

EGhosts::EGhosts(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, QObject *parent)
{
    this->PosX = PosX;
    this->PosY = PosY;
    this->WidthSprite = WidthSprite;
    this->HeightSprite = HeightSprite;
    this->Speed = Speed;

    TimerSprite = new QTimer();
    TimerSprite->start(65);
    TimerMove = new QTimer();
    TimerMove->start(18);

    Rows = 0;
    Columns = 0;

    PixMap = new QPixmap(":/Images/Sprites.png");

    connect(TimerSprite,&QTimer::timeout,this,&EGhosts::RefreshSprite);

}

QRectF EGhosts::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void EGhosts::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (Sprite) {
    case 1:
        //Adelante
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*4) + 1, WidthSprite, HeightSprite);

        break;
    case 2:
        //Atras
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*4) + 1, WidthSprite, HeightSprite);
        break;
    case 3:
        //Arriba
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*4) + 1, WidthSprite, HeightSprite);
        break;
    case 4:
        //Abajo
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*4) + 1, WidthSprite, HeightSprite);
        break;
    }
}

void EGhosts::RefreshSprite()
{

    {
        Columns += 15;

        if (Columns >= 30){
            Columns = 0;
        }
        this->update((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
    }

}
