#ifndef EPACMAN_H
#define EPACMAN_H

#include <barriers.h>

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QKeyEvent>


class EPacMan : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:


    int PosX, PosY, Speed, Rows, Columns, WidthSprite, HeightSprite, Sprite;

    QTimer *TimerSprite;
    QTimer *TimerMove;
    QPixmap *PixMap;

    EPacMan(int PosX, int PosY, int WidthSprite, int HeightSprite, int Speed, QObject *parent = nullptr);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    //Movimiento
    //void StartPos();
    void keyPressEvent(QKeyEvent *evento, EPacMan *PacMan);
    void MoveEntity(int Option);
    void StopEntity(int Option);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

signals:

public slots:

    void RefreshSprite();
};

#endif // EPACMAN_H
