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

class SingleScore;

class HighScore : public QWidget
{
    Q_OBJECT

public:
    explicit HighScore(QWidget *parent = 0);
    ~HighScore();
    vector<SingleScore*> highscore;
    //add to vector
    void addScore(SingleScore*);

    //delete high score from vector when
    void deleteScore(SingleScore*);

    //reset high scores -> there will be a button
    void reset();

    //unit tests for high scores
    void highScoreUnitTests();

    //print highscores (in ui?)
    QString print();

    // have save scores and load scores
    void loadHS();
    void saveHS();

private:
    Ui::HighScore *highscoreui;
    int score;
    string name;
};

class SingleScore{
private:
    int score;
    string name;
public:
    //constructor
    SingleScore() { }
    SingleScore(int score_, string name_) :
        score(score_), name(name_) { }
    //get methods
    string getName() {return name;}
    int getHighScore() {return score;}

    //set methods
    void setName(string newName) { name = newName; }
    void setHighScore(int newScore) { score = newScore; }

};


//keep track of multiplayer high scores
class MultiScore : public HighScore{
private:
    vector<HighScore*> multiscore;
public:
    MultiScore() { }
    ~MultiScore() { }



};









#endif // HIGHSCORE_H

