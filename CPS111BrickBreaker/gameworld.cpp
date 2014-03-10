#include "gameworld.h"

GameWorld::GameWorld(): playerName("") {}

//method to start and run a game
void GameWorld::runGame()
{
    //use threading to do this, cause this method will need to be constantly running
}

//method to render a level
void GameWorld::makeLevel()
{
    //need to figure out a way to store the data for the types and locations of bricks in each level

    //in this method, I can make the Brick objects for the world. However, I need to figure out a way to make the GUIBrick objects
    //that will need to be done in the GameWindow class probably, so I may need to read from the worldObjects vector in GameWorld
    //to look at the Brick objects in it
}

GameWorld GameWorld::worldInstance;




