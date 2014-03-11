#include "gameworld.h"
#include <QFile>
#include <QDebug>

GameWorld::GameWorld(): playerName("") {}

int GameWorld::totalNumBricks = 60;//sets the total number of bricks that each level will have in it.
//this needs to correspond to the number of entries in each leveldata text document.

//method to render a level
void GameWorld::makeLevel()
{
    QString levelData, filePath = ":/documents/" + QString::number(curLevel + 1) + ".txt";
    qDebug() << filePath;
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

    //loop through the rows of Bricks
    for (int i = 0; i < GameWorld::getTotalNumBricks()/10; i++){

        //loop through the Bricks in a row
        for (int j = 0; j < 10; j++){
            QString singleBrickData = levelData.at(count);

            Brick *newbrick = new Brick(singleBrickData.toInt(), count, j * 40, i * 20);
            GameWorld::accessWorld().addObject(newbrick);

            count++;
        }

    }

    //in this method, I can make the Brick objects for the world. However, I need to figure out a way to make the GUIBrick objects
    //that will need to be done in the GameWindow class probably, so I may need to read from the worldObjects vector in GameWorld
    //to look at the Brick objects in it
}

GameWorld GameWorld::worldInstance;




