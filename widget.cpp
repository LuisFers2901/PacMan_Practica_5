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

//    Delay->start(18);

   // connect(Delay, &QTimer::timeout, this, &EPacMan::);

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

    PointCounter = new QLabel("HIGH SCORE\n0",nullptr);
    PointCounter->setGeometry(75, 5, 100, 34);
    PointCounter->setStyleSheet("color: white;"
                                "font-weight: bold;"
                                "background-color: transparent;"
                                "font-size: 15px;");
    PointCounter->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    MazeMap->addWidget(PointCounter);

    ListLifesMap.SpecialBarriers();
    for (auto lifes : ListLifesMap.Lifes) {
        MazeMap->addItem(lifes);
    }

    ListBarriersMap.BarriersMap();
    for (auto barrier : ListBarriersMap.Paredes) {
        MazeMap->addItem(barrier);
    }

    ListPowerUps.PowerUp();
    for (auto power : ListPowerUps.PowerUps) {
        MazeMap->addItem(power);
    }

    ListFoodMap.FoodsMap();
    for (auto food : ListFoodMap.Food) {
        MazeMap->addItem(food);
    }

    ListPortalsMap.SpecialBarriers();

    PacMan = new Entities(124, 231, 14, 13, 1, 1, 65, 18, nullptr);
    MazeMap->addItem(PacMan);

    Blinky = new Entities(124, 135, 14, 13, 1, 2, 65, 18, nullptr);
    MazeMap->addItem(Blinky);


    EntitiesPlay.push_back(Blinky);
    Pinky = new Entities(124, 158, 14, 13, 1, 3, 65, 18, nullptr);
    MazeMap->addItem(Pinky);
    EntitiesPlay.push_back(Pinky);
    Inky = new Entities(108, 158, 14, 13, 1, 4, 65, 18, nullptr);
    MazeMap->addItem(Inky);
    EntitiesPlay.push_back(Inky);
    Clyde = new Entities(140, 158, 14, 13, 1, 5, 65, 18, nullptr);
    MazeMap->addItem(Clyde);
    EntitiesPlay.push_back(Clyde);

//    FunctionsGhosts->ExitHouse(Pinky, 1, 0);
//    FunctionsGhosts->ExitHouse(Inky, 1, 1);
//    FunctionsGhosts->ExitHouse(Clyde, 1, 2);





    connect(PacMan->TimerMove, &QTimer::timeout, this, &Widget::EvalueCollision);
}

Widget::~Widget()
{
    delete ui;
    ListBarriersMap.~ListBarriers();
    delete PacMan;
    delete Blinky;
    delete Pinky;
    delete Inky;
    delete Clyde;

}

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

    for (auto barrier : ListBarriersMap.Paredes) {
        if(barrier->collidesWithItem(PacMan)){
            PacMan->StopEntity(Option);
        }
    }

    for (auto powerup : ListPowerUps.PowerUps) {
        if(powerup->collidesWithItem(PacMan)){
            Blinky->Sprite = 6;
            Pinky->Sprite = 6;
            Inky->Sprite = 6;
            Clyde->Sprite = 6;
        }
    }

    for (auto entity : EntitiesPlay) {
        if(entity->collidesWithItem(PacMan)){

            PacMan->Dead(Option);
            MazeMap->removeItem(Blinky);
            MazeMap->removeItem(Pinky);
            MazeMap->removeItem(Inky);
            MazeMap->removeItem(Clyde);
            PacMan->PosX = 124;
            PacMan->PosY = 231;
            PacMan->setPos(124, 231);
            Blinky->PosX = 124;
            Blinky->PosY = 135;
            Blinky->setPos(124, 135);
            Pinky->PosX = 124;
            Pinky->PosY = 158;
            Pinky->setPos(124, 158);
            Inky->PosX = 108;
            Inky->PosY = 158;
            Inky->setPos(108, 158);
            Clyde->PosX = 140;
            Clyde->PosY = 158;
            Clyde->setPos(140, 158);
            PacMan->Sprite = 1;
            PacMan->TimerMove->start(PacMan->TimerM);

            MazeMap->addItem(Blinky);
            MazeMap->addItem(Pinky);
            MazeMap->addItem(Inky);
            MazeMap->addItem(Clyde);
            MazeMap->removeItem(ListLifesMap.Lifes[Cont]);
            Cont--;
        }
    }
    Barriers * o;
    for(QList<Barriers*>::iterator i = ListFoodMap.Food.begin(); i!=ListFoodMap.Food.end(); i++){
        o = *i;
        if(o->collidesWithItem(PacMan)){
            MazeMap->removeItem(o);
            delete o;
            ListFoodMap.Food.erase(i);
            i--;
            Points += 10;
            Score = QString("HIGH SCORE\n%1").arg(Points);
            PointCounter->setText(Score);
        }
    }
    for(QList<Barriers*>::iterator i = ListPowerUps.PowerUps.begin(); i != ListPowerUps.PowerUps.end(); i++){
        o = *i;
        if(o->collidesWithItem(PacMan)){
            MazeMap->removeItem(o);
            delete o;
            ListPowerUps.PowerUps.erase(i);
            i--;
            Points += 50;
            Score = QString("HIGH SCORE\n%1").arg(Points);
            PointCounter->setText(Score);
        }
    }

    int Cont = 0;

    for (auto portal : ListPortalsMap.Portals) {
        Cont++;
        if(portal->collidesWithItem(PacMan)){
            if(Cont == 1){
                PacMan->PosX = 250;
                PacMan->PosY = 158;

            }
            else if(Cont == 2){
                PacMan->PosX = -5;
                PacMan->PosY = 158;
            }

        }
    }

}
