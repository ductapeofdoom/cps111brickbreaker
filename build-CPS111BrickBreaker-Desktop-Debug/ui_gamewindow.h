/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *wdGame;
    QLabel *lblCurrentHighScore;
    QPushButton *btnPause;
    QLabel *lblCHS;
    QLabel *lblCurrentPlayersName;
    QLabel *lblCPN;
    QLabel *lblLevel_2;
    QLabel *lblLevel;
    QLabel *lblCurrentDifficulty;
    QLabel *lblDifficult;
    QLabel *lblPowerup_2;
    QLabel *lblTimeLeft;
    QLabel *lblPowerTime;
    QLabel *lblPowerup;
    QLabel *lblOName;
    QLabel *lblOScore;
    QLabel *lblNumberOfLives;
    QLabel *lblLife;

    void setupUi(QWidget *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QStringLiteral("GameWindow"));
        GameWindow->resize(642, 588);
        wdGame = new QWidget(GameWindow);
        wdGame->setObjectName(QStringLiteral("wdGame"));
        wdGame->setGeometry(QRect(30, 30, 400, 500));
        wdGame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lblCurrentHighScore = new QLabel(GameWindow);
        lblCurrentHighScore->setObjectName(QStringLiteral("lblCurrentHighScore"));
        lblCurrentHighScore->setGeometry(QRect(450, 10, 141, 21));
        btnPause = new QPushButton(GameWindow);
        btnPause->setObjectName(QStringLiteral("btnPause"));
        btnPause->setGeometry(QRect(460, 410, 161, 51));
        btnPause->setFocusPolicy(Qt::NoFocus);
        btnPause->setCheckable(true);
        lblCHS = new QLabel(GameWindow);
        lblCHS->setObjectName(QStringLiteral("lblCHS"));
        lblCHS->setGeometry(QRect(510, 30, 66, 17));
        lblCurrentPlayersName = new QLabel(GameWindow);
        lblCurrentPlayersName->setObjectName(QStringLiteral("lblCurrentPlayersName"));
        lblCurrentPlayersName->setGeometry(QRect(30, 10, 161, 16));
        lblCPN = new QLabel(GameWindow);
        lblCPN->setObjectName(QStringLiteral("lblCPN"));
        lblCPN->setGeometry(QRect(210, 10, 181, 16));
        lblLevel_2 = new QLabel(GameWindow);
        lblLevel_2->setObjectName(QStringLiteral("lblLevel_2"));
        lblLevel_2->setGeometry(QRect(450, 60, 61, 16));
        lblLevel = new QLabel(GameWindow);
        lblLevel->setObjectName(QStringLiteral("lblLevel"));
        lblLevel->setGeometry(QRect(500, 60, 66, 17));
        lblCurrentDifficulty = new QLabel(GameWindow);
        lblCurrentDifficulty->setObjectName(QStringLiteral("lblCurrentDifficulty"));
        lblCurrentDifficulty->setGeometry(QRect(450, 346, 131, 20));
        lblDifficult = new QLabel(GameWindow);
        lblDifficult->setObjectName(QStringLiteral("lblDifficult"));
        lblDifficult->setGeometry(QRect(500, 370, 71, 21));
        lblPowerup_2 = new QLabel(GameWindow);
        lblPowerup_2->setObjectName(QStringLiteral("lblPowerup_2"));
        lblPowerup_2->setGeometry(QRect(450, 110, 66, 17));
        lblTimeLeft = new QLabel(GameWindow);
        lblTimeLeft->setObjectName(QStringLiteral("lblTimeLeft"));
        lblTimeLeft->setGeometry(QRect(450, 140, 71, 17));
        lblPowerTime = new QLabel(GameWindow);
        lblPowerTime->setObjectName(QStringLiteral("lblPowerTime"));
        lblPowerTime->setGeometry(QRect(550, 140, 91, 20));
        lblPowerup = new QLabel(GameWindow);
        lblPowerup->setObjectName(QStringLiteral("lblPowerup"));
        lblPowerup->setGeometry(QRect(520, 110, 111, 21));
        lblOName = new QLabel(GameWindow);
        lblOName->setObjectName(QStringLiteral("lblOName"));
        lblOName->setGeometry(QRect(450, 260, 131, 21));
        lblOScore = new QLabel(GameWindow);
        lblOScore->setObjectName(QStringLiteral("lblOScore"));
        lblOScore->setGeometry(QRect(450, 290, 131, 21));
        lblNumberOfLives = new QLabel(GameWindow);
        lblNumberOfLives->setObjectName(QStringLiteral("lblNumberOfLives"));
        lblNumberOfLives->setGeometry(QRect(450, 190, 121, 21));
        lblLife = new QLabel(GameWindow);
        lblLife->setObjectName(QStringLiteral("lblLife"));
        lblLife->setGeometry(QRect(580, 190, 31, 21));

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "Brick Breaker!", 0));
        lblCurrentHighScore->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Current High Score</span></p></body></html>", 0));
        btnPause->setText(QApplication::translate("GameWindow", "Pause", 0));
        lblCHS->setText(QApplication::translate("GameWindow", "0", 0));
        lblCurrentPlayersName->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Current Player's Name</span></p></body></html>", 0));
        lblCPN->setText(QApplication::translate("GameWindow", "(player name)", 0));
        lblLevel_2->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Level:</span></p></body></html>", 0));
        lblLevel->setText(QApplication::translate("GameWindow", "1", 0));
        lblCurrentDifficulty->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Current Difficulty</span></p></body></html>", 0));
        lblDifficult->setText(QString());
        lblPowerup_2->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Powerup:</span></p></body></html>", 0));
        lblTimeLeft->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Time Left</span></p></body></html>", 0));
        lblPowerTime->setText(QApplication::translate("GameWindow", "0 secs", 0));
        lblPowerup->setText(QApplication::translate("GameWindow", "(none)", 0));
        lblOName->setText(QString());
        lblOScore->setText(QString());
        lblNumberOfLives->setText(QApplication::translate("GameWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Number of Lives</span></p></body></html>", 0));
        lblLife->setText(QApplication::translate("GameWindow", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H