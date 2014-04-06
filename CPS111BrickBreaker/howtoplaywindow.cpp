#include "howtoplaywindow.h"
#include "ui_howtoplaywindow.h"

HowToPlayWindow::HowToPlayWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HowToPlayWindow)
{
    ui->setupUi(this);
}

HowToPlayWindow::~HowToPlayWindow()
{
    delete ui;
}

void HowToPlayWindow::on_btnOk_clicked()
{
    this->close();
    this->deleteLater();
}
