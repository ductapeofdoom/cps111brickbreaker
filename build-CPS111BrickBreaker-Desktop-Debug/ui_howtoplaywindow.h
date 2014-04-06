/********************************************************************************
** Form generated from reading UI file 'howtoplaywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOWTOPLAYWINDOW_H
#define UI_HOWTOPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HowToPlayWindow
{
public:
    QLabel *lblHowToPlay;
    QTextBrowser *txtBrowserInstructions;
    QPushButton *btnOk;

    void setupUi(QWidget *HowToPlayWindow)
    {
        if (HowToPlayWindow->objectName().isEmpty())
            HowToPlayWindow->setObjectName(QStringLiteral("HowToPlayWindow"));
        HowToPlayWindow->resize(686, 510);
        lblHowToPlay = new QLabel(HowToPlayWindow);
        lblHowToPlay->setObjectName(QStringLiteral("lblHowToPlay"));
        lblHowToPlay->setGeometry(QRect(0, 0, 681, 61));
        txtBrowserInstructions = new QTextBrowser(HowToPlayWindow);
        txtBrowserInstructions->setObjectName(QStringLiteral("txtBrowserInstructions"));
        txtBrowserInstructions->setGeometry(QRect(10, 60, 661, 391));
        btnOk = new QPushButton(HowToPlayWindow);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(300, 470, 98, 27));

        retranslateUi(HowToPlayWindow);

        QMetaObject::connectSlotsByName(HowToPlayWindow);
    } // setupUi

    void retranslateUi(QWidget *HowToPlayWindow)
    {
        HowToPlayWindow->setWindowTitle(QApplication::translate("HowToPlayWindow", "How To Play", 0));
        lblHowToPlay->setText(QApplication::translate("HowToPlayWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:600;\">How To Play</span></p></body></html>", 0));
        txtBrowserInstructions->setHtml(QApplication::translate("HowToPlayWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Starting A Game</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To start a new game, click the &quot;New Game&quot; button on the main menu. You will be asked for your name and your desired difficulty. Once you have provided that information and clicked 'Ok,' the game will open up on level 1.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><sp"
                        "an style=\" font-size:14pt; font-weight:600;\">Playing The Game</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To start the game with arrow key control, press tab and then use the left or right arrow on the keyboard to launch the ball. To start the game with mouse control (default), click and drag the paddle to launch the ball. The ball will be launched toward whichever side of the paddle you click on. The ball will bounce around the screen hitting bricks. Your job is to keep it from falling off the bottom of the screen by bouncing the ball with your paddle. As long as you hit the ball with your paddle each time it goes down to the bottom of the screen, it will continue to bounce back up and hit more bricks.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Each time you fail to catch the ball as it falls down the screen, you will lose a lif"
                        "e. You can see the number of lives on the right side of the gameplay window. Once you lose all of your lives, you will die. You will have the option of quitting or starting over at level 1.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Once you break all the bricks in a level, you will have the option to go to the next level or quit.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Save and Load a Game</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you would like to quit and come back to the game later, you can save your game by clicking &quot;Save Game&quot; in the gameplay window. From the main menu, you can click &quot;Load&quot; to open up the last saved game. It will pick up right where you left off "
                        "when you saved.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Multiplayer</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To play with a friend online, have two people open up the game. Have both people select &quot;Multiplayer&quot; from the main menu. A second window should open up, and ONLY ONE person needs to click &quot;Start TCP Server.&quot; The host, the person who started the server, needs to tell the other player, the client, what his IP address is, and the client needs to put that IP address into the text box beside &quot;Connect to TCP Server.&quot; After the client has provided the IP address of the host, both players can click &quot;Connect to TCP Server&quot; to connect. Players should follow the on-screen prompts to proceed to play the game.</p>\n"
"<p style=\" margin-top:1"
                        "2px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Highscores</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">When you die or end the game, if your score is higher than other players' scores, your score will be added to the high scores list! You can view your high scores by clicking &quot;High Scores&quot; on the main menu.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Cheating</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">If you just can't seem to win, try cheating! During gameplay, look at the bottom of the game window. There are four buttons marked &quot;Cheats.&quot; &quot;No Death&quot; prevents th"
                        "e ball from ever going off the bottom of the screen. &quot;Slow Ball&quot; and &quot;Speed Ball&quot; slow the ball down and speed the ball up respectively. It is not possible to have both of these enabled at the same time. Finally, &quot;Add Life&quot; adds one life to your number of lives. You can add as many lives as you want to.</p></body></html>", 0));
        btnOk->setText(QApplication::translate("HowToPlayWindow", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class HowToPlayWindow: public Ui_HowToPlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOWTOPLAYWINDOW_H
