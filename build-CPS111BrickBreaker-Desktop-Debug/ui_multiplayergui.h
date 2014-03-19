/********************************************************************************
** Form generated from reading UI file 'multiplayergui.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLAYERGUI_H
#define UI_MULTIPLAYERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiplayerGUI
{
public:
    QLabel *label;
    QPushButton *btnStartServer;
    QPushButton *btnConnect;
    QLabel *lblServerStatus;
    QLabel *lblConnectionStatus;

    void setupUi(QWidget *MultiplayerGUI)
    {
        if (MultiplayerGUI->objectName().isEmpty())
            MultiplayerGUI->setObjectName(QStringLiteral("MultiplayerGUI"));
        MultiplayerGUI->resize(512, 487);
        label = new QLabel(MultiplayerGUI);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 10, 431, 81));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/multiplayer.png")));
        btnStartServer = new QPushButton(MultiplayerGUI);
        btnStartServer->setObjectName(QStringLiteral("btnStartServer"));
        btnStartServer->setGeometry(QRect(120, 130, 261, 31));
        btnConnect = new QPushButton(MultiplayerGUI);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(120, 360, 261, 31));
        lblServerStatus = new QLabel(MultiplayerGUI);
        lblServerStatus->setObjectName(QStringLiteral("lblServerStatus"));
        lblServerStatus->setGeometry(QRect(120, 170, 251, 151));
        lblConnectionStatus = new QLabel(MultiplayerGUI);
        lblConnectionStatus->setObjectName(QStringLiteral("lblConnectionStatus"));
        lblConnectionStatus->setGeometry(QRect(120, 410, 251, 51));

        retranslateUi(MultiplayerGUI);

        QMetaObject::connectSlotsByName(MultiplayerGUI);
    } // setupUi

    void retranslateUi(QWidget *MultiplayerGUI)
    {
        MultiplayerGUI->setWindowTitle(QApplication::translate("MultiplayerGUI", "Form", 0));
        label->setText(QString());
        btnStartServer->setText(QApplication::translate("MultiplayerGUI", "Start TCP Server", 0));
        btnConnect->setText(QApplication::translate("MultiplayerGUI", "Connect to TCP Server", 0));
        lblServerStatus->setText(QApplication::translate("MultiplayerGUI", "Server Status:", 0));
        lblConnectionStatus->setText(QApplication::translate("MultiplayerGUI", "Connection Status:", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiplayerGUI: public Ui_MultiplayerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYERGUI_H
