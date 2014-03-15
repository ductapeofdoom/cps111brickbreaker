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
#include <QString>
#include <QMessageBox>

using namespace std;


//Constructor for the GUI. Creates and sets animTimer and spawns the ball and paddle in the game widget.
GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    gameui(new Ui::GameWindow)
{
    gameui->setupUi(this);
    collisionUnitTests();
    highScoreUnitTests();
    cyclecount = 0;
    collisioncount = 0;
    animTimer = new QTimer(this);
    animTimer->setInterval(1);
    connect(animTimer, &QTimer::timeout, this, &GameWindow::animTimerHit);
}

//Animates <obj>. Designed specifically to move the ball from it currents coordinates to its next ones.
void Update(QObject * obj, GameWindow * window){
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
    int i = 0;
    for(QWidget * obj : window->getGUIObjects()){
        GUIBrick * brick  = dynamic_cast<GUIBrick*>(obj);
        if (brick != NULL){
            if(brick->getBrick()->getDestory()){
                qDebug() << brick->getBrick()->getId() << " destroyed";
                GameWorld::accessWorld().deleteObject(brick->getBrick()->getId());
                window->getGUIObjects().erase(window->getGUIObjects().begin() + i);
                brick->hide();
            }
        }
        i++;
    }
}

//Slot implementaion for animTimerHit. Redraws the paddle and executes Update every 10 cycles. It will also reset animation and stop the timer if the ball goes off the bottom.
void GameWindow::animTimerHit(){
    GUIPaddle * paddle = dynamic_cast<GUIPaddle *>(GUIObjects.at(0));
    GUIBall * ball = dynamic_cast<GUIBall *>(GUIObjects.at(1));
    if(GameWorld::accessWorld().update()){
        if (cyclecount == 10){
            Update(paddle, this);
            Update(ball, this);
            showStuff();
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
            Update(ball, this);
            paddle->setInitialCommand(true);
            showStuff();
            animTimer->stop();
        }
        /*for(GUIBrick * brick:this->getGUIBricks()){
            if(brick->getBrick()->getDestory()){
                brick->getBrick() = NULL;
            }
        }*/
    }
    else{
        showStuff();
        animTimer->stop();

        QString msg1, msg2;
        //player has lost all their lives
        if (GameWorld::accessWorld().getLife() == 0){
            GameWorld::accessWorld().reset();
            //notify the player that they have died
            //give them the option to play the level over or go to the main menu.
        }

        //player has destroyed all the bricks
        if (GameWorld::accessWorld().getRemainingBricks() == 0){

            GameWorld::accessWorld().reset();

            for (QWidget* obj : GameWindow::getGUIObjects()){
                delete obj;
            }
            GUIObjects.erase(GUIObjects.begin(), GUIObjects.end());

            QMessageBox msgBox;
            msgBox.setText("You beat the level!");
            msgBox.setInformativeText("Would you like to play the next level?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::Yes);
            int choice = msgBox.exec();

            switch (choice) {
              case QMessageBox::Yes:
                  GameWorld::accessWorld().incrementLevel(1);
                  qDebug() << "incremented level.";
                  GameWorld::accessWorld().makeLevel();
                  this->renderLevel();
                  break;
              case QMessageBox::No:
                  this->close();
                  break;
              default:
                  // should never be reached
                  break;
            }
        }

        /*QLabel * win = new QLabel(this);
        win->setText("You win!");
        win->setGeometry(QRect(250,250,500,500));
        win->setStyleSheet("color:rgb(255,0,0);");
        win->show();*/
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
    delete animTimer;
    delete gameui;
}



//create GUIBricks for a level
//***for each level starting from one, for every 3 levels, increase bricks hits +1 for random bricks
//***each difficulty, # of unbreakables
void GameWindow::renderLevel()
{
    GeneratePlayer();
    for (GameObject *obj : GameWorld::accessWorld().getObjects()){
        Brick *tempbrick = dynamic_cast<Brick*>(obj);
        if (tempbrick != NULL){
            GUIBrick *newGUIBrick = new GUIBrick(gameui->wdGame, tempbrick);
            newGUIBrick->show();
            GameWindow::addObject(newGUIBrick);
        }
    }
    qDebug() << "made GUIBricks for level. GUIBricks vector is this big: " << GUIObjects.size();
}

//relabels everything in gameui
void GameWindow::showStuff(){
    gameui->lblCPN->setText(GameWorld::accessWorld().getName());
    //get high score from # of ball hits
    QString difficults = "";
    if (GameWorld::accessWorld().getDifficulty() == 0) {
        difficults = "Easy";
    } else if (GameWorld::accessWorld().getDifficulty() == 1){
        difficults = "Medium";
    } else if (GameWorld::accessWorld().getDifficulty() == 2) {
        difficults = "Hard";}
    gameui->lblDifficult->setText(difficults);

    //Stuff that needs to be put in QTimer/QThread
    QString Highscore = "";
    Ball* theBall = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
    Highscore = QString::number(theBall->getHS());
    gameui->lblCHS->setText(Highscore);
    //change according to deaths
    gameui->lblLife->setText(QString::number(GameWorld::accessWorld().getLife()));
    gameui->lblLevel->setText(QString::number(GameWorld::accessWorld().getLevel()));
    //gameui->lblPowerup->setText(Gameworld::accessWorld().___);
    //gameui->lblPowerTime->setText(Gameworld::accessWorld().___);


}

void GameWindow::GeneratePlayer()
{
    Paddle * dataPaddle = dynamic_cast<Paddle*>(GameWorld::accessWorld().getObjects().at(0));
    GUIPaddle * paddle = new GUIPaddle(gameui->wdGame, dataPaddle, this);
    Ball * dataBall = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
    GUIBall * ball = new GUIBall(gameui->wdGame, dataBall);
    addObject(paddle);
    addObject(ball);
    //set defaults
    dataBall->setDefaultScore();
    GameWorld::accessWorld().setDefaultLife();
    ball->show();
    paddle->show();
    this->showStuff();
}

void GameWindow::closeEvent(QCloseEvent * ev)
{
    animTimer->stop();
    GameWorld::accessWorld().reset();
    GUIObjects.erase(GUIObjects.begin(), GUIObjects.end());
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

