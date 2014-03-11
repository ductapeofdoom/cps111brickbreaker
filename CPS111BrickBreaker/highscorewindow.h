#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include <QWidget>

namespace Ui {
class HighScoreWindow;
}

class HighScoreWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit HighScoreWindow(QWidget *parent = 0);
    ~HighScoreWindow();

    void showHS();
    
private:
    Ui::HighScoreWindow *highScoreUi;
};

#endif // HIGHSCOREWINDOW_H
