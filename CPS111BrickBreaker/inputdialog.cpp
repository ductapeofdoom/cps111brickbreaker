#include "inputdialog.h"
#include "ui_inputdialog.h"

#include <QMessageBox>
#include <QString>

#include <string>

using namespace std;

inputDialog::inputDialog(QWidget *parent) :
    QDialog(parent),
    inputui(new Ui::inputDialog)
{
    inputui->setupUi(this);
}

inputDialog::~inputDialog()
{
    delete inputui;
}

void inputDialog::on_buttonBox_accepted()
{
    QString name = inputui->lineEditPlayerName->text();
    int difficulty = inputui->cmbBoxDifficultyLevels->currentIndex();

    if (name == NULL || name == ""){
        QMessageBox::critical(this, "AAAAAAAAAAAA!", "You must provide a name.");
    }
}
