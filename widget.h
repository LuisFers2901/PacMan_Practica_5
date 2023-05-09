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
#include "epacman.h"
#include "eghosts.h"
#include "levels.h"
#include "barriers.h"
#include "ambientsound.h"


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

    int X, Y, Width, Height, Option;

    QGraphicsScene *MazeMap;
    EPacMan *PacMan;
    EGhosts *GhostRed;
    QTimer *Delay;
    QTimer *collisionTimer;
    //Barriers *Pared;
    void keyPressEvent(QKeyEvent *evento);
    void EvalueCollision();

    QList<Barriers*>Paredes;

};

#endif // WIDGET_H
