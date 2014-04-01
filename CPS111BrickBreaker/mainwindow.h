/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *mainwindow.h - this file contains class definitions and method declarations for the
 *               MainWindow class.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>

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

    void playMusic();
    void stopMusic();
    
private slots:
    void on_btnPlay_clicked();

    void on_btnHowToPlay_clicked();

    void on_btnHighScores_clicked();

    void on_btnLoad_clicked();

    void on_btnMultiplayer_clicked();

private:
    Ui::MainWindow *mainui;
    QSound * music;
};

#endif // MAINWINDOW_H
