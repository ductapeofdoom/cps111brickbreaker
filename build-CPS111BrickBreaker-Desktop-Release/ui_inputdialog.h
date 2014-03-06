/********************************************************************************
** Form generated from reading UI file 'inputdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTDIALOG_H
#define UI_INPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_inputDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *cmbBoxDifficultyLevels;
    QLabel *lblDifficulty;
    QLabel *lblPlayerName;
    QLineEdit *lineEditPlayerName;

    void setupUi(QDialog *inputDialog)
    {
        if (inputDialog->objectName().isEmpty())
            inputDialog->setObjectName(QStringLiteral("inputDialog"));
        inputDialog->resize(325, 167);
        buttonBox = new QDialogButtonBox(inputDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 120, 271, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        cmbBoxDifficultyLevels = new QComboBox(inputDialog);
        cmbBoxDifficultyLevels->setObjectName(QStringLiteral("cmbBoxDifficultyLevels"));
        cmbBoxDifficultyLevels->setGeometry(QRect(150, 60, 151, 27));
        lblDifficulty = new QLabel(inputDialog);
        lblDifficulty->setObjectName(QStringLiteral("lblDifficulty"));
        lblDifficulty->setGeometry(QRect(20, 60, 91, 17));
        lblPlayerName = new QLabel(inputDialog);
        lblPlayerName->setObjectName(QStringLiteral("lblPlayerName"));
        lblPlayerName->setGeometry(QRect(20, 20, 111, 17));
        lineEditPlayerName = new QLineEdit(inputDialog);
        lineEditPlayerName->setObjectName(QStringLiteral("lineEditPlayerName"));
        lineEditPlayerName->setGeometry(QRect(150, 10, 151, 27));

        retranslateUi(inputDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), inputDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), inputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(inputDialog);
    } // setupUi

    void retranslateUi(QDialog *inputDialog)
    {
        inputDialog->setWindowTitle(QApplication::translate("inputDialog", "Player Name", 0));
        cmbBoxDifficultyLevels->clear();
        cmbBoxDifficultyLevels->insertItems(0, QStringList()
         << QApplication::translate("inputDialog", "Easy", 0)
         << QApplication::translate("inputDialog", "Medium", 0)
         << QApplication::translate("inputDialog", "Hard", 0)
        );
        lblDifficulty->setText(QApplication::translate("inputDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Difficulty:</span></p></body></html>", 0));
        lblPlayerName->setText(QApplication::translate("inputDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Player Name:</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class inputDialog: public Ui_inputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
