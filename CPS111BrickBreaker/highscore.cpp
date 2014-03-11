#include <QWidget>
#include <string>
#include <QString>
#include "highscore.h"
#include "gamewindow.h"
#include "gameworld.h"
#include <cassert>
#include <QDebug>
using namespace std;


//resets highscore, deletes everything from vector??
void HighScoreManager::reset(){
    for (size_t i = 0; i < highScores.size(); i++) //im not sure what I am doing
    {
        if (i > -1){
            highScores.erase(highScores.begin() + i);
        }
    }
}


//high score
QString HighScoreManager::print(){
    QString hsShow;
    for (size_t i = 0; highScores.size() > i; i++){
        Score* top = highScores.at(i);
        QString name = top->getName();
        int score = top->getHighScore();
        QString currentScore = QString::number(score);
        hsShow = name + ": " + currentScore + " \n";
        qDebug() << hsShow;

        //how do I put into UI?
    }
    return hsShow;
}

void HighScoreManager::addScore(Score* single) {
    for (size_t k = 0; highScores.size() > k; k++){
        highScores.push_back(single);
    }

    //sort score...


    //erase last score
    if (highScores.size() > 10) {
        Score* lastHS = highScores.at(11);
        highScores.erase(highScores.end() - 1);
        delete lastHS;
    }
}

void HighScoreManager::deleteScore(Score* deleted) {
    for (size_t k = 0; highScores.size() > k; k++){
        if (deleted == highScores.at(k)){
            highScores.erase(highScores.begin() + k); //erase from vector
        }
    }
    delete deleted;
}

void HighScoreManager::loadHS() {
// open some text
    // loop to read high scores and store each in Score
    /*for () {
     * string name_ = read line
     * int score_ = read line
     *Score *savedScore = new Score(score_, name_)
     *addScore(savedScore);
     *}
*/

}

//save in text file
void HighScoreManager::saveHS(){
    for (size_t k = 0; highScores.size() > k; k++){
        Score* toSave = highScores.at(k);
        QString name = toSave->getName();
        int score = toSave->getHighScore();
        //convert to txt and save
        }
}


void highScoreUnitTests()
{
    HighScoreManager * manager = new HighScoreManager();
    manager->reset();
    assert(manager->getScores().size() == 0);

    //tests addScore
    Score* bob = new Score(25, "Bob");
    manager->addScore(bob);
    Score* top1 = new Score(1, "Bob");
    manager->addScore(top1);
    Score* top2 = new Score(33, "Bob");
    manager->addScore(top2);
    Score* top3 = new Score(44, "Bill");
    manager->addScore(top3);
    assert(manager->getScores().size() == 4);

    //test delete
    manager->deleteScore(top1);
    assert(manager->getScores().size() == 3);
    assert(manager->print() == "Bill: 44 \nBob: 33 \nBob 25 \n");

    manager->saveHS();

    manager->reset();
    assert(manager->getScores().size() == 0);

    manager->loadHS();
    assert(manager->getScores().size() == 3);
}
