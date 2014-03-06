#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include "gameobject.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);

    //Timer used for animations
    QTimer * getTimer(){return animTimer;}

    //accessor
    //static GameWindow* getUi();

    ~GameWindow();

private slots:
    //Slot for timer timeout signal
    void animTimerHit();

private:
    Ui::GameWindow *gameui;
    QTimer * animTimer;
    int cyclecount;
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
