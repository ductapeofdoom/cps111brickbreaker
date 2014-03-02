#include <QString>
using namespace std;
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
        int id;
        int x, y;
        int speed;
        double direction;
        QString image;

public:
    GameObject();

    //Method for updating coordinates of the object
    virtual void updatePosition() = 0;

    //Method for checking for possible collision between objects
    virtual void checkCollision() = 0;

    //Getter methods
    int getId(){return id;}
    int getX(){return x;}
    int getY(){return y;}
    double getDirection(){return direction;}
    QString getImage(){return image;}

    //Setter methods
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
    void setDirection(int newDirection){direction = newDirection;}
    void setImage(QString newImage){image = newImage;}
};

class Brick : public GameObject {
    int hits;
    QString color;
public:
    void updatePosition();

    void checkCollision();

    //Method for destroying bricks
    void destroy();

};

class Paddle : public GameObject{

public:
    void updatePosition();

    void checkCollision();
};

class Ball : public GameObject {

public:
    void updatePosition();

    void checkCollision();
};

class PowerUp : public GameObject{

public:
    void updatePosition();

    void checkCollision();
};

#endif // GAMEOBJECT_H
