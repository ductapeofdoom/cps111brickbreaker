#include <QString>
#include <QMessageBox>
#include <QDebug>

#include "inputdialog.h"
#include "ui_inputdialog.h"
#include "gameworld.h"

InputDialog::InputDialog(QWidget *parent) :
    QWidget(parent),
    inputui(new Ui::InputDialog)
{
    inputui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete inputui;
}

void InputDialog::on_btnOk_clicked()
{
    QString name = inputui->lineEditName->text();
    int difficulty = inputui->cmbBoxDifficulty->currentIndex();

    if (name == "" || name == NULL){
        QMessageBox::warning(this, "Error", "Please provide a name.");
        return;
    }

    delete this;


    GameWorld::accessWorld().setPlayerName(name);
    GameWorld::accessWorld().setDifficulty(difficulty);

    qDebug() << name << " " << difficulty;

}

void InputDialog::on_btnCancel_clicked()
{
    delete this;
}
