/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *inputdialog.cpp - this file contains method definitions for the
 *                  InputDialog class.
 */

#include <QString>
#include <QMessageBox>
#include <QDebug>

#include "inputdialog.h"
#include "ui_inputdialog.h"
#include "gameworld.h"
#include "gamewindow.h"

InputDialog::InputDialog(QWidget *parent) :
    QWidget(parent),
    inputui(new Ui::InputDialog)
{
    inputui->setupUi(this);
}
//method that specifically exists to set the focus on the "enter name" box when this window is shown
void InputDialog::setFocusOnLineEdit()
{
    inputui->lineEditName->setFocus();
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

    this->close();

    GameWorld::accessWorld().setPlayerName(name);
    GameWorld::accessWorld().setDifficulty(difficulty);

    //create the bricks for a level
    GameWorld::accessWorld().makeLevel();

    //make gamewindow and show it
    GameWindow* gamewindow = new GameWindow();

    //create the GUIBricks for a level
    gamewindow->renderLevel();

    //show the game window
    gamewindow->show();
}

void InputDialog::on_btnCancel_clicked()
{
   this->close();
}
