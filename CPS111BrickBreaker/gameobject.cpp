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
    assert(testBall->getx() == 110.5);
    assert(testBall->gety() == 79.8);
    //Test 2
    testBall->setx(220);
    testBall->sety(120);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getx() == 221.5);
    assert(testBall->gety() == 119.8);
    //Test 3
    testBall->setx(0);
    testBall->sety(20);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getx() == 1.5);
    assert(testBall->gety() == 19.8);
    //Test 4
    testBall->setx(50);
    testBall->sety(0);
    testBall->setYHeading(-1);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getx() == 51.5);
    assert(testBall->gety() == 1);
    //Test 5
    testBall->setx(480);
    testBall->sety(90);
    testBall->updatePosition();
    assert(testBall->getXHeading() == -1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getx() == 478.5);
    assert(testBall->gety() == 91);
    //Test 6
    testBall->setx(80);
    testBall->sety(500);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 0);
    assert(testBall->getYHeading() == 0);
    assert(testBall->getx() == 150);
    assert(testBall->gety() == 80);
}
