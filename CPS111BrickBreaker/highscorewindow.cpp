/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *highscorewindow.cpp - this file contains method definitions for the
 *                      HighScoreWindow class.
 */

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
    showHS();
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

    vector<Score*> highScores = HighScoreManager::accessManager().getScores();
    QString out = "";
    for (size_t i = 0; i < highScores.size(); i++)
    {
        Score* bob = highScores.at(i);
        QString name_ = bob->getName();
        QString score_ = QString::number(bob->getHighScore());
        out = out + "\t\t\t" + name_ + ": " + score_ + "\n";

    }
    // set single player HS
    highScoreUi->lblSPHS->setText(out);

    //set multiplayerHS
    //highScoreUi->lblMPHS->setText(out);
}



void HighScoreWindow::on_btnResetScores_clicked()
{
    HighScoreManager::accessManager().reset();
    HighScoreManager::accessManager().saveHS(".highscore.txt");
    showHS();
}
