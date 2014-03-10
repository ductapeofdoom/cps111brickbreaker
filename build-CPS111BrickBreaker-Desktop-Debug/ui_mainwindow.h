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
    QLabel *label;
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
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 491, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/title.png")));
        label->setScaledContents(true);
        btnPlay = new QPushButton(centralWidget);
        btnPlay->setObjectName(QStringLiteral("btnPlay"));
        btnPlay->setGeometry(QRect(40, 110, 401, 91));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/newgame.png"), QSize(), QIcon::Normal, QIcon::On);
        btnPlay->setIcon(icon);
        btnPlay->setIconSize(QSize(400, 400));
        btnHowToPlay = new QPushButton(centralWidget);
        btnHowToPlay->setObjectName(QStringLiteral("btnHowToPlay"));
        btnHowToPlay->setGeometry(QRect(50, 340, 381, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/howto.png"), QSize(), QIcon::Normal, QIcon::On);
        btnHowToPlay->setIcon(icon1);
        btnHowToPlay->setIconSize(QSize(300, 300));
        btnMultiplayer = new QPushButton(centralWidget);
        btnMultiplayer->setObjectName(QStringLiteral("btnMultiplayer"));
        btnMultiplayer->setGeometry(QRect(50, 480, 381, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/multiplayer.png"), QSize(), QIcon::Normal, QIcon::On);
        btnMultiplayer->setIcon(icon2);
        btnMultiplayer->setIconSize(QSize(300, 300));
        btnHighScores = new QPushButton(centralWidget);
        btnHighScores->setObjectName(QStringLiteral("btnHighScores"));
        btnHighScores->setGeometry(QRect(50, 410, 381, 61));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/highscore.png"), QSize(), QIcon::Normal, QIcon::On);
        btnHighScores->setIcon(icon3);
        btnHighScores->setIconSize(QSize(300, 300));
        btnLoad = new QPushButton(centralWidget);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));
        btnLoad->setGeometry(QRect(120, 220, 241, 91));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/load.png"), QSize(), QIcon::Normal, QIcon::On);
        btnLoad->setIcon(icon4);
        btnLoad->setIconSize(QSize(200, 200));
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
        label->setText(QString());
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
