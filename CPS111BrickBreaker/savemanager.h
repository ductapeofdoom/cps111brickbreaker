/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *savemanager.h - this file contains class definitions and method declarations for the
 *                SaveManager class.
 */

#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include <QString>

class SaveManager
{
    QString filepath;
public:
    SaveManager();

    void SaveGame();

    void LoadGame();
};

#endif // SAVEMANAGER_H
