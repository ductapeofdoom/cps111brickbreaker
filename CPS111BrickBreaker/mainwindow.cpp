#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"

#include <QDialogButtonBox>

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
    //I was trying to show the other window here
    //inputDialog::ui->inputD
}
