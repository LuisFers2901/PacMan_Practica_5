#include "widget.h"
#include "ui_widget.h"
#include "barriers.h"
#include "epacman.h"

//Tamaño Mapa (224 x 248)

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    QScreen* primaryScreen = QApplication::primaryScreen();
    QRect DesktopSpecs = primaryScreen->geometry();
    X = DesktopSpecs.x();
    Y = DesktopSpecs.y();
    Width = DesktopSpecs.width();
    Height = DesktopSpecs.height();
    //showFullScreen();
    QPixmap IconFile(":/Images/icon.png");
    QIcon Icon(IconFile);

    QTimer *Delay = new QTimer();

    Option = 0;

    Delay->start(18);

    connect(Delay, &QTimer::timeout, this, &Widget::EvalueCollision);

    setWindowIcon(Icon);
    setWindowTitle("PacMan");
    setFixedSize(300, 350);
    setStyleSheet("background-image: url(:/Images/MapaVacio.png); "
                  "background-position: center; "
                  "background-repeat: no-repeat; "
                  "background-color: black;");

    MazeMap = new QGraphicsScene();
    ui->graphicsView->setScene(MazeMap);
    MazeMap->setSceneRect(X, Y, ui->graphicsView->width()-2, ui->graphicsView->height()-2);

    PacMan = new EPacMan(124, 231, 14, 13, 1);
    MazeMap->addItem(PacMan);
    GhostRed = new EGhosts(124, 140, 14, 13, 1);
    MazeMap->addItem(GhostRed);



    Paredes.push_back(new Barriers(12, 42, 224, 7));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(12, 286, 224, 4));
    MazeMap->addItem(Paredes.back());
    //lateral derecho
    Paredes.push_back(new Barriers(11, 42, 6, 109));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(11, 165, 6, 123));
    MazeMap->addItem(Paredes.back());
    //lateral izquierdo
    Paredes.push_back(new Barriers(232, 42, 4, 109));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(232, 165, 4, 123));
    MazeMap->addItem(Paredes.back());
    //portales
    Paredes.push_back(new Barriers(-25, 149, 4, 19));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(269, 149, 4, 19));
    MazeMap->addItem(Paredes.back());

    Paredes.push_back(new Barriers(31, 62, 26, 19));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(71, 62, 34, 19));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(143, 62, 34, 19));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 62, 26, 19));
    MazeMap->addItem(Paredes.back());
    //---
    Paredes.push_back(new Barriers(-25, 118, 82, 34));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 118, 82, 34));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(-25, 165, 82, 35));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 165, 82, 35));
    MazeMap->addItem(Paredes.back());

    Paredes.push_back(new Barriers(95, 142, 58, 3));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(95, 173, 58, 3));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(95, 142, 3, 31));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(150, 142, 3, 31));
    MazeMap->addItem(Paredes.back());


    Paredes.push_back(new Barriers(31, 94, 26, 11));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(95, 94, 58, 11));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 94, 25, 11));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(31, 213, 26, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(71, 213, 34, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(143, 213, 34, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 213, 26, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(15, 238, 18, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(215, 238, 18, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(95, 238, 58, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(71, 238, 10, 23));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(167, 238, 10, 23));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(31, 261, 74, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(143, 261, 74, 12));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(95, 190, 58, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(78, 118, 26, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(143, 118, 26, 10));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(119, 47, 10, 32));
    MazeMap->addItem(Paredes.back());
    //laterales verticales
    Paredes.push_back(new Barriers(71, 94, 10, 58));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(167, 94, 10, 58));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(71, 165, 10, 35));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(167, 165, 10, 35));
    MazeMap->addItem(Paredes.back());
    //mitad vertical
    Paredes.push_back(new Barriers(119, 103, 10, 25));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(119, 199, 10, 26));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(119, 248, 10, 25));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(47, 223, 10, 25));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 223, 10, 25));
    MazeMap->addItem(Paredes.back());/**/

}

Widget::~Widget()
{
    delete ui;

}

bool Colision = false;
void Widget::keyPressEvent(QKeyEvent *evento)
{

    if (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up){
        PacMan->MoveEntity(1);
        Option = 1;
    }
    else if (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down){
        PacMan->MoveEntity(2);
        Option = 2;
    }
    else if (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left){
        PacMan->MoveEntity(3);
        Option = 3;
    }
    else if (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right){
        PacMan->MoveEntity(4);
        Option = 4;
    }
}

void Widget::EvalueCollision()
{
    QList<Barriers*>::Iterator it;
    for (it = Paredes.begin(); it != Paredes.end(); it++){

        if((*it)->collidesWithItem(PacMan)){
            PacMan->StopEntity(Option);
        }
    }
}



