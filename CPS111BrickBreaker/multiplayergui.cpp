#include "multiplayergui.h"
#include "ui_multiplayergui.h"
#include "gameobject.h"
#include "gameworld.h"
#include "highscore.h"
#include "gamewindow.h"
#include "inputdialog.h"

#include <QTcpSocket>
#include <QTcpServer>
#include <QMessageBox>
#include <QInputDialog>
#include <QFile>

MultiplayerGUI::MultiplayerGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MultiplayerGUI)
{
    ui->setupUi(this);
    server = new QTcpServer();
    connect(server, &QTcpServer::newConnection, this, &MultiplayerGUI::clientConnected);
    clientCount = 0;
}

MultiplayerGUI::~MultiplayerGUI()
{
    delete server;
    delete ui;
}


void MultiplayerGUI::clientConnected(){
    QTcpSocket * sock = server->nextPendingConnection();
    connect(sock, &QTcpSocket::disconnected, this, &MultiplayerGUI::clientDisconnected);
    connect(sock, &QTcpSocket::readyRead, this, &MultiplayerGUI::dataRecieved);
    currentConnections.push_back(sock);
    clientCount++;
    ui->lblClients->setText(QString::number(clientCount));
    if (clientCount < 2){
        ui->lblServerStatus->setText("Waiting for more client connections.");
        ui->lblServerStatus->setStyleSheet("color: orange;");
    }
    else if (clientCount > 2){
        ui->lblServerStatus->setText("Too many clients connected.");
        ui->lblServerStatus->setStyleSheet("color: red;");
    }
    else{
        int level = QInputDialog::getInt(this, "Level Choice", "Which level would you like to play?", 0, 1, 30);
        QString levelData = "LEVEL:", filePath = ":/documents/" + QString::number(level) + ".txt";

        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
            return;
        }

        while (!file.atEnd()) {
            QByteArray line = file.readLine();
            levelData = levelData + line;
        }

        file.close();
        ui->lblServerStatus->setText("Sending level data");
        ui->lblServerStatus->setStyleSheet("color: green;");
        for (QTcpSocket * socket: currentConnections){
            socket->write(levelData.toLocal8Bit());
        }
    }
}

void MultiplayerGUI::clientDisconnected()
{
    QTcpSocket * sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    clientCount--;
    ui->lblClients->setText(QString::number(clientCount));
}

void MultiplayerGUI::dataRecieved()
{
    QTcpSocket * sock = dynamic_cast<QTcpSocket*>(sender());
    while (sock->canReadLine()){
        QString line = sock->readLine();
    }
}

void MultiplayerGUI::on_btnStartServer_clicked()
{
    if (ui->btnStartServer->isChecked()){
        if (!server->listen(QHostAddress::Any, 6000)){
            exit(1);
        }
        ui->lblServerStatus->setText("Running");
        ui->lblServerStatus->setStyleSheet("color: green;");
        ui->btnStartServer->setText("Stop TCP Server");
    }
    else{
        server->close();
        for (QTcpSocket * sock: currentConnections){
            sock->close();
        }
        currentConnections.erase(currentConnections.begin(), currentConnections.end());
        ui->lblServerStatus->setText("Offline");
        ui->lblServerStatus->setStyleSheet("color: red;");
        ui->btnStartServer->setText("Start TCP Server");
        ui->lblClients->setText(QString::number(clientCount));
    }
}


void MultiplayerGUI::on_btnConnect_clicked()
{

    clientSock = new QTcpSocket(this);
    connect(clientSock, &QTcpSocket::readyRead, this, &MultiplayerGUI::clientDataRecieved);
    connect(clientSock, &QTcpSocket::disconnected, this, &MultiplayerGUI::serverDisconnected);
    clientSock->connectToHost("localhost", 6000);
    if (!clientSock->waitForConnected()){
        QMessageBox::critical(this, "ERROR", "Unable to connect to server.");
    }
    else{
        ui->lblConnectionStatus->setText("Connected");
        ui->lblConnectionStatus->setStyleSheet("color: green;");
        ui->btnConnect->setEnabled(false);
    }
}

void MultiplayerGUI::processInput(QString input)
{
    if (input.indexOf("LEVEL:") != -1){
        input.remove(0,6);

        Paddle * dataPaddle = new Paddle(150, 450, 1);
        Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle, 2);
        GameWorld::accessWorld().addObject(dataPaddle);
        GameWorld::accessWorld().addObject(dataBall);

        int count = 0;
        int idCounter = 3;

        //loop through the rows of Bricks
        for (int i = 0; i < 6; i++){

            //loop through the Bricks in a row
            for (int j = 0; j < 10; j++){
                QString singleBrickData = input.at(count);

                Brick *newbrick = new Brick(singleBrickData.toInt(), idCounter, j * 40, i * 20);
                GameWorld::accessWorld().addObject(newbrick);

                count++;
                idCounter++;
            }

        }
        qDebug() << "made Bricks for new level";

        GameWorld::accessWorld().setPlayerName(QInputDialog::getText(this, "Player Name?", "Please enter your name."));

        //make gamewindow and show it
        GameWindow* gamewindow = new GameWindow();

        //create the GUIBricks for a level
        gamewindow->renderLevel();

        //show the game window
        gamewindow->show();
    }
}

void MultiplayerGUI::clientDataRecieved()
{
    while(clientSock->canReadLine()){
        QString str = clientSock->readLine();
        processInput(str);
    }

}

void MultiplayerGUI::serverDisconnected()
{
    if (clientSock->isOpen()){
        clientSock->close();
    }
    clientSock->deleteLater();
    ui->btnConnect->setEnabled(true);
    ui->lblConnectionStatus->setText("Disconnected");
    ui->lblConnectionStatus->setStyleSheet("color: red;");
}

