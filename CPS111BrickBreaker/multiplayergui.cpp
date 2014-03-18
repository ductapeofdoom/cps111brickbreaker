#include "multiplayergui.h"
#include "ui_multiplayergui.h"

#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>

MultiplayerGUI::MultiplayerGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerGUI)
{
    ui->setupUi(this);
    serverThread = new ServerThread(this);
}

MultiplayerGUI::~MultiplayerGUI()
{
    delete ui;
}


void ServerObject::clientConnected(){

}

void ServerObject::connectSlots(){
    connect(server, &QTcpServer::newConnection, this, &ServerObject::clientConnected);
}

void ServerThread::run()
{
    QTcpServer * server = new QTcpServer(parentWindow);
    if (!server->listen(QHostAddress::Any, 6000)){
        QMessageBox::critical(parentWindow, "Failure to Start!", "Unable to start server!");
        exit(1);
    }
    servObj =  new ServerObject(server);
    servObj->connectSlots();
}
