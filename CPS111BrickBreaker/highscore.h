#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QWidget>
#include <string>
#include <vector>
#include <QString>
#include "gamewindow.h"
#include "gameworld.h"


namespace Ui {
class HighScore;
}

class HighScore : public QWidget
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = 0);
    ~HighScore();
    vector<HighScore*> highscore;

   //get methods
   string getName() {return name;}
   int getHighScore() {return score;}

   //set methods
   void setName(string newName) { name = newName; }
   void setHighScore(int newScore) { score = newScore; }

   //add to vector
   void addScore();

   //delete high score from vector when
   void deleteScore();

   //reset high scores -> there will be a button
   void reset();

   //unit tests for high scores
   void highScoreUnitTests();

   //print highscores (in ui?)
   void print();

private:
    Ui::HighScore *highscoreui;
    int score;
    string name;
};



//keep track of multiplayer high scores
class MultiScore : public HighScore{
private:
    vector<MultiScore*> multiscore;
public:
    MultiScore() { }
    ~MultiScore() { }



};









#endif // HIGHSCORE_H

