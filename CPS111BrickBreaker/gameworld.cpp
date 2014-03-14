#include "gameworld.h"
#include "gameobject.h"
#include <QFile>
#include <QDebug>

GameWorld::GameWorld(): playerName("") {}

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

bool GameWorld::update()
{
    Ball * ball = dynamic_cast<Ball*>(worldObjects.at(1));
    ball->updatePosition();
    if (worldObjects.size() == 2){
        return false;
    }
    return true;
}

void GameWorld::reset()
{
    worldObjects.erase(worldObjects.begin(), worldObjects.end());
}

int GameWorld::totalNumBricks = 60;//sets the total number of bricks that each level will have in it.
//this needs to correspond to the number of entries in each leveldata text document.

//method to render a level
void GameWorld::makeLevel()
{
    //Adds the ball and paddle GameWorld
    Paddle * dataPaddle = new Paddle(150, 450, 1);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle, 2);
    GameWorld::accessWorld().addObject(dataPaddle);
    GameWorld::accessWorld().addObject(dataBall);

    QString levelData, filePath = ":/documents/" + QString::number(curLevel + 1) + ".txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
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

    //in this method, I can make the Brick objects for the world. However, I need to figure out a way to make the GUIBrick objects
    //that will need to be done in the GameWindow class probably, so I may need to read from the worldObjects vector in GameWorld
    //to look at the Brick objects in it
}

GameWorld GameWorld::worldInstance;




