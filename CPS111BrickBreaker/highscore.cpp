#include "highscore.h"
#include "ui_highscore.h"

#include <QWidget>
#include <string>
#include <QString>
#include "highscore.h"
#include "ui_highscore.h"
#include "gamewindow.h"
#include "gameworld.h"


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
void HighScore::print(){
    int i = 0;
    for (int i = 0; highscore.size() > i; i++){
        HighScore* top = highscore.at(i);
        name = top->getName();
        score =top->getHighScore();

        //how do I put into UI?
    }
}

void HighScore::addScore() {
    for (int k = 0; highscore.size() > k; k++){
        highscore.push_back(highscore.at(k));
    }

    //sort score...

    //erase last score
    HighScore* lastHS = highscore.at(11);
    if (highscore.size() > 10) { delete lastHS; }
}

void HighScore::deleteScore() {

}

void HighScore::highScoreUnitTests(){
    reset();
    addScore();

}



