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
