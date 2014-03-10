#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include "gameobject.h"
#include <vector>

using namespace std;

namespace Ui {
class GameWindow;
}

//forward declaration of GUIBrick because GameWindow uses it
class GUIBrick;

class GameWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::GameWindow *gameui;
    QTimer * animTimer;
    int cyclecount, life;
    vector<GUIBrick*> GUIBricks;

private slots:
    //Slot for timer timeout signal
    void animTimerHit();
    
public:
    explicit GameWindow(QWidget *parent = 0);

    //method to add GUIBricks to the vector
    void addObject(GUIBrick * newBrick){ GUIBricks.push_back(newBrick);}

    //Timer used for animations
    QTimer * getTimer(){return animTimer;}

    //get/set number of lives
    int getLife() {return life;}
    void setLife(int);

    //accessor
    //static GameWindow* getUi();


    //display stuff on side of screen
    void showStuff();

    ~GameWindow();

};

//GUI representation of the paddle
class GUIPaddle : public QWidget{
    Paddle * paddle;
    GameWindow * window;
    bool initialCommand;
public:
    //The constructor sets the paddle at the middle of the widget and makes it the focused object (can recieve key inputs)
    explicit GUIPaddle(QWidget * parent, Paddle * newPaddle, GameWindow * currentWindow) : QWidget(parent), paddle(newPaddle), window(currentWindow), initialCommand(true){
        setGeometry(QRect(150, 450, 120, 20));
        setFocusPolicy(Qt::StrongFocus);
        setStyleSheet("background-color: white");
    }

    //Method for what happens when the object recieves a key press
    void keyPressEvent(QKeyEvent * event);

    //Getter methods
    Paddle * getPaddle(){return paddle;}

    //Setter methods
    void setInitialCommand(bool value){initialCommand = value;}
};

//GUI representation of the ball
class GUIBall : public QWidget{
    Ball * ball;
public:
    //The constructor sets that ball at the middle of the paddle.
    explicit GUIBall(QWidget * parent, Ball * newBall): QWidget(parent), ball(newBall){
        setGeometry(QRect(200, 430, 20, 20));
        setStyleSheet("background-color: orange");
    }

    //Getter methods
    Ball * getBall(){return ball;}
};

class GUIBrick : public QWidget{
    Brick * brick;
    QString imgName;
public:
    explicit GUIBrick(QWidget * parent, Brick * newBrick): QWidget(parent), brick(newBrick){
        setGeometry(QRect(brick->getX(), brick->getY(), 126, 63));
        imgName = brick->getHits() + ".png";
    }

    //accessor
    QString getImage(){ return imgName; }
};

#endif // GAMEWINDOW_H
