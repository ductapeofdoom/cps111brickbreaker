#include <QWidget>
#include <string>
#include <QString>
#include "highscore.h"
#include "gamewindow.h"
#include "gameworld.h"
#include <cassert>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
using namespace std;

HighScoreManager HighScoreManager::managerInstance;

//resets highscore, deletes everything from vector??
void HighScoreManager::reset(){
    for(Score * score: highScores){
        delete score;
    }
    highScores.erase(highScores.begin(), highScores.end());
}


//high score
QString HighScoreManager::print(){
    QString hsShow;
    for (size_t i = 0; i < highScores.size(); i++){
        Score* top = highScores.at(i);
        QString name = top->getName();
        int score = top->getHighScore();
        QString currentScore = QString::number(score);
        hsShow += name + ": " + currentScore + " \n";

        //how do I put into UI?
    }
    qDebug() << hsShow;
    return hsShow;
}

HighScoreManager::~HighScoreManager()
{
    for(Score * score: highScores){
        delete score;
    }
}

void HighScoreManager::addScore(Score* single) {
    //sort score
    int highPos = highScores.size();
    int currentHigh = 0;
    if (highScores.size() > 1){
        for (size_t i = 0; i < highScores.size(); i++){
            if (single->getHighScore() > highScores.at(i)->getHighScore() && highScores.at(i)->getHighScore() > currentHigh){
                highPos = i;
                currentHigh = highScores.at(i)->getHighScore();
            }
        }
        highScores.insert(highScores.begin() + highPos, single);
    }
    else if (highScores.size() == 1){
        if (single->getHighScore() > highScores.at(0)->getHighScore()){
            highScores.insert(highScores.begin(), single);
        }
        else{
            highScores.push_back(single);
        }
    }
    else{
        highScores.push_back(single);
    }


    //erase last score
    if (highScores.size() > 10) {
        Score* lastHS = highScores.at(10);
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

void HighScoreManager::loadHS(QString filename) {
    QString highscoreText;
    QFile file(filename);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }//if

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        highscoreText += line;
    }//while

    file.close();

//put data in list
    QStringList namesandScores = highscoreText.split("\n");
//add scores and names to vector
    for (int i = 0; i < namesandScores.size() - 1; i++){
        QString nameScore= namesandScores.at(i);
        QStringList nameScoreList = nameScore.split(":");
        QString name = nameScoreList.at(0).trimmed();
        int score = nameScoreList.at(1).trimmed().toInt();
        Score* aScore = new Score(score, name);
        addScore(aScore);
    }//for

}

//save in text file
void HighScoreManager::saveHS(QString filename){

    QString nameandScore = "";
    for (size_t k = 0; k < highScores.size(); k++){
        Score* toSave = highScores.at(k);
        QString name = toSave->getName();
        QString score = QString::number(toSave->getHighScore());
        nameandScore += name + ":" + score + "\n";
        }
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly| QIODevice::Text)){
        return;
    }
    file.write(nameandScore.toLocal8Bit());
    file.close();

}


void highScoreUnitTests()
{
    HighScoreManager::accessManager().reset();
    assert( HighScoreManager::accessManager().getScores().size() == 0);

    //tests addScore
    Score* bob = new Score(25, "Bob");
    HighScoreManager::accessManager().addScore(bob);
    Score* top1 = new Score(1, "Bob");
    HighScoreManager::accessManager().addScore(top1);
    Score* top2 = new Score(33, "Bob");
    HighScoreManager::accessManager().addScore(top2);
    Score* top3 = new Score(44, "Bill");
    HighScoreManager::accessManager().addScore(top3);
    assert(HighScoreManager::accessManager().getScores().size() == 4);

    //test delete
    HighScoreManager::accessManager().deleteScore(top1);
    assert(HighScoreManager::accessManager().getScores().size() == 3);
    assert(HighScoreManager::accessManager().print() == "Bill: 44 \nBob: 33 \nBob: 25 \n");

    HighScoreManager::accessManager().saveHS(".highscoretest");

    HighScoreManager::accessManager().reset();
    assert(HighScoreManager::accessManager().getScores().size() == 0);

    HighScoreManager::accessManager().loadHS(".highscoretest");
    assert(HighScoreManager::accessManager().getScores().size() == 3);

     HighScoreManager::accessManager().reset();
     HighScoreManager::accessManager().loadHS(".highscore.txt");
}
