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
#include <QMutex>
#include <QMutexLocker>

QMutex mutex;

MultiplayerGUI::MultiplayerGUI(QWidget *parent) :
    QWidget(parent),
    player1Name(""), player2Name("") , player1Score(0), player2Score(0), ui(new Ui::MultiplayerGUI)
{
    ui->setupUi(this);
    server = new QTcpServer();
    connect(server, &QTcpServer::newConnection, this, &MultiplayerGUI::clientConnected);
    clientCount = 0;
    gamewindow = NULL;
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

        levelData += "\n";
        file.close();
        ui->lblServerStatus->setText("Sending level data");
        ui->lblServerStatus->setStyleSheet("color: green;");
        for (QTcpSocket * socket: currentConnections){
            socket->write(levelData.toLocal8Bit());
        }
        ui->lblServerStatus->setText("Level data sent");
    }
}

void MultiplayerGUI::clientDisconnected()
{
    QTcpSocket * sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    clientCount--;
    ui->lblClients->setText(QString::number(clientCount));
}

void ServerProcessThread::run()
{
    while (socket->canReadLine()){
        QString line = socket->readLine();
        if (line.indexOf("DESTROY:") != -1){
            for (QTcpSocket * sock: currentConnections){
                if (sock != socket){
                    sock->write(line.toLocal8Bit());
                }
            }
        }
        else if (line.indexOf("SCORE:") != -1){
            line = line.remove(0, 6);
            QStringList scoreList = line.split(":");
            if (player1Name == ""){
                player1Name = scoreList.at(0);
                player1Score = scoreList.at(1).toInt();
            }
            else{
                player2Name = scoreList.at(0);
                player2Score = scoreList.at(1).toInt();
                if (player1Score > player2Score){
                    QString winningScore = "WINNER:" + player1Name + " wins with a score of " + QString::number(player1Score) +"\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
                else if (player1Score == player2Score){
                    QString winningScore = "WINNER: You have tied with a score of " + QString::number(player2Score) + "\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
                else{
                    QString winningScore = "WINNER:" + player2Name + " wins with a score of " + QString::number(player2Score) + "\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
            }
        }
    }
    socket->moveToThread(QApplication::instance()->thread());
}

void MultiplayerGUI::dataRecieved()
{
    QTcpSocket * sock = dynamic_cast<QTcpSocket*>(sender());
    while (sock->canReadLine()){
        QString line = sock->readLine();
        if (line.indexOf("DESTROY:") != -1){
            for (QTcpSocket * socket: currentConnections){
                if (socket != sock){
                    socket->write(line.toLocal8Bit());
                }
            }
        }
        else if (line.indexOf("SCORE:") != -1){
            line = line.remove(0, 6);
            QStringList scoreList = line.split(":");
            if (player1Name == ""){
                player1Name = scoreList.at(0);
                player1Score = scoreList.at(1).toInt();
            }
            else{
                player2Name = scoreList.at(0);
                player2Score = scoreList.at(1).toInt();
                if (player1Score > player2Score){
                    QString winningScore = "WINNER:" + player1Name + " wins with a score of " + QString::number(player1Score) +"\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
                else if (player1Score == player2Score){
                    QString winningScore = "WINNER: You have tied with a score of " + QString::number(player2Score) + "\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
                else{
                    QString winningScore = "WINNER:" + player2Name + " wins with a score of " + QString::number(player2Score) + "\n";
                    for (QTcpSocket * sock: currentConnections){
                        sock->write(winningScore.toLocal8Bit());
                    }
                }
            }
        }
    }

   // ServerProcessThread * thread = new ServerProcessThread(sock, currentConnections);
    //connect(thread, &QThread::finished, this, &MultiplayerGUI::serverProcessFinished);
    //thread->start();
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
            delete sock;
        }
        currentConnections.clear();
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

void ProcessThread::run()
{
    int i = 0;
    for (QWidget * obj: window->getGUIObjects()){
        GUIBrick * curBrick = dynamic_cast<GUIBrick*>(obj);
        if(curBrick != NULL){
            Brick * dataBrick = dynamic_cast<Brick*>(curBrick->getBrick());
            if (dataBrick != NULL && curBrick->getBrick()->getId() == input.toInt()){
                GameWorld::accessWorld().deleteObject(input.toInt());
                window->getGUIObjects().erase(window->getGUIObjects().begin() + i);
                resultBrick = curBrick;
                //delete dataBrick;
            }
        }
        i++;
    }
}

void MultiplayerGUI::processInput(QString input)
{
    if (input.indexOf("LEVEL:") != -1){
        input.remove(0,6);
        GenerateMuliWorld(input);
    }
    else if(input.indexOf("DESTROY:") != -1){
        input.remove(0,8);
        ProcessThread * thread = new ProcessThread(gamewindow);
        connect(thread, &QThread::finished, this, &MultiplayerGUI::processFinished);
        thread->setInput(input);
        thread->start();
    }
    else if(input.indexOf("WINNER:") != -1){
        input.remove(0,7);
        QMessageBox::about(this, "Winner", input);
        gamewindow->close();
    }
}

void MultiplayerGUI::GenerateMuliWorld(QString input)
{
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
    gamewindow = new GameWindow();

    //create the GUIBricks for a level
    gamewindow->renderLevel();

    gamewindow->setSocket(clientSock);

    gamewindow->setNetwork(true);

    //show the game window
    gamewindow->show();
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

void MultiplayerGUI::processFinished()
{
    if (dynamic_cast<ProcessThread*>(sender())->getResult() != NULL){
        dynamic_cast<ProcessThread*>(sender())->getResult()->hide();
    }
    sender()->deleteLater();

}

void MultiplayerGUI::serverProcessFinished()
{
    sender()->deleteLater();
}



