#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inputdialog.h"
#include "gameworld.h"

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
