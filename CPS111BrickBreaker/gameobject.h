#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

<<<<<<< HEAD
#include <QString>
using namespace std;

=======
//Abstract class that contains a set of x,y coordinated and and object id.
>>>>>>> fb9ed0559aeaccd501d3ac48e433db35a57d70ea
class GameObject
{
protected:
        double x, y;


public:
        GameObject(double newX,double newY): x(newX), y(newY){}

    //Getter methods
    int getX(){return x;}
    int getY(){return y;}

    //Setter methods
    void setX(int newX){x = newX;}
    void setY(int newY){y = newY;}
};

//Data class for the bricks
class Brick : public GameObject {
    int hits, hitCounter;
    QString color;
public:
    //Method for incrementing hit counter and check for destruction
    void hit();

    //Method for destroying bricks
    void destroy();

};

//Data class for the paddle
class Paddle : public GameObject{

private:
    bool initialLeft, initialRight;
public:
    explicit Paddle(double newX, double newY): GameObject(newX, newY), initialLeft(false), initialRight(false){}

    //Method used for collision detection on the right side of the screen
    bool checkCollisionRight();

    //Method used for collision detection on the left side of the screen
    bool checkCollisionLeft();

    //Getter methods
    int getx() {return x;}
    int gety() {return y;}
    bool getInitialLeft(){return initialLeft;}
    bool getInitialRight(){return initialRight;}

    //Setter methods
    void setx(int newX) {x = newX;}
    void sety(int newY) {y = newY;}
    void setInitialRight(bool value){initialRight = value;}
    void setInitialLeft(bool value){initialLeft = value;}
};

//Data class for the ball
class Ball : public GameObject {

private:
    double x, y, xHeading, yHeading;
    Paddle * paddle;
    bool initialPos;
public:
    explicit Ball(double newX, double newY, double newXHeading, double newYHeading, Paddle * newPaddle): GameObject(newX, newY), xHeading(newXHeading), yHeading(newYHeading), paddle(newPaddle), initialPos(true){}

    //Method used for ball collision detection
    void checkCollision();

    //Method used to update the ball's x,y coordinates
    void updatePosition();

    //Getter methods
    double getx() {return x;}
    double gety() {return y;}
    double getXHeading() {return xHeading;}
    double getYHeading() {return yHeading;}
    bool getInitalPos() {return initialPos;}

    //Setter methods
    void setx(double newX) {x = newX;}
    void sety(double newY) {y = newY;}
    void setXHeading(double heading){xHeading = heading;}
    void setYHeading(double heading){yHeading = heading;}
};

//Data class for power ups
class PowerUp : public GameObject{

public:

};

#endif // GAMEOBJECT_H
