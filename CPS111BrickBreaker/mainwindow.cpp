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
    //eliminate the possibility of clicking the load button twice in a row
    mainui->btnLoad->setEnabled(false);

    //create save manager, load the game, and then delete the pointer to the save manager
    SaveManager * saver = new SaveManager();
    saver->LoadGame();
    delete saver;

    //reenable the button
    mainui->btnLoad->setEnabled(true);

}

void MainWindow::on_btnMultiplayer_clicked()
{
    MultiplayerGUI * window = new MultiplayerGUI();
    window->show();
}
