#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>
#include "gameobject.h"
using namespace std;

class GameWorld
{
    vector<GameObject*> worldObjects;
public:
    GameWorld();

    void addObject(GameObject * newObject){ worldObjects.push_back(newObject);}

    void deleteObject(int id);

     //Getter methdod
    vector<GameObject*> getObjects() {return worldObjects;}
};

#endif // GAMEWORLD_H
