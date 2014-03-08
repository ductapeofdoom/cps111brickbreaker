#include "gamewindow.h"
#include "gameobject.h"
#include "ui_gamewindow.h"
#include <QPropertyAnimation>
#include <QKeyEvent>

//Constructor for the GUI. Creates and sets animTimer and spawns the ball and paddle in the game widget.
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    gameui(new Ui::GameWindow)
{
    gameui->setupUi(this);
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
}

/*GameWindow *GameWindow::getUi()
{
    return gameui;
}*/

//Animates <obj>. Designed specifically to move the ball from it currents coordinates to its next ones.
void Animate(QObject * obj){
    GUIBall * ball = dynamic_cast<GUIBall*>(obj);
    QPropertyAnimation * animation = new QPropertyAnimation(obj, "geometry");
    animation->setDuration(1);
    animation->setStartValue(QRect(ball->x(), ball->y(), 20, 20));
    animation->setEndValue(QRect(ball->getBall()->getX(),ball->getBall()->getY(),20,20));
    animation->start();
}

//Slot implementaion for animTimerHit. Redraws the paddle and executes Animation every 10 cycles. It will also reset animation and stop the timer if the ball goes off the bottom.
void GameWindow::animTimerHit(){
    GUIPaddle * paddle = dynamic_cast<GUIPaddle *>(gameui->wdGame->children().at(0));
    paddle->setGeometry(QRect(paddle->getPaddle()->getX(), paddle->getPaddle()->getY(), 120, 20));
    GUIBall * ball = dynamic_cast<GUIBall *>(gameui->wdGame->children().at(1));
    ball->getBall()->updatePosition();
    if (cyclecount == 10){
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
    //ball->hide();
    //ball->setGeometry(QRect(ball->getBall()->getX(), ball->getBall()->getY(), 20, 20));
    //ball->show();
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

//Checks if the paddle has collided with the right side of the screen
bool Paddle::checkCollisionRight()
{
    if (x >= 280){
        return true;
    }
    else{
        return false;
    }
}

//Checks to see if the paddle has collided with the left side of the screen
bool Paddle::checkCollisionLeft()
{
    if (x <= 0){
        return true;
    }
    else{
        return false;
    }
}

void Paddle::saveState()
{

}

//Checks for the ball's collision and sets its headings accordingly. If the ball has gone off the bottom of the screen the ball is reset to the center of the paddle.
void Ball::checkCollision()
{
    if (x <= 0){
        xHeading = -1 * xHeading;
    }
    else if (y <= 0){
        yHeading = -1 * yHeading;
    }
    else if (x >= 380) {
        xHeading = -1 * xHeading;
    }
    else if (y >= 500){
        yHeading = 0;
        xHeading = 0;
        x = paddle->getX() + 50;
        y = paddle->getY() - 20;
        initialPos = true;
    }
    else if ((x >= paddle->getX() - 20 && x <= paddle->getX() + 120) && (y >= paddle->getY() - 20 && y <= paddle->getY() + 20)){
        //int testX = paddle->getX();
        //int testY = paddle->getY();
        if (((x+20 >= paddle->getX() - 20 && x >= paddle->getX() - 20 && x+20 <= paddle->getX() && x <= paddle->getX()) && y >= paddle->getY() - 20 && y <= paddle->getY() + 20) ||
                ((x+20 <= paddle->getX() + 140 && x <= paddle->getX() + 140 && x+20 >= paddle->getX() + 120 && x >= paddle->getX() + 120) && y >= paddle->getY() - 20 && y <=paddle->getY() + 20)){
            xHeading = -1 * xHeading;
        }
        else{
            yHeading = -1 * yHeading;
        }
    }
}

//Updates the ball's x,y coordinates with its heading and sets it heading if the ball is sitting still.
void Ball::updatePosition()
{
    if (initialPos){
        if(paddle->getInitialLeft()){
            yHeading = .2;
            xHeading = -.5;
            paddle->setInitialLeft(false);
        }
        else if(paddle->getInitialRight()){
            yHeading = .2;
            xHeading = .5;
            paddle->setInitialRight(false);
        }
        initialPos = false;
    }
   checkCollision();
   x = x + xHeading;
   y = y + yHeading;
}

void Ball::saveState()
{

}

//GameWindow destructor
GameWindow::~GameWindow()
{
    delete gameui;
}

