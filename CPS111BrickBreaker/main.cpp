#include "mainwindow.h"
#include "gameobject.h"
#include "gamewindow.h"
#include "highscore.h"
#include "main.h"
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

//takes a string <text> and replaces any instances of <ch1> with <ch2>
string processText(string text, char ch1, char ch2){
    int pos = text.find(ch1);
    if (pos != string::npos){
        stringstream sstream;
        sstream << text.substr(0, pos) << ch2 << text.substr(pos + 1, text.size()- (pos + 1));
        text = sstream.str();
        processText(text, ch1, ch2);
    }
    else{
        qDebug() << "Player Name is " << QString::fromStdString(text);
        return text;
    }
}


