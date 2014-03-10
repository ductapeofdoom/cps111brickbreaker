#include "gameworld.h"
#include <QFile>

GameWorld::GameWorld(): playerName("") {}

//method to start and run a game
void GameWorld::runGame()
{
    //use threading to do this, cause this method will need to be constantly running
}

//method to render a level
void GameWorld::makeLevel()
{
    QString levelData, filePath = ":/documents/" + curLevel + ".txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        levelData = levelData + line;
    }

    file.close();

    //loop through the rows of Bricks
    for (int i = 0; i < GameWorld::getTotalNumBricks()/10; i++){

        //loop through the Bricks in a row
        for (int j = 0; j < 10; j++){
            //create Brick objects (find out how how to then create GUIBricks)
        }

    }

    //in this method, I can make the Brick objects for the world. However, I need to figure out a way to make the GUIBrick objects
    //that will need to be done in the GameWindow class probably, so I may need to read from the worldObjects vector in GameWorld
    //to look at the Brick objects in it
}

GameWorld GameWorld::worldInstance;




