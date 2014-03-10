#include "highscore.h"
#include "ui_highscore.h"

#include <QWidget>
#include <string>
#include <QString>
#include "highscore.h"
#include "ui_highscore.h"
#include "gamewindow.h"
#include "gameworld.h"
#include <cassert>
#include <QDebug>

HighScore::HighScore(QWidget *parent) :
    QWidget(parent),
    highscoreui(new Ui::HighScore)
{
    highscoreui->setupUi(this);
}

HighScore::~HighScore()
{
    delete highscoreui;
}


//resets highscore, deletes everything from vector??
void HighScore::reset(){
    int i = 0;
    for (i = 0; i < highscore.size(); i++) //im not sure what I am doing
    {
        if (i>-1){
            highscore.erase(highscore.begin() + i);
        }
    }
}

//high score
QString HighScore::print(){
    int i = 0;
    QString hsShow;
    for (int i = 0; highscore.size() > i; i++){
        SingleScore* top = highscore.at(i);
        name = top->getName();
        score =top->getHighScore();
        QString score_ = QString::number(score);
        hsShow = QString::fromStdString(name) + ": " + score_ + " \n";
        qDebug() << hsShow;
        highscoreui->lblHS_0->setText(hsShow);

        //how do I put into UI?
    }
    return hsShow;
}

void HighScore::addScore(SingleScore* single) {
    for (int k = 0; highscore.size() > k; k++){
        highscore.push_back(single);
    }

    //sort score...


    //erase last score
    SingleScore* lastHS = highscore.at(11);
    if (highscore.size() > 10) { delete lastHS; }
}

void HighScore::deleteScore(SingleScore* deleted) {
    for (int k = 0; highscore.size() > k; k++){
        if (deleted == highscore.at(k)){
            highscore.erase(highscore.begin() + k); //erase from vector
        }
    }
    delete deleted;
}

void HighScore::loadHS() {
// open some text
    // loop to read high scores and store each in SingleScore
    /*for () {
     * string name_ = read line
     * int score_ = read line
     *SingleScore *savedScore = new SingleScore(score_, name_)
     *addScore(savedScore);
     *}
*/

}

//save in text file
void HighScore::saveHS(){
    for (int k = 0; highscore.size() > k; k++){
        SingleScore* toSave = highscore.at(k);
        name = toSave->getName();
        score = toSave->getHighScore();
        //convert to txt and save
        }
}


void highScoreUnitTests(){

    HighScore* Bill;
    Bill->reset();
    assert(Bill->highscore.size() == 0);

    //tests addScore
    SingleScore* bob = new SingleScore(25, "Bob");
    Bill->addScore(bob);
    SingleScore* top1 = new SingleScore(1, "Bob");
    Bill->addScore(top1);
    SingleScore* top2 = new SingleScore(33, "Bob");
    Bill->addScore(top2);
    SingleScore* top3 = new SingleScore(44, "Bill");
    Bill->addScore(top3);
    assert(Bill->highscore.size() == 4);

    //test delete
    Bill->deleteScore(top1);
    assert(Bill->highscore.size() == 3);
    assert(Bill->print() == "Bill: 44 \nBob: 33 \nBob 25 \n");

    Bill->saveHS();

    Bill->reset();
    assert(Bill->highscore.size() == 0);

    Bill->loadHS();
    assert(Bill->highscore.size() == 3);

    //can imitate all tests from highscore and save on the other half of screen
    MultiScore* John;
    John->reset();

}

