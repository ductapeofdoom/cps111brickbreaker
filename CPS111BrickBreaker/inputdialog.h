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
    
private:
    Ui::inputDialog *ui;
};

#endif // INPUTDIALOG_H