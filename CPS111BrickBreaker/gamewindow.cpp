#include "gamewindow.h"
#include "gameobject.h"
#include "gameworld.h"
#include "highscore.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"

#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QtWidgets>
#include <QDebug>
#include <cassert>
#include <QThread>

using namespace std;

//Constructor for the GUI. Creates and sets animTimer and spawns the ball and paddle in the game widget.
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    gameui(new Ui::GameWindow)
{
    gameui->setupUi(this);
    collisionUnitTests();
    //highScoreUnitTests();
    cyclecount = 0;
    collisioncount = 0;
    animTimer = new QTimer(this);
    animTimer->setInterval(1);
    connect(animTimer, &QTimer::timeout, this, &GameWindow::animTimerHit);
    Paddle * dataPaddle = new Paddle(150, 450);
    GUIPaddle * paddle = new GUIPaddle(gameui->wdGame, dataPaddle, this);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle);
    GUIBall * ball = new GUIBall(gameui->wdGame, dataBall);
    //set defaults
    dataBall->setDefaultScore();
    GameWorld::accessWorld().setDefaultLife();
    ball->show();
    paddle->show();
    this->showStuff();
}

//Animates <obj>. Designed specifically to move the ball from it currents coordinates to its next ones.
void Animate(QObject * obj){
    GUIBall * ball = dynamic_cast<GUIBall*>(obj);
    if (ball != NULL){
        QPropertyAnimation * animation = new QPropertyAnimation(obj, "geometry");
        animation->setDuration(10);
        animation->setStartValue(QRect(ball->x(), ball->y(), 20, 20));
        animation->setEndValue(QRect(ball->getBall()->getX(),ball->getBall()->getY(),20,20));
        animation->start();
    }
    GUIPaddle * paddle = dynamic_cast<GUIPaddle*>(obj);
    if (paddle != NULL){
        QPropertyAnimation * animation = new QPropertyAnimation(obj, "geometry");
        animation->setDuration(10);
        animation->setStartValue(QRect(paddle->x(), paddle->y(), 120, 20));
        animation->setEndValue(QRect(paddle->getPaddle()->getX(), paddle->getPaddle()->getY(), 120, 20));
        animation->start();
    }
}

//Slot implementaion for animTimerHit. Redraws the paddle and executes Animation every 10 cycles. It will also reset animation and stop the timer if the ball goes off the bottom.
void GameWindow::animTimerHit(){
    GUIPaddle * paddle = dynamic_cast<GUIPaddle *>(gameui->wdGame->children().at(0));
    GUIBall * ball = dynamic_cast<GUIBall *>(gameui->wdGame->children().at(1));
    ball->getBall()->updatePosition();
    if (cyclecount == 10){
        Animate(paddle);
        Animate(ball);
        cyclecount = 0;
    }
    else if (collisioncount == 2){
        if (ball->getBall()->getCollision()){
            ball->getBall()->setCollision(false);
        }
        cyclecount++;
        collisioncount = 0;
    }
    else{
        cyclecount++;
        collisioncount++;
    }
    if(ball->getBall()->getInitalPos()){
        Animate(ball);
        paddle->setInitialCommand(true);
        animTimer->stop();
    }
}

//Checks for the key press from <event> and sets the paddle's x coordinate and command state accordingly. InitialCommand is used for the first move of the game or when the ball has been reset.
void GUIPaddle::keyPressEvent(QKeyEvent *event)
{
    int keyPress = event->key();
        if (keyPress == Qt::Key_Right){
            if(initialCommand){
                window->getTimer()->start();
                paddle->setInitialRight(true);
                initialCommand = false;
            }
            if(!paddle->checkCollisionRight()){
                paddle->setX(paddle->getX() + 10);
            }
        }
        else if(keyPress == Qt::Key_Left) {
            if(initialCommand){
                window->getTimer()->start();
                paddle->setInitialLeft(true);
                initialCommand = false;
            }

            if(!paddle->checkCollisionLeft()){
             paddle->setX(paddle->getX() - 10);
            }
        }
}

//GameWindow destructor
GameWindow::~GameWindow()
{
    delete gameui;
}



//create GUIBricks for a level
//***for each level starting from one, for every 3 levels, increase bricks hits +1 for random bricks
//***each difficulty, # of unbreakables
void GameWindow::renderLevel()
{
    for (GameObject *obj : GameWorld::accessWorld().getObjects()){
        Brick *tempbrick = dynamic_cast<Brick*>(obj);
        if (tempbrick == NULL){
            break;
        }
        GUIBrick *newGUIBrick = new GUIBrick(gameui->wdGame, tempbrick);
        GameWindow::addObject(newGUIBrick);
    }
}

//relabels everything in gameui
void GameWindow::showStuff(){
    gameui->lblCPN->setText(GameWorld::accessWorld().getName());
    //get high score from # of ball hits
    QString Highscore;
    for(GameObject * obj: GameWorld::accessWorld().getObjects()){
        Ball* theBall = dynamic_cast<Ball*>(obj);
        Highscore = QString::number(theBall->getHS());
    }
    gameui->lblCHS->setText(Highscore);
    QString difficults;
    if (GameWorld::accessWorld().getDifficulty() == 0) {
        difficults = "Easy";
    } else if (GameWorld::accessWorld().getDifficulty() == 1){
        difficults = "Medium";
    } else if (GameWorld::accessWorld().getDifficulty() == 2) {
        difficults = "Hard";}
    gameui->lblDifficult->setText(difficults);
    //change according to deaths
    gameui->lblLife->setText(QString::number(GameWorld::accessWorld().getLife()));
    gameui->lblLevel->setText(QString::number(GameWorld::accessWorld().getLevel()));
    //gameui->lblPowerup->setText(Gameworld::accessWorld().___);
    //gameui->lblPowerTime->setText(Gameworld::accessWorld().___);


}

void GameWindow::on_btnPause_clicked()
{
    if (!gameui->btnPause->isChecked()){
        animTimer->start();
        gameui->btnPause->setText("Pause");
    }
    else{
        animTimer->stop();
        gameui->btnPause->setText("Resume");
    }
}

