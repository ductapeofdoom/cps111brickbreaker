#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <QString>
using namespace std;

//Unit tests for High Score classes
void highScoreUnitTests();

class Score{
private:
    int score;
    QString name;
public:
    //constructor
    Score(int newScore, QString newName) :
        score(newScore), name(newName) { }

    //get methods
    QString getName() {return name;}
    int getHighScore() {return score;}

    //set methods
    void setName(QString newName) { name = newName; }
    void setHighScore(int newScore) { score = newScore; }

};


class HighScoreManager
{
private:
    HighScoreManager(){}
    ~HighScoreManager();
    vector<Score*> highScores;
    static HighScoreManager managerInstance;

public:
    
    static HighScoreManager& accessManager() { return managerInstance; }

    //add to vector
    void addScore(Score*);

    //delete high score from vector when
    void deleteScore(Score*);

    //reset high scores -> there will be a button
    void reset();

    //print highscores (in ui?)
    QString print();

    // have save scores and load scores
    void loadHS(QString filename);

    void saveHS(QString filename);

    //Getter methods
    vector<Score*> getScores(){return highScores;}

};


#endif // HIGHSCORE_H
