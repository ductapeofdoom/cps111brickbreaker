/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *gamewindow.cpp - this file contains method definitions for the
 *                 GameWindow, GameWidget, GUIPaddle, GUIBrick, and GUIBall clases.
 */

#include "gamewindow.h"
#include "gameobject.h"
#include "gameworld.h"
#include "highscore.h"
#include "ui_gamewindow.h"
#include "mainwindow.h"
#include "savemanager.h"

#include <QPropertyAnimation>
#include <QKeyEvent>
#include <QtWidgets>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QMessageBox>
#include <QSound>

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;


//Constructor for the GUI. Creates and sets animTimer and spawns the ball and paddle in the game widget.
GameWindow::GameWindow(QSound * newmusic, QWidget *parent) :
    QWidget(parent),
    gameui(new Ui::GameWindow),
    music(newmusic)
{
    gameui->setupUi(this);
    cyclecount = 0;
    collisioncount = 0;
    animTimer = new QTimer(this);
    animTimer->setInterval(1);
    connect(animTimer, &QTimer::timeout, this, &GameWindow::animTimerHit);
    network = false;
    setMouseTracking(true);
    wdGame = new GameWidget(this);
    hit = new QSound(":/sounds/click.wav");
}

void GameWindow::stopTimer()
{
    animTimer->stop();
}

void GameWindow::startTimer()
{
    animTimer->start();
}

//Animates <obj> and hides bricks that have been destroyed.
void GameWindow::Update(QObject * obj)
{
    GUIBall * ball = dynamic_cast<GUIBall*>(obj);
    if (ball != NULL){
        animationBall->setDuration(10);
        animationBall->setStartValue(QRect(ball->x(), ball->y(), 20, 20));
        animationBall->setEndValue(QRect(ball->getBall()->getX(),ball->getBall()->getY(),20,20));
        animationBall->start();
    }
    GUIPaddle * paddle = dynamic_cast<GUIPaddle*>(obj);
    if (paddle != NULL){
        animationPaddle->setDuration(10);
        animationPaddle->setStartValue(QRect(paddle->x(), paddle->y(), 120, 20));
        animationPaddle->setEndValue(QRect(paddle->getPaddle()->getX(), paddle->getPaddle()->getY(), 120, 20));
        animationPaddle->start();
    }
    int i = 0;
    for (size_t j = 0; j < GUIObjects.size(); j++){
        GUIBrick * brick  = dynamic_cast<GUIBrick*>(GUIObjects.at(i));
        if (brick != NULL){
            if(brick->getBrick()->getDestory()){
                if (network){
                    animTimer->stop();
                    QString brickId = "DESTROY:" + QString::number(brick->getBrick()->getId()) + "\n";
                    socket->write(brickId.toLocal8Bit());
                    animTimer->start();
                }
                qDebug() << brick->getBrick()->getId() << " destroyed";
                GameWorld::accessWorld().deleteObject(brick->getBrick()->getId());
                this->getGUIObjects().erase(this->getGUIObjects().begin() + i);
                brick->hide();

            }
        }
        i++;
    }
    //This method has a very odd bug resulting in the last object being used twice.
    /*for(QWidget * obj : GUIObjects){
        GUIBrick * brick  = dynamic_cast<GUIBrick*>(obj);
        if (brick != NULL){
            if(brick->getBrick()->getDestory()){
                hit->play();
                if (network){
                    animTimer->stop();
                    QString brickId = "DESTROY:" + QString::number(brick->getBrick()->getId()) + "\n";
                    socket->write(brickId.toLocal8Bit());
                    animTimer->start();
                }
                qDebug() << brick->getBrick()->getId() << " destroyed";
                GameWorld::accessWorld().deleteObject(brick->getBrick()->getId());
                this->getGUIObjects().erase(this->getGUIObjects().begin() + i);
                brick->hide();

            }
        }
        i++;
    }*/
}

void GameWindow::turnNoDeathButtonOn()
{
    gameui->btnNoDeath->setChecked(true);
}

void GameWindow::turnSlowBallButtonOn()
{
    gameui->btnSlowBall->setChecked(true);
}

void GameWindow::turnSpeedBallButtonOn()
{
    gameui->btnSpeedBall->setChecked(true);
}

//Slot implementaion for animTimerHit. Redraws the paddle and executes Update every 10 cycles. It will also reset animation and stop the timer if the ball goes off the bottom.
void GameWindow::animTimerHit(){
    GUIPaddle * paddle = dynamic_cast<GUIPaddle *>(GUIObjects.at(0));
    GUIBall * ball = dynamic_cast<GUIBall *>(GUIObjects.at(1));
    if(GameWorld::accessWorld().update()){
        if (cyclecount == 10){
            Update(paddle);
            Update(ball);
            showStuff();
            cyclecount = 0;
        }
        else if (collisioncount == 2){
            if (ball->getBall()->getCollision()){
                ball->getBall()->setCollision(false);
                hit->play();
            }
            cyclecount++;
            collisioncount = 0;
        }
        else{
            cyclecount++;
            collisioncount++;
        }
        if(ball->getBall()->getInitalPos()){
            Update(ball);
            paddle->setInitialCommand(true);
            showStuff();
            animTimer->stop();
        }
    }
    else{
        if (network){
            showStuff();
            animTimer->stop();
            QString playerScore = "SCORE:" + GameWorld::accessWorld().getName() + ":" + QString::number(GameWorld::accessWorld().getCurrentScore()) + "\n";
            socket->write(playerScore.toLocal8Bit());
        }
        else{
            gameui->btnSlowBall->setChecked(false);
            gameui->btnSlowBall->setEnabled(true);
            gameui->btnSpeedBall->setChecked(false);
            gameui->btnSpeedBall->setEnabled(true);
            gameui->btnNoDeath->setChecked(false);
            showStuff();
            animTimer->stop();
            if (GameWorld::accessWorld().getLife() != 0){
                GameWorld::accessWorld().incrementLevel(1);
                qDebug() << "incremented level.";
            }
            //QString msg1, msg2;
            //player has lost all their lives
            if (GameWorld::accessWorld().getLife() == 0 || GameWorld::accessWorld().getLevel() == 30){
                Score * playerScore =  new Score(GameWorld::accessWorld().getCurrentScore(), GameWorld::accessWorld().getName());
                HighScoreManager::accessManager().addScore(playerScore);
                GUIObjects.erase(GUIObjects.begin(), GUIObjects.end());

                //notify the player that they have died
                //give them the option to play the level over or go to the main menu.
                QMessageBox msgBox;
                if (GameWorld::accessWorld().getLife() == 0){
                    msgBox.setText("Unfortunately you have run out of lives.");
                    msgBox.setInformativeText("Would you like to play the game again?");
                }
                else if (GameWorld::accessWorld().getLevel() == 30){
                    msgBox.setText("Congratulation, you have finished the game!");
                    msgBox.setInformativeText("Would you like to play the game again?");
                }
                GameWorld::accessWorld().reset();
                GameWorld::accessWorld().setCurrentScore(0);
                GameWorld::accessWorld().setLevel(1);
                GameWorld::accessWorld().setLife(5);
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);
                int choice = msgBox.exec();

                switch (choice) {
                  case QMessageBox::Yes:
                {
                      delete wdGame;
                      delete animationBall;
                      delete animationPaddle;
                      wdGame = new GameWidget(this);
                      wdGame->show();
                      GameWorld::accessWorld().makeLevel();
                      this->renderLevel();
                      break;
                }
                  case QMessageBox::No:
                {
                      this->close();
                      break;
                }
                  default:
                      // should never be reached
                      break;
                }
            }

            //player has destroyed all the bricks
            else if (GameWorld::accessWorld().getRemainingBricks() == 0){

                GameWorld::accessWorld().setCurrentScore(GameWorld::accessWorld().getCurrentScore());

                GameWorld::accessWorld().reset();

                GUIObjects.erase(GUIObjects.begin(), GUIObjects.end());

                QMessageBox msgBox;
                msgBox.setText("You beat the level!");
                msgBox.setInformativeText("Would you like to play the next level?");
                msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
                msgBox.setDefaultButton(QMessageBox::Yes);
                int choice = msgBox.exec();

                switch (choice) {
                  case QMessageBox::Yes:
                {
                      delete wdGame;
                      delete animationBall;
                      delete animationPaddle;
                      wdGame = new GameWidget(this);
                      wdGame->show();
                      GameWorld::accessWorld().makeLevel();
                      this->renderLevel();
                      break;
                }
                  case QMessageBox::No:
                {
                      Score * playerScore =  new Score(GameWorld::accessWorld().getCurrentScore(), GameWorld::accessWorld().getName());
                      HighScoreManager::accessManager().addScore(playerScore);
                      this->close();
                      break;
                }
                  default:
                      // should never be reached
                      break;
                }
            }
        }
    }
    //QCoreApplication::processEvents();
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
    delete animationBall;
    delete animationPaddle;
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
            GUIBrick *newGUIBrick = new GUIBrick(wdGame, tempbrick);
            newGUIBrick->show();
            GameWindow::addObject(newGUIBrick);
        }
    }
    qDebug() << "made GUIBricks for level. GUIObjects vector is this big: " << GUIObjects.size();
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
    else if (GameWorld::accessWorld().getDifficulty() == 3){
        difficults = "Multiplayer";
    }
    gameui->lblDifficult->setText(difficults);

    //Stuff that needs to be put in QTimer/QThread
    QString Highscore = "";
    //Ball* theBall = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
    Highscore = QString::number(GameWorld::accessWorld().getCurrentScore());
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
    GUIPaddle * paddle = new GUIPaddle(wdGame, dataPaddle, this);
    wdGame->setPaddle(paddle);
    Ball * dataBall = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
    GUIBall * ball = new GUIBall(wdGame, dataBall);
    animationBall = new QPropertyAnimation(ball, "geometry");
    animationPaddle = new QPropertyAnimation(paddle, "geometry");
    addObject(paddle);
    addObject(ball);
    //set defaults
    ball->show();
    paddle->show();
    this->showStuff();
}

void GameWindow::closeEvent(QCloseEvent * ev)
{
    if (ev != NULL){
        music->play();
        animTimer->stop();
        GameWorld::accessWorld().reset();
        GameWorld::accessWorld().setCurrentScore(0);
        GameWorld::accessWorld().setLife(5);
        GameWorld::accessWorld().setLevel(1);
        GUIObjects.erase(GUIObjects.begin(), GUIObjects.end());
        HighScoreManager::accessManager().saveHS(".highscore.txt");
    }
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


void GameWindow::on_btnNoDeath_clicked()
{
    if (!gameui->btnNoDeath->isChecked()){
        GameWorld::accessWorld().setnoDeath(false);
    }
    else{
         GameWorld::accessWorld().setnoDeath(true);
    }
}

void GameWindow::on_btnSlowBall_clicked()
{
    if (!gameui->btnSlowBall->isChecked()){
        GameWorld::accessWorld().setSlowBall(false);
        gameui->btnSpeedBall->setEnabled(true);
    }
    else{
        GameWorld::accessWorld().setSlowBall(true);
        gameui->btnSpeedBall->setEnabled(false);
    }
}

void GameWindow::on_btnSpeedBall_clicked()
{
    if (!gameui->btnSpeedBall->isChecked()){
        GameWorld::accessWorld().setSpeedBall(false);
        gameui->btnSlowBall->setEnabled(true);
    }
    else{
        GameWorld::accessWorld().setSpeedBall(true);
        gameui->btnSlowBall->setEnabled(false);
    }
}

void GameWindow::on_btnAddLife_clicked()
{
    GameWorld::accessWorld().setLife(GameWorld::accessWorld().getLife() + 1);
    showStuff();
}


void GameWindow::on_btnSave_clicked()
{
    //eliminate the possiblity of double clicking the button
    gameui->btnSave->setEnabled(false);

    //create save manager, save the game, then delete the pointer to the save manager
    SaveManager * saver = new SaveManager(this, music);
    saver->SaveGame();
    delete saver;

    //reenable the save game button
    gameui->btnSave->setEnabled(true);
}


GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setGeometry(QRect(30,30,400,500));
    setStyleSheet("background-color:black;");
    setFocusPolicy(Qt::StrongFocus);
}

void GameWidget::mouseMoveEvent(QMouseEvent *event)
{
    int initX = paddle->getPaddle()->getX() + 60;
    GameWindow * parent = dynamic_cast<GameWindow*>(parentWidget());

    int testX = event->x();
    if (testX >= 0 && testX <= 280){
        paddle->getPaddle()->setX(testX);
    }

    if(paddle->getInitialCommand()){
        parent->getTimer()->start();
        if (paddle->getPaddle()->getX() + 60 >= initX){
            paddle->getPaddle()->setInitialRight(true);
        }
        else{
            paddle->getPaddle()->setInitialLeft(true);
        }
        paddle->setInitialCommand(false);
    }
}

void GameWidget::mousePressEvent(QMouseEvent *event)
{
    offsetX = event->x();
    offsetY = event->y();
}
