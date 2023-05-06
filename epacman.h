#ifndef EPACMAN_H
#define EPACMAN_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>


class EPacMan : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:


    int PosX, PosY, Speed, Rows, Columns, WidthSprite, HeightSprite, Sprite;

    QTimer *Timer;
    QPixmap *PixMap;

    EPacMan(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Movimiento
    //void StartPos();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

signals:

public slots:

    void RefreshSprite();
};

#endif // EPACMAN_H
