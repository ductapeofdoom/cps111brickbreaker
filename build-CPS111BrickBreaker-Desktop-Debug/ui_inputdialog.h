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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputDialog
{
public:
    QPushButton *btnOk;
    QPushButton *btnCancel;
    QLabel *lblEnterYourName;
    QLineEdit *lineEditName;
    QLabel *lblSelectDifficulty;
    QComboBox *cmbBoxDifficulty;

    void setupUi(QWidget *InputDialog)
    {
        if (InputDialog->objectName().isEmpty())
            InputDialog->setObjectName(QStringLiteral("InputDialog"));
        InputDialog->resize(400, 168);
        InputDialog->setFocusPolicy(Qt::TabFocus);
        btnOk = new QPushButton(InputDialog);
        btnOk->setObjectName(QStringLiteral("btnOk"));
        btnOk->setGeometry(QRect(280, 120, 98, 27));
        btnCancel = new QPushButton(InputDialog);
        btnCancel->setObjectName(QStringLiteral("btnCancel"));
        btnCancel->setGeometry(QRect(170, 120, 98, 27));
        btnCancel->setFocusPolicy(Qt::StrongFocus);
        lblEnterYourName = new QLabel(InputDialog);
        lblEnterYourName->setObjectName(QStringLiteral("lblEnterYourName"));
        lblEnterYourName->setGeometry(QRect(10, 10, 151, 51));
        lineEditName = new QLineEdit(InputDialog);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(180, 20, 201, 27));
        lblSelectDifficulty = new QLabel(InputDialog);
        lblSelectDifficulty->setObjectName(QStringLiteral("lblSelectDifficulty"));
        lblSelectDifficulty->setGeometry(QRect(10, 60, 151, 51));
        cmbBoxDifficulty = new QComboBox(InputDialog);
        cmbBoxDifficulty->setObjectName(QStringLiteral("cmbBoxDifficulty"));
        cmbBoxDifficulty->setGeometry(QRect(180, 70, 201, 27));
        cmbBoxDifficulty->setFocusPolicy(Qt::StrongFocus);

        retranslateUi(InputDialog);

        QMetaObject::connectSlotsByName(InputDialog);
    } // setupUi

    void retranslateUi(QWidget *InputDialog)
    {
        InputDialog->setWindowTitle(QApplication::translate("InputDialog", "Enter Name", 0));
        btnOk->setText(QApplication::translate("InputDialog", "Ok", 0));
        btnCancel->setText(QApplication::translate("InputDialog", "Cancel", 0));
        lblEnterYourName->setText(QApplication::translate("InputDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Enter your name:</span></p></body></html>", 0));
        lineEditName->setText(QApplication::translate("InputDialog", "Player 1", 0));
        lblSelectDifficulty->setText(QApplication::translate("InputDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Select Difficulty:</span></p></body></html>", 0));
        cmbBoxDifficulty->clear();
        cmbBoxDifficulty->insertItems(0, QStringList()
         << QApplication::translate("InputDialog", "Easy", 0)
         << QApplication::translate("InputDialog", "Medium", 0)
         << QApplication::translate("InputDialog", "Hard", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class InputDialog: public Ui_InputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTDIALOG_H
