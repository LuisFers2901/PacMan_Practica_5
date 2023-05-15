#include "entities.h"

Entities::Entities(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, int Sprite, int TimerS, int TimerM, QObject *parent)
{

    this->PosX = PosX;
    this->PosY = PosY;
    this->WidthSprite = WidthSprite;
    this->HeightSprite = HeightSprite;
    this->Speed = Speed;
    this->Sprite = Sprite;
    this->SpriteOp = 4;
    this->TimerS = TimerS;
    this->TimerM = TimerM;
    this->Columns = 0;
    this->PosXPixMap = 0;
    this->PosYPixMap = 0;
    StartPosXPixMap = 0;

    TimerSprite = new QTimer();
    TimerSprite->start(TimerS);
    TimerMove = new QTimer();
    TimerMove->start(TimerM);
    PixMap = new QPixmap(":/Images/Sprite-WithoutBackground.png");
    setPos(PosX, PosY);
    connect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);

}

QRectF Entities::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void Entities::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    switch (Sprite) {
    case 1:
        this->PosYPixMap = (16*0)+1;
        NumberSprite = 2;
        break;
    case 2:
        this->PosYPixMap = (16*4)+1;
        NumberSprite = 2;
        break;
    case 3:
        this->PosYPixMap = (16*5)+1;
        NumberSprite = 2;
        break;
    case 4:
        this->PosYPixMap = (16*6)+1;
        NumberSprite = 2;
        break;
    case 5:
        this->PosYPixMap = (16*7)+1;
        NumberSprite = 2;
        break;
    case 6:
        this->PosXPixMap = 128;
        this->PosYPixMap = (16*4)+1;
        NumberSprite = 4;
        break;
    case 7:
        this->PosXPixMap = 128;
        this->PosYPixMap = (16*5)+1;;
        NumberSprite = 4;
        break;
    case 8:
        this->PosXPixMap = 31;
        this->PosYPixMap = (16*0)+1;
        NumberSprite = 12;
        break;
    }

    if (Sprite == 1){
        switch (SpriteOp) {
        case 1:
            this->PosYPixMap = (16*2)+1;
            break;
        case 2:
            this->PosYPixMap = (16*3)+1;
            break;
        case 3:
            this->PosYPixMap = (16*1)+1;
            break;
        case 4:
            this->PosYPixMap = (16*0)+1;
            break;
        }
    }

    else if (Sprite >= 2 && Sprite <= 5){
        switch (SpriteOp) {
        case 1:
            this->PosXPixMap = (16*4);
            break;
        case 2:
            this->PosXPixMap = (16*6);
            break;
        case 3:
            this->PosXPixMap = (16*2);
            break;
        case 4:
            this->PosXPixMap = (16*0);
            break;
        }

        StartPosXPixMap = PosXPixMap;
    }

    painter->drawPixmap((-WidthSprite)/2, (-HeightSprite)/2, *PixMap, PosXPixMap, PosYPixMap, WidthSprite, HeightSprite);
}

//    painter->setBrush(Qt::transparent);
//    painter->setPen(Qt::NoPen);

//    painter->setBrush(Qt::blue);
    //    painter->drawRect(boundingRect());


void Entities::MoveEntity(int Option)
{

    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveUp);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveDown);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveLeft);
    disconnect(TimerMove, &QTimer::timeout, this, &Entities::MoveRight);

    switch (Option) {
    case 1:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveUp);
        break;
    case 2:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveDown);
        break;
    case 3:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveLeft);
        break;
    case 4:
        connect(TimerMove,&QTimer::timeout,this,&Entities::MoveRight);
        break;
    }

}

void Entities::StopEntity(int Option)
{
    switch (Option) {
    case 1:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveUp);
        PosY = PosY + Speed;
        setPos(PosX, PosY);
        break;
    case 2:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveDown);
        PosY = PosY - Speed;
        setPos(PosX, PosY);
        break;
    case 3:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveLeft);
        PosX = PosX + Speed;
        setPos(PosX, PosY);
        break;
    case 4:
        disconnect(TimerMove,&QTimer::timeout,this,&Entities::MoveRight);
        PosX = PosX - Speed;
        setPos(PosX, PosY);
        break;
    }
}

void Entities::MoveUp()
{
    PosY = PosY - Speed;
    SpriteOp = 1;
    setPos(PosX, PosY);
}

void Entities::MoveDown()
{
    PosY = PosY + Speed;
    SpriteOp = 2;
    setPos(PosX, PosY);
}

void Entities::MoveLeft()
{
    PosX = PosX -Speed;
    SpriteOp = 3;
    setPos(PosX, PosY);
}

void Entities::MoveRight()
{
    PosX = PosX +Speed;
    SpriteOp = 4;
    setPos(PosX, PosY);
}

void Entities::Dead(int Option)
{
    Sprite = 8;
    StopEntity(Option);
    disconnect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);
    TimerSprite->start(200);
    connect(TimerSprite,&QTimer::timeout,this,&Entities::RefreshSprite);
}

void Entities::RefreshSprite()
{
    PosXPixMap += 16;
    if (PosXPixMap >= (NumberSprite * 16) + StartPosXPixMap){
        PosXPixMap = StartPosXPixMap;
    }
    this->update((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);

}
