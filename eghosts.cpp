#include "eghosts.h"


EGhosts::EGhosts(Entities *Entity, QObject *parent)
{
    this->WidthSprite = Entity->WidthSprite;
    this->HeightSprite = Entity->HeightSprite;
    this->PosX = Entity->PosX;
    this->PosY = Entity->PosY;
    this->Speed = Entity->Speed;

}

QRectF EGhosts::boundingRect() const
{
    return QRectF((-WidthSprite)/2, (-HeightSprite)/2, WidthSprite, HeightSprite);
}

void EGhosts::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

void EGhosts::ExitHouse(Entities *Entity, int UpDown, int LeftRight)
{
    for (int i = 0; i < 17; i++){
        if (LeftRight == 1){
            Entity->MoveRight();
        }
        else if (LeftRight == 2){
            Entity->MoveLeft();
        }
    }

    for (int i = 0; i < 23; i++){
        if (UpDown == 1){
            Entity->MoveUp();
        }
        else if (UpDown == 2){
            Entity->MoveDown();
        }
    }
}

void EGhosts::Distance(int PosXPacMan, int PosYPacMan, int PosXGhost, int PosYGhost, Entities *Entity)
{

    //true = Right false = Left
    //true = Up false = Down

    DesUp = true;
    DesDown = true;
    DesLeft = true;
    DesRight = true;

    ListBarriersMap.BarriersMap();

    for (auto barrier : ListBarriersMap.Paredes) {
        Entity->MoveUp();
        if(barrier->collidesWithItem(Entity)){
            DesUp = false;
        }
        Entity->MoveDown();
        Entity->MoveDown();
        if(barrier->collidesWithItem(Entity)){
            DesDown = false;
        }
        Entity->MoveUp();
        Entity->MoveLeft();
        if(barrier->collidesWithItem(Entity)){
            DesLeft = false;
        }
        Entity->MoveRight();
        Entity->MoveRight();
        if(barrier->collidesWithItem(Entity)){
            DesRight = false;
        }
        Entity->MoveLeft();
    }

    DistanceX = PosXGhost - PosXPacMan;
    DistanceY = PosYGhost - PosYPacMan;

    if (DistanceX == 0 && DistanceY > 0){
        if (DesUp == true){
            Entity->MoveUp();
        }
    }
    else if (DistanceX == 0 && DistanceY < 0){
        Entity->MoveDown();
    }
    else if (DistanceX > 0 && DistanceY == 0){
        Entity->MoveLeft();
    }
    else if (DistanceX < 0 && DistanceY == 0){
        Entity->MoveRight();
    }
    else if (DistanceX > 0 && DistanceY > 0){
        MoveNorthwest(Entity);
    }
    else if (DistanceX < 0 && DistanceY > 0){
        MoveNortheast(Entity);
    }
    else if (DistanceX > 0 && DistanceY < 0){
        MoveSouthwest(Entity);
    }
    else if (DistanceX < 0 && DistanceY < 0){
        MoveSoutheast(Entity);
    }

    this->PosX = Entity->PosX;
    this->PosY = Entity->PosY;
    setPos(PosX, PosY);

}

void EGhosts::MoveNortheast(Entities *Entity)
{
    if (Blocked == 1){
        Entity->MoveRight();
    }
    else if (Blocked == 4){
        Entity->MoveUp();
    }

}

void EGhosts::MoveNorthwest(Entities *Entity)
{
    if (Blocked == 1){
        Entity->MoveLeft();
    }
    else if (Blocked == 3){
        Entity->MoveUp();
    }

}

void EGhosts::MoveSouthwest(Entities *Entity)
{
    if (Blocked == 2){
        Entity->MoveLeft();
    }
    else if (Blocked == 3){
        Entity->MoveDown();
    }
}

void EGhosts::MoveSoutheast(Entities *Entity)
{
    if (Blocked == 2){
        Entity->MoveRight();
    }
    else if (Blocked == 4){
        Entity->MoveDown();
    }
}
