#include <QMainWindow>
#include <string>
#include "highscore.h"


//resets highscore, deletes everything from vector??
//check!
void HighScore::reset(){
    int i = 0;
    for (HighScore *high: highscore) //im not sure what I am doing
    {
        i++;
        if (i>-1){
            objects.erase(objects.begin() + i);
        }
        destroy(high);
    }

}

void HighScore::addScore() {

}




void HighScore::deleteScore() {

}






