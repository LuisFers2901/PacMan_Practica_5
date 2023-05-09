#ifndef EGHOSTS_H
#define EGHOSTS_H

#include <barriers.h>

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>


class EGhosts: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:


    int PosX, PosY, Speed, Rows, Columns, WidthSprite, HeightSprite, Sprite;

    QTimer *TimerSprite;
    QTimer *TimerMove;
    QPixmap *PixMap;

    EGhosts(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

    void RefreshSprite();
};

#endif // EGHOSTS_H
