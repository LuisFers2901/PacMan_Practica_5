#include "widget.h"
#include "ui_widget.h"

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
    MazeMap->setSceneRect(X, Y, 224, 288);
    PacMan = new EPacMan();
    MazeMap->addItem(PacMan);
    PacMan->setPos(100,100);


}

Widget::~Widget()
{
    delete ui;

}

void Widget::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key() == Qt::Key_W || evento->key() == Qt::Key_Up){
        PacMan->MoveUp();
    }
    else if (evento->key() == Qt::Key_S || evento->key() == Qt::Key_Down){
        PacMan->MoveDown();
    }
    else if (evento->key() == Qt::Key_A || evento->key() == Qt::Key_Left){
        PacMan->MoveLeft();
    }
    else if (evento->key() == Qt::Key_D || evento->key() == Qt::Key_Right){
        PacMan->MoveRight();
    }
}



