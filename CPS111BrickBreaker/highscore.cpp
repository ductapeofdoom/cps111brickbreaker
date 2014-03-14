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


//resets highscore, deletes everything from vector??
void HighScoreManager::reset(){
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

void HighScoreManager::addScore(Score* single) {
    //sort score
    int highPos = highScores.size() - 1;
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
    QString highscoreText;
    QFile file(".highscore.txt");

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
        QStringList nameScoreList = nameScore.split(" ");
        QString name = nameScoreList.at(0);
        int score = nameScoreList.at(1).toInt();
        Score* aScore = new Score(score, name);
        addScore(aScore);
    }//for

}

//save in text file
void HighScoreManager::saveHS(){

    QString nameandScore = "";
    for (size_t k = 0; k < highScores.size(); k++){
        Score* toSave = highScores.at(k);
        QString name = toSave->getName();
        QString score = QString::number(toSave->getHighScore());
        nameandScore += name + " " + score + "\n";
        }
    QFile file(".highscore.txt");
    if (!file.open(QIODevice::ReadWrite| QIODevice::Text)){
        return;
    }
    file.write(nameandScore.toLocal8Bit());
    file.close();

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
    assert(manager->print() == "Bill: 44 \nBob: 33 \nBob: 25 \n");

    manager->saveHS();

    manager->reset();
    assert(manager->getScores().size() == 0);

    manager->loadHS();
    assert(manager->getScores().size() == 3);
}
