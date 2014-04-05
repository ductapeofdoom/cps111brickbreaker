/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *multiplayergui.cpp - this file contains method definitions for the
 *                     MultiplayerGUI, ProcessThread, and ServerProcessThread classes.
 */

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

//The constructor instatiates a server and connects its newConnection signal to the clientConnected slot.
MultiplayerGUI::MultiplayerGUI(QSound * newmusic, QWidget *parent) :
    QWidget(parent),
    player1Name(""), player2Name("") , player1Score(0), player2Score(0), ui(new Ui::MultiplayerGUI), music(newmusic)
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

//The method connects the new socket to the proper slots and checks for the number of client connected
//and if the number is 2 it will send out the level data selected by the player.
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
        QString levelData = "LEVEL:" + QString::number(level) + "/", filePath = ":/documents/" + QString::number(level) + ".txt";

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

//The method deletes the disconnected socket an deincrements the the clientCount variable.
void MultiplayerGUI::clientDisconnected()
{
    QTcpSocket * sock = dynamic_cast<QTcpSocket*>(sender());
    sock->deleteLater();
    clientCount--;
    ui->lblClients->setText(QString::number(clientCount));
}


/*void ServerProcessThread::run()
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
}*/

//The method checks for the data recieved and if a destroy command is recieved it echos out the command, if a score command is recieved it saves the score
//and if both scores have been recieved it sends out the winner.
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
    clientSock->connectToHost(ui->lnServer->text(), 6000);
    if (!clientSock->waitForConnected()){
        QMessageBox::critical(this, "ERROR", "Unable to connect to server.");
    }
    else{
        ui->lblConnectionStatus->setText("Connected");
        ui->lblConnectionStatus->setStyleSheet("color: green;");
        ui->btnConnect->setEnabled(false);
    }
}


//Thread run  method for deleting neccessare bricks
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

//The method checks for the data recieved and creates the world, destroys a block, or shows the winner as neccessary.
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
        QMessageBox::about(gamewindow, "Winner", input);
        gamewindow->close();
    }
}

//Creates the multiplayer world
void MultiplayerGUI::GenerateMuliWorld(QString input)
{
    Paddle * dataPaddle = new Paddle(150, 450, 1);
    Ball * dataBall = new Ball(200, 430, 0, 0, dataPaddle, 2);
    GameWorld::accessWorld().addObject(dataPaddle);
    GameWorld::accessWorld().addObject(dataBall);

    int slPos = input.indexOf("/");

    GameWorld::accessWorld().setLevel(input.left(slPos).toInt());

    int count = slPos + 1;
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

    GameWorld::accessWorld().setDifficulty(3);

    //make gamewindow and show it
    gamewindow = new GameWindow(music);

    //create the GUIBricks for a level
    gamewindow->renderLevel();

    //set the position of the gamewindow
    gamewindow->setGeometry(373, 0, 642, 608);

    //stop the music
    music->stop();

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



