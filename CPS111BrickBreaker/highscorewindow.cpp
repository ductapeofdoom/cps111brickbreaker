#include "highscorewindow.h"
#include "ui_highscorewindow.h"

HighScoreWindow::HighScoreWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighScoreWindow)
{
    ui->setupUi(this);
}

HighScoreWindow::~HighScoreWindow()
{
    delete ui;
}
