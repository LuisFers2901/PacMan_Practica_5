#ifndef WIDGET_H
#define WIDGET_H



#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QApplication>
#include <QScreen>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QIcon>
#include <QList>
#include <QSoundEffect>
#include <QLabel>
#include <QFont>
#include <QString>
#include "entities.h"
#include "epacman.h"
#include "eghosts.h"
#include "levels.h"
#include "barriers.h"
#include "ambientsound.h"
#include "listbarriers.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    int Cont = 2;
    int X, Y, Width, Height, Option, Points, LastOption = 4;
    bool DesUp, DesDown, DesLeft, DesRight;

    QTimer *TimerMo;


    void keyPressEvent(QKeyEvent *evento);
    void EvalueCollision();

    QGraphicsScene *MazeMap;

    Entities *PacMan;
    Entities *Blinky;
    Entities *Pinky;
    Entities *Inky;
    Entities *Clyde;

    EGhosts *FunctionsGhosts;

    QLabel *PointCounter;
    QFont *Font;
    QString Score;


    QTimer *Delay;
    QTimer *collisionTimer;
    ListBarriers ListBarriersMap;
    ListBarriers ListFoodMap;
    ListBarriers ListPowerUps;
    ListBarriers ListPortalsMap;
    ListBarriers ListLifesMap;
    QList<Entities*>EntitiesPlay;



};

#endif // WIDGET_H
