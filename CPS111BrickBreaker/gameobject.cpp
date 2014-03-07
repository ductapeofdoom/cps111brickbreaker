#include "gameobject.h"
#include "gamewindow.h"
#include <cassert>

//Units tests for ball collision detection
void collisionUnitTests(){
    Paddle * testPaddle = new Paddle(100,100);
    Ball * testBall = new Ball(110, 80, 0, 0, testPaddle);
    testPaddle->setInitialRight(true);
    //Test 1
    testBall->updatePosition();
    assert(testBall->getXHeading() == .5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 110.5);
    assert(testBall->getY() == 79.8);
    //Test 2
    testBall->setX(220);
    testBall->setY(120);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 221.5);
    assert(testBall->getY() == 119.8);
    //Test 3
    testBall->setX(0);
    testBall->setY(20);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 1.5);
    assert(testBall->getY() == 19.8);
    //Test 4
    testBall->setX(50);
    testBall->setY(0);
    testBall->setYHeading(-1);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 51.5);
    assert(testBall->getY() == 1);
    //Test 5
    testBall->setX(480);
    testBall->setY(90);
    testBall->updatePosition();
    assert(testBall->getXHeading() == -1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 478.5);
    assert(testBall->getY() == 91);
    //Test 6
    testBall->setX(80);
    testBall->setY(500);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 0);
    assert(testBall->getYHeading() == 0);
    assert(testBall->getX() == 150);
    assert(testBall->getY() == 80);
}
