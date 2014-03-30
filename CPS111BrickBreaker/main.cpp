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
#include <vector>

using namespace std;

void runUnitTests(){
    collisionUnitTests();
    highScoreUnitTests();
    qDebug() << "All tests passed.";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Unit test command
    vector<string> args(argv, argv + argc);
    if (args.size() > 1 && args.at(1) == "-test"){
        runUnitTests();
    }
    w.show();

    return a.exec();
}
