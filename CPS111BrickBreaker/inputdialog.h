#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui {
class inputDialog;
}

class inputDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit inputDialog(QWidget *parent = 0);
    ~inputDialog();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::inputDialog *inputui;
};

#endif // INPUTDIALOG_H
