
#ifndef BARRIERS_H
#define BARRIERS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QList>
#include <QColor>

class Barriers: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:

    QPixmap *PixMap;

    int WidthBarrier, HeightBarrier, X, Y, Color;

    Barriers(int X, int Y, int WidthBarrier, int HeightBarrier, int Color);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QColor ColorHex;

};

#endif // BARRIERS_H
