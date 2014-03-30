/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *gamewindow.h - this file contains class definitions and method declarations for
 *               the GameWindow, GameWidget, GUIPaddle, GUIBall, and GUIBrick classes.
 */

#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QString>
#include <QPropertyAnimation>
#include "gameobject.h"
#include <string>
#include <vector>
#include <QTcpSocket>

using namespace std;

namespace Ui {
class GameWindow;
}

//forward declaration of GUIBrick because GameWindow uses it
class GUIBrick;
class GUIPaddle;
class GameWidget;

class GameWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::GameWindow *gameui;
    QTimer * animTimer;
    QPropertyAnimation * animationBall;
    QPropertyAnimation * animationPaddle;
    int cyclecount, life, collisioncount;
    vector<QWidget*> GUIObjects;
    bool network;
    QTcpSocket * socket;
    GameWidget * wdGame;

private slots:
    //Slot for timer timeout signal
    void animTimerHit();
    
    void on_btnPause_clicked();

    void on_btnNoDeath_clicked();

    void on_btnSlowBall_clicked();

    void on_btnSpeedBall_clicked();

    void on_btnAddLife_clicked();

    void on_btnSave_clicked();

public:
    explicit GameWindow(QWidget *parent = 0);

    //method to add GUIBricks to the vector
    void  addObject(QWidget * newObject){ GUIObjects.push_back(newObject);}

    //Timer used for animations
    QTimer * getTimer(){return animTimer;}

    //create GUIBricks based on the Brick objects in the vector in gameworld
    void renderLevel();

    void Update(QObject *obj);

    //accessors
    //static GameWindow* getUi();
    vector<QWidget*>& getGUIObjects(){ return GUIObjects; }

    //mutators
    void turnNoDeathButtonOn();
    void turnSlowBallButtonOn();
    void turnSpeedBallButtonOn();

    //display stuff on side of screen
    void showStuff();

    void GeneratePlayer();

    void closeEvent(QCloseEvent *ev);

    void setNetwork(bool value) {network = value;}

    void setSocket(QTcpSocket * sock) {socket = sock;}

    ~GameWindow();

};
class GameWidget : public QWidget{
    GUIPaddle * paddle;
    int offsetX, offsetY;
public:
    GameWidget(QWidget * parent);

    void setPaddle(GUIPaddle * newPaddle) {paddle = newPaddle;}

    void mouseMoveEvent(QMouseEvent * event);

    void mousePressEvent(QMouseEvent * event);
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
        setFocusPolicy(Qt::TabFocus);
        setStyleSheet("background-color: white");

    }

    //Method for what happens when the object recieves a key press
    void keyPressEvent(QKeyEvent * event);

    //Getter methods
    Paddle * getPaddle(){return paddle;}

    //Setter methods
    void setInitialCommand(bool value){initialCommand = value;}

    bool getInitialCommand() {return initialCommand;}
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
        setGeometry(QRect(brick->getX(), brick->getY(), 40, 20));
        imgName = ":/images/" + QString::number(brick->getHits()) + ".png";

        QString bkgndImageStyle = "background-image: url(" + imgName + ")";
        setStyleSheet(bkgndImageStyle);
    }

    //accessor
    QString getImage() { return imgName; }
    double getXValue() { return brick->getX(); }
    Brick * getBrick() {return brick;}

    ~GUIBrick() {
        delete brick;
    }
};


#endif // GAMEWINDOW_H
