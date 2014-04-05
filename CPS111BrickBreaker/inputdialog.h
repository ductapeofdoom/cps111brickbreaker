/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *inputdialog.h - this file contains class definitions and method declarations for the
 *                InputDialog class.
 */

#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QWidget>
#include <QSound>

namespace Ui {
class InputDialog;
}

class InputDialog : public QWidget
{
    Q_OBJECT
    
private:
    Ui::InputDialog *inputui;
    QSound * music;

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

public:
    explicit InputDialog(QSound * newmusic, QWidget *parent = 0);

    //method that specifically exists to set the focus on the "enter name" box when this window is shown
    void setFocusOnLineEdit();

    ~InputDialog();

};

#endif // INPUTDIALOG_H
