/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *savemanager.h - this file contains class definitions and method declarations for the
 *                SaveManager class.
 */

#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "gamewindow.h"
#include "mainwindow.h"

#include <QString>
#include <QSound>

class SaveManager
{
    QString filepath;
    GameWindow * gamewindow;
    MainWindow * mainwindow;
    QSound * music;
public:
    SaveManager(GameWindow *, QSound *);
    SaveManager(MainWindow *, QSound *);

    void SaveGame();

    void LoadGame();
};

#endif // SAVEMANAGER_H
