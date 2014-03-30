#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "gameworld.h"
#include "highscore.h"
#include "highscorewindow.h"
#include "multiplayergui.h"

#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
#include <QFile>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainui(new Ui::MainWindow)
{
    mainui->setupUi(this);
    HighScoreManager::accessManager().loadHS(".highscore.txt");
}

MainWindow::~MainWindow()
{
    delete mainui;
}

void MainWindow::on_btnPlay_clicked()
{
    InputDialog *input = new InputDialog();
    input->show();
    input->setFocusOnLineEdit();
}

void MainWindow::on_btnHowToPlay_clicked()
{
    QString howToPlay;
    QFile file(":/documents/howTo.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Error!", "The 'How To' file appears to be missing or corrupted. You're on your own!");
        return;
    }

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        howToPlay = howToPlay + line;
    }

    QMessageBox::information(this, "How To Play", howToPlay);
}

void MainWindow::on_btnHighScores_clicked()
{
    HighScoreWindow* showHS = new HighScoreWindow();
    showHS->show();
}

void MainWindow::on_btnLoad_clicked()
{
    //open file
    ifstream infile("gamesave.txt");

    //close if file didn't open
    if (!infile) {
        QMessageBox::critical(this, "Error!", "The default save file could not be loaded. Please start a new game and save it in order to be able to load it.");
        return;
    }

    //file is open, read it into a string
    string line = "", fullfile = "";
    getline(infile, line);
    while (infile) {
        fullfile += line;
        getline(infile, line);
    }

    //close file
    infile.close();

    //declare some vars for use in processing the string
    vector<string> gamedata;
    string entry = "";
    char ch = ' ';
    uint count = 0;

    //split the string up into the individual parts and store them in the vector
    while (count < fullfile.size()){
        ch = fullfile.at(count);
        if (ch != '@'){
            entry += ch;
        }
        else{
            gamedata.push_back(entry);
            entry = "";
        }
        count++;
    }

    //take the parts out of the vector and assign them to the appropriate variables in GameWorld
    //set the level
    GameWorld::accessWorld().setLevel(stoi(gamedata.at(0)));

    //set the player name
    GameWorld::accessWorld().setPlayerName(QString::fromStdString(gamedata.at(1)));

    //set the current score
    GameWorld::accessWorld().setCurrentScore(stoi(gamedata.at(2)));

    //set the difficulty and totalNumBricks based on difficulty
    int difficulty = stoi(gamedata.at(3));
    GameWorld::accessWorld().setDifficulty(difficulty);
    if (difficulty == 0){
        GameWorld::accessWorld().setTotalNumBricks(20);
    }
    else if (difficulty == 1){
        GameWorld::accessWorld().setTotalNumBricks(40);
    }
    else if (difficulty == 2){
        GameWorld::accessWorld().setTotalNumBricks(60);
    }

    //set the number of lives
    GameWorld::accessWorld().setLife(stoi(gamedata.at(4)));

    //add a ball and paddle
    Paddle * dataPaddle = new Paddle(150, 450, 1);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle, 2);
    GameWorld::accessWorld().addObject(dataPaddle);
    GameWorld::accessWorld().addObject(dataBall);

    //recreate the bricks that were saved
    //put the data of the bricks into the brickdatavec vector
    uint i = 0;
    string allbrickdata = gamedata.at(5);
    vector<string> brickdatavec;
    while (i < allbrickdata.size()){
        ch = allbrickdata.at(i);
        if (ch != ' '){
            entry += ch;
        }
        else{
            brickdatavec.push_back(entry);
            entry = "";
        }
        i++;
    }

    //go through the vector creating bricks and adding them to the GameObjects vector
    int j = 3; /*variable that will be used to set the ID of brick objects.
                 set to 3 because the ball and paddle are already in the vector,
                 and they used up 1 and 2.*/
    for (string brickdata : brickdatavec){
        int hits = brickdata.at(0); //set number of hits as the first number in the string
        //remove the hits and the parentheses and store the result in a new string
        string brickcoord = brickdata.substr(2, brickdata.size() - 3);

        //split up the coordinates and store the values in integers
        int newx, newy, commapos = brickcoord.find(',');
        newx = stoi(brickcoord.substr(0, brickcoord.size() - commapos));
        newy = stoi(brickcoord.substr(commapos + 1, string::npos));

        //create brick & store in vector
        Brick *newbrick = new Brick(hits, j, newx, newy);
        GameWorld::accessWorld().addObject(newbrick);
        j++;
    }

    qDebug() << "Made Bricks for the saved level.";

    //make gamewindow
    GameWindow* gamewindow = new GameWindow();

    //create the GUIBricks for a level
    gamewindow->renderLevel();

    //show the game window
    gamewindow->show();

    //set the cheats from the saved data
    string cheatdata = gamedata.at(6);
    //if nodeath was on before, set it to on now
    if (cheatdata.at(0) == '1'){
        GameWorld::accessWorld().setnoDeath(true);
        gamewindow->turnNoDeathButtonOn();
    }

    //if slowball was on before, set it to on now
    if (cheatdata.at(1) == '1'){
        GameWorld::accessWorld().setSlowBall(true);
        gamewindow->turnSlowBallButtonOn();
    }

    //if speedball was on before, set it to on now
    if (cheatdata.at(2) == '1'){
        GameWorld::accessWorld().setSpeedBall(true);
        gamewindow->turnSpeedBallButtonOn();
    }

}

void MainWindow::on_btnMultiplayer_clicked()
{
    MultiplayerGUI * window = new MultiplayerGUI();
    window->show();
}
