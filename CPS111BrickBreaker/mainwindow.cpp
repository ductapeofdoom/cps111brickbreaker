#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "gameworld.h"
#include "highscore.h"

#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainui(new Ui::MainWindow)
{
    mainui->setupUi(this);
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
    HighScore *highscore = new HighScore();
    highscore->show();
}
