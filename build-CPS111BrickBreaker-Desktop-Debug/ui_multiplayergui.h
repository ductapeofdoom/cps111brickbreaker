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
#include <QtWidgets/QHBoxLayout>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblNumClients;
    QLabel *lblClients;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblConnectionStatus;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *lblServerStatus;

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
        btnStartServer->setCheckable(true);
        btnConnect = new QPushButton(MultiplayerGUI);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(120, 360, 261, 31));
        widget = new QWidget(MultiplayerGUI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(120, 220, 218, 19));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblNumClients = new QLabel(widget);
        lblNumClients->setObjectName(QStringLiteral("lblNumClients"));

        horizontalLayout->addWidget(lblNumClients);

        lblClients = new QLabel(widget);
        lblClients->setObjectName(QStringLiteral("lblClients"));

        horizontalLayout->addWidget(lblClients);

        widget1 = new QWidget(MultiplayerGUI);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(120, 420, 232, 19));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lblConnectionStatus = new QLabel(widget1);
        lblConnectionStatus->setObjectName(QStringLiteral("lblConnectionStatus"));
        lblConnectionStatus->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_2->addWidget(lblConnectionStatus);

        widget2 = new QWidget(MultiplayerGUI);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(120, 170, 338, 19));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lblServerStatus = new QLabel(widget2);
        lblServerStatus->setObjectName(QStringLiteral("lblServerStatus"));
        lblServerStatus->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_3->addWidget(lblServerStatus);


        retranslateUi(MultiplayerGUI);

        QMetaObject::connectSlotsByName(MultiplayerGUI);
    } // setupUi

    void retranslateUi(QWidget *MultiplayerGUI)
    {
        MultiplayerGUI->setWindowTitle(QApplication::translate("MultiplayerGUI", "Multiplayer", 0));
        label->setText(QString());
        btnStartServer->setText(QApplication::translate("MultiplayerGUI", "Start TCP Server", 0));
        btnConnect->setText(QApplication::translate("MultiplayerGUI", "Connect to TCP Server", 0));
        lblNumClients->setText(QApplication::translate("MultiplayerGUI", "Number of Clients Connected:", 0));
        lblClients->setText(QString());
        label_2->setText(QApplication::translate("MultiplayerGUI", " Connection Status: ", 0));
        lblConnectionStatus->setText(QApplication::translate("MultiplayerGUI", "Disconnected", 0));
        label_3->setText(QApplication::translate("MultiplayerGUI", "Server Status:", 0));
        lblServerStatus->setText(QApplication::translate("MultiplayerGUI", "Offline", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiplayerGUI: public Ui_MultiplayerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYERGUI_H
