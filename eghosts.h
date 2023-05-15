#ifndef EGHOSTS_H
#define EGHOSTS_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>
#include <QThread>
#include "entities.h"
#include "listbarriers.h"
#include "barriers.h"


class EGhosts: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    int WidthSprite, HeightSprite, Speed, PosX, PosY;
    bool DesUp, DesDown, DesLeft, DesRight;
    bool Sides = true;  //true = Right false = Left
    bool Poles = true;  //true = Up false = Down

    EGhosts(Entities *Entity,QObject *parent);

    QRectF boundingRect() const;                //Genera la hitbox de la entidad
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    ListBarriers ListBarriersMap;
    int DistanceX, DistanceY, Blocked;

    void ExitHouse(Entities *Entity, int UpDown, int LeftRight);

    void Distance(int PosXPacMan, int PosYPacMan, int PosXGhost, int PosYGhost, Entities *Entity);
    void MoveNortheast(Entities *Entity);
    void MoveNorthwest(Entities *Entity);
    void MoveSouthwest(Entities *Entity);
    void MoveSoutheast(Entities *Entity);

};

#endif // EGHOSTS_H
