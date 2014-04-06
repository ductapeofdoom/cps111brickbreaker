/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *mainwindow.cpp - this file contains method definitions for the
 *                 MainWindow class.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "gameworld.h"
#include "highscore.h"
#include "highscorewindow.h"
#include "multiplayergui.h"
#include "savemanager.h"
#include "howtoplaywindow.h"

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
    music = new QSound(":/sounds/piano.wav");
    music->setLoops(-1);
}

MainWindow::~MainWindow()
{
    delete mainui;
    delete music;
}

void MainWindow::playMusic()
{
    music->play();
}

void MainWindow::stopMusic()
{
    music->stop();
}

void MainWindow::on_btnPlay_clicked()
{
    InputDialog *input = new InputDialog(music);
    input->setGeometry(497, 100, 400, 168);
    input->show();
    input->setFocusOnLineEdit();
}

void MainWindow::on_btnHowToPlay_clicked()
{
    HowToPlayWindow * howto = new HowToPlayWindow();
    howto->setGeometry(350, 80, 686, 510);
    howto->show();
}

void MainWindow::on_btnHighScores_clicked()
{
    HighScoreWindow* showHS = new HighScoreWindow();
    showHS->setGeometry(417, 80, 557, 514);
    showHS->show();
}

void MainWindow::on_btnLoad_clicked()
{
    //eliminate the possibility of clicking the load button twice in a row
    mainui->btnLoad->setEnabled(false);

    //create save manager, load the game, and then delete the pointer to the save manager
    SaveManager * saver = new SaveManager(this, music);
    saver->LoadGame();
    delete saver;

    //reenable the button
    mainui->btnLoad->setEnabled(true);

}

void MainWindow::on_btnMultiplayer_clicked()
{

    MultiplayerGUI * window = new MultiplayerGUI(music);
    window->setGeometry(440, 80, 512, 487);
    window->show();
}
