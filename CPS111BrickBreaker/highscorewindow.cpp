#include "highscorewindow.h"
#include "highscore.h"
#include "ui_highscorewindow.h"

#include <vector>
using namespace std;

HighScoreWindow::HighScoreWindow(QWidget *parent) :
    QWidget(parent),
    highScoreUi(new Ui::HighScoreWindow)
{
    highScoreUi->setupUi(this);
}

HighScoreWindow::~HighScoreWindow()
{
    delete highScoreUi;
}

void HighScoreWindow::setSPScoresLabel(QString scores)
{
    highScoreUi->lblSPHS->setText(scores);
}

void HighScoreWindow::showHS(){
/*
    //vector<Score*> highScoreStuff = HighScoreManager::getScores();
    QString out;
    for (size_t i = 0; i < highScoreStuff.size(); i++)
    {
        Score* bob = highScoreStuff.at(i);
        QString name_ = bob->getName();
        QString score_ = QString::number(bob->getHighScore());
        out = out + "\n" + name_ + ": " + score_;

    }
    // set single player HS
    highScoreUi->lblSPHS->setText(out);

    //set multiplayerHS
    highScoreUi->lblMPHS->setText(out);
*/
}


