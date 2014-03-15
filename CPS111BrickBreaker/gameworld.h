#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>

#include <QString>
#include <QObject>
#include <QDebug>

#include "gameobject.h"
using namespace std;

class GameWorld : public QObject
{

    Q_OBJECT

private:
    GameWorld();
    vector<GameObject*> worldObjects;
    QString playerName;
    int difficulty, curLevel, life, curScore;
    static int totalNumBricks;
    static GameWorld worldInstance;

public:
    static GameWorld& accessWorld() { return worldInstance; }

    void addObject(GameObject * newObject){ worldObjects.push_back(newObject);}

    void deleteObject(int id);

    //Method to update state of all GameObjects
    bool update();

    void reset();

    void incrementScore(){curScore++;}

    void loseLife() {life--;}

    int getLevel() {return curLevel; }

    //method to create a level
    void makeLevel();

    //method to get total number of bricks that each level will have
    static int getTotalNumBricks() { return totalNumBricks; }

    //Getter methods
    vector<GameObject*> getObjects() {return worldObjects;}
    QString getName() { return playerName; }
    int getDifficulty() { return difficulty; }
    int getLife() {return life;}
    int getRemainingBricks();
    int getCurrentScore() {return curScore;}


    //Setter methods
    void setPlayerName(QString newName) { playerName = newName; }
    void setDifficulty(int newDiff) { difficulty = newDiff; }//0 = Easy    1 = Medium   2 = Hard
    void setLevel() {curLevel++;}
    void setCurrentScore(int newScore){curScore = newScore;}
    void loadLevel(int loadLevel) {curLevel = loadLevel;}
    void incrementLevel(int amount) { curLevel += amount; }

    //add or subtract lives when ball hits bottom
    //takes in a negative (when dies) or positive number when he gets pluslife powerup
    void setLife(int lifeChange) { life += lifeChange; }
};

#endif // GAMEWORLD_H
