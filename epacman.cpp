#include "epacman.h"

EPacMan::EPacMan(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, QObject *parent)
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

    connect(TimerSprite,&QTimer::timeout,this,&EPacMan::RefreshSprite);



}

QRectF EPacMan::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void EPacMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch (Sprite) {
    case 1:
        //Adelante
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*0) + 1, WidthSprite, HeightSprite);

        break;
    case 2:
        //Atras
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*1) + 1, WidthSprite, HeightSprite);
        break;
    case 3:
        //Arriba
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*2) + 1, WidthSprite, HeightSprite);
        break;
    case 4:
        //Abajo
        painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, Columns, (16*3) + 1, WidthSprite, HeightSprite);
        break;
    }
}

void EPacMan::MoveEntity(int Option)
{
    disconnect(TimerMove, &QTimer::timeout, this, &EPacMan::MoveUp);
    disconnect(TimerMove, &QTimer::timeout, this, &EPacMan::MoveDown);
    disconnect(TimerMove, &QTimer::timeout, this, &EPacMan::MoveLeft);
    disconnect(TimerMove, &QTimer::timeout, this, &EPacMan::MoveRight);

        switch (Option) {
        case 1:
            connect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveUp);
            break;
        case 2:
            connect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveDown);
            break;
        case 3:
            connect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveLeft);
            break;
        case 4:
            connect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveRight);
            break;
        }
}

void EPacMan::StopEntity(int Option)
{

        switch (Option) {
        case 1:
            disconnect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveUp);
            PosY = PosY + Speed;
            setPos(PosX, PosY);
            break;
        case 2:
            disconnect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveDown);
            PosY = PosY - Speed;
            setPos(PosX, PosY);
            break;
        case 3:
            disconnect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveLeft);
            PosX = PosX + Speed;
            setPos(PosX, PosY);
            break;
        case 4:
            disconnect(TimerMove,&QTimer::timeout,this,&EPacMan::MoveRight);
            PosX = PosX - Speed;
            setPos(PosX, PosY);
            break;
        }
}



void EPacMan::MoveUp()
{
    PosY = PosY - Speed;
    setPos(PosX, PosY);
    Sprite = 3;
}

void EPacMan::MoveDown()
{
    PosY = PosY + Speed;
    setPos(PosX, PosY);
    Sprite = 4;
}

void EPacMan::MoveLeft()
{
    PosX = PosX - Speed;
    setPos(PosX, PosY);
    Sprite = 2;
}

void EPacMan::MoveRight()
{
    PosX = PosX + Speed;
    setPos(PosX, PosY);
    Sprite = 1;
}

void EPacMan::RefreshSprite()
{
    {
        Columns += 15;

        if (Columns >= 30){
            Columns = 0;
        }
        this->update((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
    }
}

