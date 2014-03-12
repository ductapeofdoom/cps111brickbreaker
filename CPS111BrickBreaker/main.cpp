#include "mainwindow.h"
#include "gameobject.h"
#include "gamewindow.h"
#include "highscore.h"
#include <QApplication>
#include <vector>

using namespace std;

void runUnitTests(){
    collisionUnitTests();
    GUIUnitTests();
    highScoreUnitTests();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //Unit test command
    vector<string> args(argv, argv + argc);
    if (args.size() > 1 && args.at(1) == "test"){
        runUnitTests();
    }
    w.show();

    return a.exec();
}




