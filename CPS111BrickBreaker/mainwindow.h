#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "gamewindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnPlay_clicked();

    void on_btnHowToPlay_clicked();

    void on_btnHighScores_clicked();

    void on_btnMultiplayer_clicked();

private:
    Ui::MainWindow *mainui;
};

#endif // MAINWINDOW_H
