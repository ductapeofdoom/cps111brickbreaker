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
    QLabel *label;
    QPushButton *pushButton;
    QLabel *lblCHS;
    QLabel *label_2;
    QLabel *lblCPN;
    QLabel *label_3;
    QLabel *lblLevel;
    QLabel *label_4;
    QLabel *lblDifficult;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *lblPowerTime;
    QLabel *lblPowerup;
    QLabel *lblOName;
    QLabel *lblOScore;
    QLabel *label_8;
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
        label = new QLabel(GameWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(470, 10, 141, 21));
        pushButton = new QPushButton(GameWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(460, 410, 161, 51));
        lblCHS = new QLabel(GameWindow);
        lblCHS->setObjectName(QStringLiteral("lblCHS"));
        lblCHS->setGeometry(QRect(530, 30, 66, 17));
        label_2 = new QLabel(GameWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 161, 16));
        lblCPN = new QLabel(GameWindow);
        lblCPN->setObjectName(QStringLiteral("lblCPN"));
        lblCPN->setGeometry(QRect(210, 10, 181, 16));
        label_3 = new QLabel(GameWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 60, 61, 16));
        lblLevel = new QLabel(GameWindow);
        lblLevel->setObjectName(QStringLiteral("lblLevel"));
        lblLevel->setGeometry(QRect(530, 80, 66, 17));
        label_4 = new QLabel(GameWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(480, 350, 121, 16));
        lblDifficult = new QLabel(GameWindow);
        lblDifficult->setObjectName(QStringLiteral("lblDifficult"));
        lblDifficult->setGeometry(QRect(510, 370, 71, 21));
        label_5 = new QLabel(GameWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(450, 110, 66, 17));
        label_6 = new QLabel(GameWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(450, 140, 66, 17));
        lblPowerTime = new QLabel(GameWindow);
        lblPowerTime->setObjectName(QStringLiteral("lblPowerTime"));
        lblPowerTime->setGeometry(QRect(530, 140, 111, 16));
        lblPowerup = new QLabel(GameWindow);
        lblPowerup->setObjectName(QStringLiteral("lblPowerup"));
        lblPowerup->setGeometry(QRect(520, 110, 111, 21));
        lblOName = new QLabel(GameWindow);
        lblOName->setObjectName(QStringLiteral("lblOName"));
        lblOName->setGeometry(QRect(480, 260, 131, 21));
        lblOScore = new QLabel(GameWindow);
        lblOScore->setObjectName(QStringLiteral("lblOScore"));
        lblOScore->setGeometry(QRect(480, 290, 131, 21));
        label_8 = new QLabel(GameWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(480, 190, 121, 21));
        lblLife = new QLabel(GameWindow);
        lblLife->setObjectName(QStringLiteral("lblLife"));
        lblLife->setGeometry(QRect(530, 210, 81, 21));

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QWidget *GameWindow)
    {
        GameWindow->setWindowTitle(QApplication::translate("GameWindow", "Brick Breaker!", 0));
        label->setText(QApplication::translate("GameWindow", "Current High Score", 0));
        pushButton->setText(QApplication::translate("GameWindow", "Pause", 0));
        lblCHS->setText(QApplication::translate("GameWindow", "0", 0));
        label_2->setText(QApplication::translate("GameWindow", "Current Player's Name", 0));
        lblCPN->setText(QApplication::translate("GameWindow", "(player name)", 0));
        label_3->setText(QApplication::translate("GameWindow", "Level", 0));
        lblLevel->setText(QApplication::translate("GameWindow", "1", 0));
        label_4->setText(QApplication::translate("GameWindow", "Current Difficulty", 0));
        lblDifficult->setText(QString());
        label_5->setText(QApplication::translate("GameWindow", "Powerup:", 0));
        label_6->setText(QApplication::translate("GameWindow", "Time Left", 0));
        lblPowerTime->setText(QApplication::translate("GameWindow", "0 secs", 0));
        lblPowerup->setText(QApplication::translate("GameWindow", "(none)", 0));
        lblOName->setText(QString());
        lblOScore->setText(QString());
        label_8->setText(QApplication::translate("GameWindow", "Number of Lives", 0));
        lblLife->setText(QApplication::translate("GameWindow", "1", 0));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
