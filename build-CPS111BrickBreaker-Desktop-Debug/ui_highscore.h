/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScore
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *HighScore)
    {
        if (HighScore->objectName().isEmpty())
            HighScore->setObjectName(QStringLiteral("HighScore"));
        HighScore->resize(529, 469);
        label = new QLabel(HighScore);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 401, 71));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/highscore.png")));
        pushButton = new QPushButton(HighScore);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 390, 181, 31));

        retranslateUi(HighScore);

        QMetaObject::connectSlotsByName(HighScore);
    } // setupUi

    void retranslateUi(QWidget *HighScore)
    {
        HighScore->setWindowTitle(QApplication::translate("HighScore", "Form", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("HighScore", "Reset High Scores", 0));
    } // retranslateUi

};

namespace Ui {
    class HighScore: public Ui_HighScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
