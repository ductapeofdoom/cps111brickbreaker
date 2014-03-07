#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "gameworld.h"

#include <QInputDialog>
#include <QStringList>
#include <QDebug>

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

    //delete input;
}
