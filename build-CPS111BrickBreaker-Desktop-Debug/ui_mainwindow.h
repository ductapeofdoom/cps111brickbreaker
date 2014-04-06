/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lblTitle;
    QPushButton *btnPlay;
    QPushButton *btnHowToPlay;
    QPushButton *btnMultiplayer;
    QPushButton *btnHighScores;
    QPushButton *btnLoad;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(491, 585);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lblTitle = new QLabel(centralWidget);
        lblTitle->setObjectName(QStringLiteral("lblTitle"));
        lblTitle->setGeometry(QRect(40, 0, 411, 161));
        lblTitle->setPixmap(QPixmap(QString::fromUtf8(":/images/brickbreaker.png")));
        lblTitle->setScaledContents(true);
        btnPlay = new QPushButton(centralWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setGeometry(QRect(70, 220, 351, 81));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/newgame.png"), QSize(), QIcon::Normal, QIcon::On);
        btnPlay->setIcon(icon);
        btnPlay->setIconSize(QSize(350, 400));
        btnHowToPlay = new QPushButton(centralWidget);
        btnHowToPlay->setObjectName(QStringLiteral("btnHowToPlay"));
        btnHowToPlay->setGeometry(QRect(130, 400, 231, 41));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/howto.png"), QSize(), QIcon::Normal, QIcon::On);
        btnHowToPlay->setIcon(icon1);
        btnHowToPlay->setIconSize(QSize(225, 45));
        btnMultiplayer = new QPushButton(centralWidget);
        btnMultiplayer->setObjectName(QStringLiteral("btnMultiplayer"));
        btnMultiplayer->setEnabled(true);
        btnMultiplayer->setGeometry(QRect(130, 500, 231, 41));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/multiplayer.png"), QSize(), QIcon::Normal, QIcon::On);
        btnMultiplayer->setIcon(icon2);
        btnMultiplayer->setIconSize(QSize(350, 45));
        btnHighScores = new QPushButton(centralWidget);
        btnHighScores->setObjectName(QStringLiteral("btnHighScores"));
        btnHighScores->setGeometry(QRect(130, 450, 231, 41));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/highscore.png"), QSize(), QIcon::Normal, QIcon::On);
        btnHighScores->setIcon(icon3);
        btnHighScores->setIconSize(QSize(225, 45));
        btnLoad = new QPushButton(centralWidget);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setEnabled(true);
        btnLoad->setGeometry(QRect(150, 310, 191, 71));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/load.png"), QSize(), QIcon::Normal, QIcon::On);
        btnLoad->setIcon(icon4);
        btnLoad->setIconSize(QSize(150, 150));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Brick Breaker!", 0));
        lblTitle->setText(QString());
        btnPlay->setText(QString());
        btnHowToPlay->setText(QString());
        btnMultiplayer->setText(QString());
        btnHighScores->setText(QString());
        btnLoad->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
