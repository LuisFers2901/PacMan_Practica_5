#ifndef LISTBARRIERS_H
#define LISTBARRIERS_H

#include <QList>
#include "barriers.h"



class ListBarriers
{

public:

    ListBarriers();
    ~ListBarriers();
    void BarriersMap();  // lista de paredes
    void FoodsMap();
    void SpecialBarriers();
    void CreateBarriers(int X, int Y, int WidthBarrier, int HeightBarrier, int Color);// función para crear las paredes
    void PowerUp();
    QList<Barriers*> Paredes;
    QList<Barriers*> Food;
    QList<Barriers*> Portals;
    QList<Barriers*> PowerUps;
    QList<Barriers*> Lifes;
};

#endif // LISTBARRIERS_H
