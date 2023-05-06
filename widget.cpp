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

    PacMan = new EPacMan(124, 230, 14, 13, 2);
    MazeMap->addItem(PacMan);



    Paredes.push_back(new Barriers(12, 43, 224, 4));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(12, 287, 224, 4));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(12, 43, 4, 248));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(232, 43, 4, 248));
    MazeMap->addItem(Paredes.back());
//31
    Paredes.push_back(new Barriers(31, 62, 25, 17));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(191, 62, 25, 17));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(71, 62, 33, 17));
    MazeMap->addItem(Paredes.back());
    Paredes.push_back(new Barriers(143, 62, 33, 17));
    MazeMap->addItem(Paredes.back());
    /*Paredes.push_back(new Barriers(232, 43, 4, 248));
    MazeMap->addItem(Paredes.back());*/

}

Widget::~Widget()
{
    delete ui;

}

void Widget::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up){
        if (!EvalueCollision()){
            PacMan->MoveUp();
        }
        else{
            PacMan->MoveDown();
        }
    }
    else if (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down){
        if (!EvalueCollision()){
            PacMan->MoveDown();
        }
        else{
            PacMan->MoveUp();
        }
    }
    else if (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left){
        if (!EvalueCollision()){
            PacMan->MoveLeft();
        }
        else{
            PacMan->MoveRight();
        }
    }
    else if (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right){
        if (!EvalueCollision()){
            PacMan->MoveRight();
        }
        else{
            PacMan->MoveLeft();
        }
    }
}

bool Widget::EvalueCollision()
{
    QList<Barriers*>::Iterator it;
    for (it = Paredes.begin(); it != Paredes.end(); it++){

        if((*it)->collidesWithItem(PacMan)){
            return true;
        }
    }
    return false;
}



