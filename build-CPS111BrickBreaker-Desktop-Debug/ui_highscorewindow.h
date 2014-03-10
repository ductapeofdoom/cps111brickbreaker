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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScoreWindow
{
public:

    void setupUi(QWidget *HighScoreWindow)
    {
        if (HighScoreWindow->objectName().isEmpty())
            HighScoreWindow->setObjectName(QStringLiteral("HighScoreWindow"));
        HighScoreWindow->resize(400, 300);

        retranslateUi(HighScoreWindow);

        QMetaObject::connectSlotsByName(HighScoreWindow);
    } // setupUi

    void retranslateUi(QWidget *HighScoreWindow)
    {
        HighScoreWindow->setWindowTitle(QApplication::translate("HighScoreWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class HighScoreWindow: public Ui_HighScoreWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCOREWINDOW_H
