/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *main.cpp - this file contains the main method that runs the game.
 *           It also contains the function declaration for runUnitTests()
 *           that runs the other various unit test functions.
 */

#include "mainwindow.h"
#include "gameobject.h"
#include "gamewindow.h"
#include "highscore.h"
#include <QApplication>
#include <QDebug>
#include <QSound>
#include <vector>

using namespace std;

//function that runs all of our unit tests
void runUnitTests(){
    collisionUnitTests();
    highScoreUnitTests();
    qDebug() << "All tests passed.";
}

//main method
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Unit test command
    vector<string> args(argv, argv + argc);
    if (args.size() > 1 && args.at(1) == "-test"){
        runUnitTests();
    }
    w.setGeometry(450, 0, 491, 585);
    w.show();
    QSound * music = new QSound(":/sounds/piano.wav");
    music->setLoops(-1);
    music->play();

    return a.exec();
}
