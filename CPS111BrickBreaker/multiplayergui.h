#ifndef MULTIPLAYERGUI_H
#define MULTIPLAYERGUI_H

#include <QWidget>
#include <QThread>
#include <QTcpServer>
#include <QString>
#include <vector>
using namespace std;

namespace Ui {
class MultiplayerGUI;
}

/*class ServerThread : public QThread{

private:
    QWidget * parentWindow;
    QTcpServer * server;
    QString errorMsg;
    int clientCount;
    bool endServer;
    QString lineRead;
public:
    ServerThread(QWidget * parent, QTcpServer * newServer): parentWindow(parent), server(newServer), errorMsg(""), clientCount(0), endServer(false) {}
    void run();

    int getClientCount() {return clientCount;}

    void incrementClientCount() {clientCount++;}

    void deincrementClientCount() {clientCount--;}

    void setEndServer(bool value){endServer = value;}

    void setLineRead(QString line) {lineRead = line;}
};*/

class MultiplayerGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerGUI(QWidget *parent = 0);
    ~MultiplayerGUI();

    void processInput(QString input);

private slots:
    void clientConnected();
    void clientDisconnected();
    void dataRecieved();
    void on_btnStartServer_clicked();

    void on_btnConnect_clicked();

    void clientDataRecieved();

    void serverDisconnected();

private:
    QTcpServer * server;
    QTcpSocket * clientSock;
    int clientCount;
    vector<QTcpSocket*> currentConnections;
    Ui::MultiplayerGUI *ui;
};

#endif // MULTIPLAYERGUI_H
