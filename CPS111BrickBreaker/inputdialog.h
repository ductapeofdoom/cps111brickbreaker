#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QWidget>

namespace Ui {
class InputDialog;
}

class InputDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();
    
private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::InputDialog *inputui;
};

#endif // INPUTDIALOG_H
