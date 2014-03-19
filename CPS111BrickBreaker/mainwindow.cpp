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
    vector<string> data;
    string entry = "";
    char ch = ' ';
    int count = 0;

    //split the string up into the individual parts
    while (ch != '#'){
        ch = fullfile.at(count);
        if (ch != '%'){
            entry += ch;
        }
        else{
            data.push_back(entry);
            entry = "";
        }
        count++;
    }

    //take the parts out of the vector and assign them to the appropriate variables in GameWorld
    GameWorld::accessWorld().setLevel(stoi(data.at(0)));
    GameWorld::accessWorld().setPlayerName(QString::fromStdString(data.at(1)));
    GameWorld::accessWorld().setCurrentScore(stoi(data.at(2)));
    GameWorld::accessWorld().setDifficulty(stoi(data.at(3)));
    GameWorld::accessWorld().setLife(stoi(data.at(4)));

    //create the bricks for a level
    GameWorld::accessWorld().makeLevel();

    //make gamewindow and show it
    GameWindow* gamewindow = new GameWindow();

    //create the GUIBricks for a level
    gamewindow->renderLevel();

    //show the game window
    gamewindow->show();

}

void MainWindow::on_btnMultiplayer_clicked()
{
    MultiplayerGUI * window = new MultiplayerGUI();
    window->show();
}
