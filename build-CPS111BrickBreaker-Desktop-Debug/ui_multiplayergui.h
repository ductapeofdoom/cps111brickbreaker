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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiplayerGUI
{
public:
    QLabel *label;
    QPushButton *btnStartServer;
    QPushButton *btnConnect;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblNumClients;
    QLabel *lblClients;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *lblConnectionStatus;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *lblServerStatus;
    QLineEdit *lnServer;

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
        btnConnect->setGeometry(QRect(120, 360, 161, 31));
        layoutWidget = new QWidget(MultiplayerGUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(120, 220, 218, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblNumClients = new QLabel(layoutWidget);
        lblNumClients->setObjectName(QStringLiteral("lblNumClients"));

        horizontalLayout->addWidget(lblNumClients);

        lblClients = new QLabel(layoutWidget);
        lblClients->setObjectName(QStringLiteral("lblClients"));

        horizontalLayout->addWidget(lblClients);

        layoutWidget1 = new QWidget(MultiplayerGUI);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 420, 232, 19));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lblConnectionStatus = new QLabel(layoutWidget1);
        lblConnectionStatus->setObjectName(QStringLiteral("lblConnectionStatus"));
        lblConnectionStatus->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_2->addWidget(lblConnectionStatus);

        layoutWidget2 = new QWidget(MultiplayerGUI);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(120, 170, 338, 19));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lblServerStatus = new QLabel(layoutWidget2);
        lblServerStatus->setObjectName(QStringLiteral("lblServerStatus"));
        lblServerStatus->setStyleSheet(QStringLiteral("color: red;"));

        horizontalLayout_3->addWidget(lblServerStatus);

        lnServer = new QLineEdit(MultiplayerGUI);
        lnServer->setObjectName(QStringLiteral("lnServer"));
        lnServer->setGeometry(QRect(290, 360, 113, 27));

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
        lnServer->setText(QApplication::translate("MultiplayerGUI", "localhost", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiplayerGUI: public Ui_MultiplayerGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLAYERGUI_H
