#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QMainWindow>
#include <string>

using namespace std;

//keep track of personal high scores
class HighScore{
private:

    /* vector<HighScore*>
     *
     *
     *
     *
     *
     */

    int score;
    string name;



public:
    /*
     *
     *
     *
     *
     *
     *
     */

    //constructor
    HighScore(){
//get name from textbox earlier
//get score from game

    }
    ~HighScore(){ }

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
