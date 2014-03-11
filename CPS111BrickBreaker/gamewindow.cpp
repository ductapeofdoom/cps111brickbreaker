#include "gamewindow.h"
#include "gameobject.h"
#include "gameworld.h"
#include "highscore.h"
#include "ui_gamewindow.h"

#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QtWidgets>
#include <QDebug>
#include <cassert>

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
    animTimer = new QTimer(this);
    animTimer->setInterval(1);
    connect(animTimer, &QTimer::timeout, this, &GameWindow::animTimerHit);
    Paddle * dataPaddle = new Paddle(150, 450);
    GUIPaddle * paddle = new GUIPaddle(gameui->wdGame, dataPaddle, this);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle);
    GUIBall * ball = new GUIBall(gameui->wdGame, dataBall);
    ball->show();
    paddle->show();
    this->showStuff();
}

//Animates <obj>. Designed specifically to move the ball from it currents coordinates to its next ones.
void Animate(QObject * obj){
    GUIBall * ball = dynamic_cast<GUIBall*>(obj);
    if (ball != NULL){
        QPropertyAnimation * animation = new QPropertyAnimation(obj, "geometry");
        animation->setDuration(1);
        animation->setStartValue(QRect(ball->x(), ball->y(), 20, 20));
        animation->setEndValue(QRect(ball->getBall()->getX(),ball->getBall()->getY(),20,20));
        animation->start();
    }
    GUIPaddle * paddle = dynamic_cast<GUIPaddle*>(obj);
    if (paddle != NULL){
        QPropertyAnimation * animation = new QPropertyAnimation(obj, "geometry");
        animation->setDuration(1);
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
    else{
        cyclecount++;
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

//add or subtract lives when ball hits bottom
//takes in a negative (when dies) or positive number when he gets pluslife powerup
void GameWindow::setLife(int j){
    life += j;
}

//create GUIBricks for a level
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
    //gameui->lblCHS->setText(GameWorld::accessWorld().);
    QString difficults;
    if (GameWorld::accessWorld().getDifficulty() == 0) {
        difficults = "Easy";
    } else if (GameWorld::accessWorld().getDifficulty() == 1){
        difficults = "Medium";
    } else if (GameWorld::accessWorld().getDifficulty() == 2) {
        difficults = "Hard";}
    gameui->lblDifficult->setText(difficults);
    //gameui->lblLife->setText(Gameworld::accessWorld().___);
    //gameui.lblLevel->setText();
    //gameui->lblPowerup->setText(Gameworld::accessWorld().___);
    //gameui->lblPowerTime->setText(Gameworld::accessWorld().___);


}

void GameWindow::on_btnPause_clicked()
{
    if (!gameui->btnPause->isChecked()){
        animTimer->start();
    }
    else{
        animTimer->stop();
    }
}
void GUIUnitTests()
{
    /*Test 1*/
    Brick *brick1 = new Brick(1, 0, 0, 0);
    Brick *brick2 = new Brick(1, 1, 40, 0);
    Brick *brick3 = new Brick(1, 2, 80, 0);
    Brick *brick4 = new Brick(1, 3, 120, 0);
    Brick *brick5 = new Brick(1, 4, 160, 0);
    GameWorld::accessWorld().addObject(brick1);
    GameWorld::accessWorld().addObject(brick2);
    GameWorld::accessWorld().addObject(brick3);
    GameWorld::accessWorld().addObject(brick4);
    GameWorld::accessWorld().addObject(brick5);
    GameWindow *testgamewindow = new GameWindow();
    testgamewindow->renderLevel();
    GUIBrick *tempbrick = testgamewindow->getGUIBricks().at(3);
    assert(tempbrick->getXValue() == 120);
    delete testgamewindow;
    delete brick1;
    delete brick2;
    delete brick3;
    delete brick4;
    delete brick5;
    /*end test 1*/
    /*more tests?*/
}
