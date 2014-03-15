/********************************************************************************
** Form generated from reading UI file 'highscorewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCOREWINDOW_H
#define UI_HIGHSCOREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScoreWindow
{
public:
    QLabel *lblHighScoreTitle;
    QPushButton *btnResetScores;
    QLabel *label;
    QLabel *lblSPHS;

    void setupUi(QWidget *HighScoreWindow)
    {
        if (HighScoreWindow->objectName().isEmpty())
            HighScoreWindow->setObjectName(QStringLiteral("HighScoreWindow"));
        HighScoreWindow->resize(557, 514);
        lblHighScoreTitle = new QLabel(HighScoreWindow);
        lblHighScoreTitle->setObjectName(QStringLiteral("lblHighScoreTitle"));
        lblHighScoreTitle->setGeometry(QRect(70, 30, 401, 81));
        lblHighScoreTitle->setPixmap(QPixmap(QString::fromUtf8(":/images/highscore.png")));
        btnResetScores = new QPushButton(HighScoreWindow);
        btnResetScores->setObjectName(QStringLiteral("btnResetScores"));
        btnResetScores->setGeometry(QRect(180, 440, 171, 27));
        label = new QLabel(HighScoreWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 120, 111, 31));
        lblSPHS = new QLabel(HighScoreWindow);
        lblSPHS->setObjectName(QStringLiteral("lblSPHS"));
        lblSPHS->setGeometry(QRect(10, 150, 531, 271));

        retranslateUi(HighScoreWindow);

        QMetaObject::connectSlotsByName(HighScoreWindow);
    } // setupUi

    void retranslateUi(QWidget *HighScoreWindow)
    {
        HighScoreWindow->setWindowTitle(QApplication::translate("HighScoreWindow", "Form", 0));
        lblHighScoreTitle->setText(QString());
        btnResetScores->setText(QApplication::translate("HighScoreWindow", "Reset High Scores", 0));
        label->setText(QApplication::translate("HighScoreWindow", "Single Player", 0));
        lblSPHS->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HighScoreWindow: public Ui_HighScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCOREWINDOW_H
