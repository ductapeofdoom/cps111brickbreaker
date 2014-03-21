#ifndef MULTIPLAYERGUI_H
#define MULTIPLAYERGUI_H

#include "gamewindow.h"

#include <QWidget>
#include <QThread>
#include <QTcpServer>
#include <QString>
#include <vector>
using namespace std;

namespace Ui {
class MultiplayerGUI;
}

class ProcessThread :public QThread{
    GameWindow * window;
    QString input;
    GUIBrick * resultBrick;
public:
    ProcessThread(GameWindow * win): window(win), resultBrick(NULL){}
    void run();

    GUIBrick * getResult() {return resultBrick;}

    void setInput(QString text){input = text;}
};

class ServerProcessThread: public QThread{
    QTcpSocket * socket;
    vector<QTcpSocket*> currentConnections;
public:
    ServerProcessThread(QTcpSocket * sock, vector<QTcpSocket*> connections): socket(sock), currentConnections(connections){}
    void run();
};

class MultiplayerGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerGUI(QWidget *parent = 0);
    ~MultiplayerGUI();

    void processInput(QString input);

    void GenerateMuliWorld(QString input);

private slots:
    void clientConnected();
    void clientDisconnected();
    void dataRecieved();
    void on_btnStartServer_clicked();

    void on_btnConnect_clicked();

    void clientDataRecieved();

    void serverDisconnected();

    void processFinished();

    void serverProcessFinished();
private:
    QTcpServer * server;
    QTcpSocket * clientSock;
    GameWindow * gamewindow;
    int clientCount;
    vector<QTcpSocket*> currentConnections;
    Ui::MultiplayerGUI *ui;
};

#endif // MULTIPLAYERGUI_H
