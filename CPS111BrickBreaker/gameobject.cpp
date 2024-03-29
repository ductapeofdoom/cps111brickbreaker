/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *gameobject.cpp - this file contains method definitions for the
 *                 GameObject, Paddle, Ball, and Brick classes. It also
 *                 contains the definition for collisionUnitTests().
 */

#include "gameobject.h"
#include "gamewindow.h"
#include "gameworld.h"

#include <QObject>
#include <QSound>

#include <cassert>

using namespace std;

//Units tests for ball collision detection
void collisionUnitTests(){
    Paddle * testPaddle = new Paddle(100,100,1);
    Ball * testBall = new Ball(110, 80, 0, 0, testPaddle,2);
    testPaddle->setInitialRight(true);
    //Test 1
    testBall->updatePosition();
    assert(testBall->getXHeading() == .5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 110.5);
    assert(testBall->getY() == 79.8);
    testBall->setCollision(false);
    //Test 2
    testBall->setX(220);
    testBall->setY(120);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 221.5);
    assert(testBall->getY() == 119.8);
    testBall->setCollision(false);
    //Test 3
    testBall->setX(0);
    testBall->setY(20);
    testBall->setXHeading(-1.5);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == -.2);
    assert(testBall->getX() == 1.5);
    assert(testBall->getY() == 19.8);
    testBall->setCollision(false);
    //Test 4
    testBall->setX(50);
    testBall->setY(0);
    testBall->setYHeading(-1);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 51.5);
    assert(testBall->getY() == 1);
    testBall->setCollision(false);
    //Test 5
    testBall->setX(380);
    testBall->setY(90);
    testBall->updatePosition();
    assert(testBall->getXHeading() == -1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 378.5);
    assert(testBall->getY() == 91);
    testBall->setCollision(false);
    //Test 6
    testBall->setX(220);
    testBall->setY(110);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 221.5);
    assert(testBall->getY() == 111);
    testBall->setCollision(false);
    //Test 7
    testBall->setX(80);
    testBall->setY(100);
    testBall->updatePosition();
    assert(testBall->getXHeading() == -1.5);
    assert(testBall->getYHeading() == 1);
    assert(testBall->getX() == 78.5);
    assert(testBall->getY() == 101);
    testBall->setCollision(false);
    //Test 8
    testBall->setX(80);
    testBall->setY(500);
    testBall->updatePosition();
    assert(testBall->getXHeading() == 0);
    assert(testBall->getYHeading() == 0);
    assert(testBall->getX() == 150);
    assert(testBall->getY() == 80);
    testBall->setCollision(false);
    GameWorld::accessWorld().setLife(5);

    delete testBall;
    delete testPaddle;
}

//Checks if the paddle has collided with the right side of the screen
bool Paddle::checkCollisionRight()
{
    if (x >= 280){
        return true;
    }
    else{
        return false;
    }
}

//Checks to see if the paddle has collided with the left side of the screen
bool Paddle::checkCollisionLeft()
{
    if (x <= 0){
        return true;
    }
    else{
        return false;
    }
}

void Paddle::CheckBallCollision()
{
    int ballX = GameWorld::accessWorld().getObjects().at(1)->getX();
    int ballY = GameWorld::accessWorld().getObjects().at(1)->getY();

    if (ballX > x - 20 && ballX < x + 60 && ballY > y - 20 && ballY < y + 20){
        GameWorld::accessWorld().getObjects().at(1)->setX(ballX - 10);
        Ball * ball = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
        ball->setXHeading(ball->getXHeading() * -1);
    }

    else if(ballX < x + 120 && ballX > x + 60 && ballY > y - 20 && ballY < y + 20){
        GameWorld::accessWorld().getObjects().at(1)->setX(ballX + 10);
        Ball * ball = dynamic_cast<Ball*>(GameWorld::accessWorld().getObjects().at(1));
        ball->setXHeading(ball->getXHeading() * -1);
    }
}

void Paddle::saveState()
{

}

//Checks for the ball's collision and sets its headings accordingly. If the ball has gone off the bottom of the screen the ball is reset to the center of the paddle.
void Ball::checkCollision()
{
    if (!collided){
        if (x <= 0){
            if (x < 0){
                        x = 0;
                        //y = paddle->getY() + 20;
            }
            xHeading = -1 * xHeading;
            collided = true;
        }
        else if (y <= 0){
            yHeading = -1 * yHeading;
            collided = true;
        }
        else if (x >= 380) {
            if (x > 380){
                        x = 380;
                        //y = paddle->getY() - 20;
                    }
            xHeading = -1 * xHeading;
            collided = true;
        }
        else if (y >= 500){
            if (!GameWorld::accessWorld().getNoDeath()){
                yHeading = 0;
                xHeading = 0;
                x = paddle->getX() + 50;
                y = paddle->getY() - 21;
                initialPos = true;
                GameWorld::accessWorld().loseLife();
            }
            else{
                yHeading = -1 * yHeading;
            }
        }
        else if ((x >= paddle->getX() - 20 && x <= paddle->getX() + 120) && (y >= paddle->getY() - 20 && y <= paddle->getY() + 20)){
            collided = true;
            //int testX = paddle->getX();
            //int testY = paddle->getY();
            if (((x+20 >= paddle->getX() - 20 && x >= paddle->getX() - 20 && x+20 <= paddle->getX() && x <= paddle->getX()) && y >= paddle->getY() - 20 && y <= paddle->getY() + 20) ||
                    ((x+20 <= paddle->getX() + 140 && x <= paddle->getX() + 140 && x+20 >= paddle->getX() + 120 && x >= paddle->getX() + 120) && y >= paddle->getY() - 20 && y <=paddle->getY() + 20)){
                xHeading = -1 * xHeading;
            }
            else{
                yHeading = -1 * yHeading;
            }
        }
        else{
            for(GameObject * obj: GameWorld::accessWorld().getObjects()){
                Brick * brick = dynamic_cast<Brick*>(obj);
                if (brick != NULL){
                    if((x >= brick->getX() - 20.1 && x <= brick->getX() + 40.1) && (y >= brick->getY() - 20.1 && y <= brick->getY() + 20.1) && !collided && !brick->getDestory()){

                        //int testY = paddle->getY();
                        if (((x+20 >= brick->getX() - 20 && x >= brick->getX() - 20 && x+20 <= brick->getX() && x <= brick->getX()) && y >= brick->getY() - 20 && y <= brick->getY() + 20) && !collided){
                            //x = x - 1;
                            xHeading = -1 * xHeading;
                        }
                        else if ((x+20 <= brick->getX() + 60 && x <= brick->getX() + 60 && x+20 >= brick->getX() + 40 && x >= brick->getX() + 40) && y >= brick->getY() - 20 && y <=brick->getY() + 20 && !collided){
                            //x = x + 1;
                            xHeading = -1 * xHeading;
                        }
                        else if(!collided){
                            yHeading = -1 * yHeading;
                        }
                        /*else if (y +20 >= brick->getY() && y + 20 <= brick->getY() + 20){
                            y = y - .4;
                            yHeading = -1 * yHeading;
                        }
                        //else if(y >= brick->getY() + 20 && y <= brick->getY()){
                            y = y + .4;
                            yHeading = -1 * yHeading;
                        }*/
                        collided = true;
                        GameWorld::accessWorld().incrementScore();
                        brick->hit();
                    }
                }
            }
        }
    }
}

//Updates the ball's x,y coordinates with its heading and sets it heading if the ball is sitting still.
void Ball::updatePosition(){
    if (initialPos){
        if(paddle->getInitialLeft()){
            yHeading = -.2;
            xHeading = -.5;
            paddle->setInitialLeft(false);
        }
        else if(paddle->getInitialRight()){
            yHeading = -.2;
            xHeading = .5;
            paddle->setInitialRight(false);
        }
        initialPos = false;
    }
   checkCollision();
   if (GameWorld::accessWorld().getSlowBall()){
       x = x + (xHeading * .5);
       y = y + (yHeading * .5);
   }
   else if (GameWorld::accessWorld().getSpeedBall()){
       x = x + (xHeading * 1.5);
       y = y + (yHeading * 1.5);
   }
   else{
       x = x + xHeading;
       y = y + yHeading;
   }
}

void Ball::saveState()
{

}

void Brick::hit(){
    hitsLeft--;

    if(hitsLeft == 0) {
        destroyed = true;
    }
}

void Brick::saveState()
{

}
