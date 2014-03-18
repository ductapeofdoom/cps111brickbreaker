#ifndef MULTIPLAYERGUI_H
#define MULTIPLAYERGUI_H

#include <QWidget>
#include <QThread>
#include <QTcpServer>

namespace Ui {
class MultiplayerGUI;
}

class ServerObject :  public QObject{

    Q_OBJECT

private:
    QTcpServer * server;
private slots:
    void clientConnected();
public:
    ServerObject(QTcpServer * newServer): server(newServer){}
    void connectSlots();
};

class ServerThread : public QThread{

private:
    ServerObject * servObj;
    QWidget * parentWindow;
public:
    ServerThread(QWidget * parent): parentWindow(parent) {}
    void run();
};

class MultiplayerGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplayerGUI(QWidget *parent = 0);
    ~MultiplayerGUI();
    
private:
    ServerThread * serverThread;
    Ui::MultiplayerGUI *ui;
};

#endif // MULTIPLAYERGUI_H
