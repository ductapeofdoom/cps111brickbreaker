#ifndef HOWTOPLAYWINDOW_H
#define HOWTOPLAYWINDOW_H

#include <QWidget>

namespace Ui {
class HowToPlayWindow;
}

class HowToPlayWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit HowToPlayWindow(QWidget *parent = 0);
    ~HowToPlayWindow();
    
private slots:
    void on_btnOk_clicked();

private:
    Ui::HowToPlayWindow *ui;
};

#endif // HOWTOPLAYWINDOW_H
