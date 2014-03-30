/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *gameworld.cpp - this file contains method definitions for the
 *                GameWorld class.
 */

#include "gameworld.h"
#include "gameobject.h"
#include <QFile>
#include <QDebug>

GameWorld::GameWorld(): playerName(""), curLevel(1), life(5), curScore(0), noDeath(false), speedBall(false), slowBall(false) {
}

GameWorld::~GameWorld()
{
    for(GameObject * obj : worldObjects){
        delete obj;
    }
    worldObjects.erase(worldObjects.begin(), worldObjects.end());
}

void GameWorld::deleteObject(int id)
{
    int i = 0;
    for(GameObject * obj: worldObjects){
        if (obj->getId() == id){
            worldObjects.erase(worldObjects.begin() + i);
            delete obj;
        }
        i++;
    }
}

GameObject * GameWorld::getObjectById(int id)
{
    int i = 0;
    for(GameObject * obj: worldObjects){
        if (obj->getId() == id){
            return obj;
        }
        i++;
    }
    return NULL;
}

bool GameWorld::update()
{
    Ball * ball = dynamic_cast<Ball*>(worldObjects.at(1));
    ball->updatePosition();
    Paddle * paddle = dynamic_cast<Paddle*>(worldObjects.at(0));
    paddle->CheckBallCollision();
    if (worldObjects.size() == 2 || life == 0 || curLevel == 10){
        return false;
    }
    return true;
}

void GameWorld::reset()
{
    noDeath = false;
    speedBall = false;
    slowBall = false;
    for(GameObject * obj : worldObjects){
        delete obj;
    }
    worldObjects.erase(worldObjects.begin(), worldObjects.end());
}

//method to render a level
void GameWorld::makeLevel()
{
    //totalNumBricks does need to be set to a multiple of 10.
    if (difficulty == 0){
        totalNumBricks = 20;
    }
    else if (difficulty == 1){
        totalNumBricks = 40;
    }
    else if (difficulty == 2){
        totalNumBricks = 60;
    }

    //Add the ball and paddle to GameWorld
    Paddle * dataPaddle = new Paddle(150, 450, 1);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle, 2);
    GameWorld::accessWorld().addObject(dataPaddle);
    GameWorld::accessWorld().addObject(dataBall);

    QString levelData, filePath = ":/documents/" + QString::number(curLevel) + ".txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //not too concerned about having an error opening a resource
        return;
    }

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        levelData = levelData + line;
    }

    file.close();

    int count = 0;
    int idCounter = 3;

    //loop through the rows of Bricks
    for (int i = 0; i < GameWorld::getTotalNumBricks()/10; i++){

        //loop through the Bricks in a row
        for (int j = 0; j < 10; j++){
            QString singleBrickData = levelData.at(count);

            Brick *newbrick = new Brick(singleBrickData.toInt(), idCounter, j * 40, i * 20);
            GameWorld::accessWorld().addObject(newbrick);

            count++;
            idCounter++;
        }

    }
    qDebug() << "made Bricks for new level";
}

//counts the remaining bricks in the game
int GameWorld::getRemainingBricks()
{
    int count = 0;
    for (GameObject* obj : worldObjects){
        if (dynamic_cast<Brick*>(obj) != NULL){
            count++;
        }
    }
    return count;
}

GameWorld GameWorld::worldInstance;




