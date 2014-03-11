#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QWidget>

namespace Ui {
class InputDialog;
}

class InputDialog : public QWidget
{
    Q_OBJECT
    
private:
    Ui::InputDialog *inputui;

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

public:
    explicit InputDialog(QWidget *parent = 0);

    //method that specifically exists to set the focus on the "enter name" box when this window is shown
    void setFocusOnLineEdit();

    ~InputDialog();

};

#endif // INPUTDIALOG_H
