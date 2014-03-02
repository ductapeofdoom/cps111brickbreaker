#include "gamewindow.h"
//#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    gameui(new Ui::GameWindow)
{
    gameui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete gameui;
}

