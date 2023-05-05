
#ifndef BARRIERS_H
#define BARRIERS_H

#include <QObject>
#include <QGraphicsItem>

class Barriers: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    int WidthBarrier, HeightBarrier;

    //Barriers();

    //QRectF boundingRect() const;
};

#endif // BARRIERS_H
