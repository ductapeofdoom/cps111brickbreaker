#ifndef HIGHSCOREWINDOW_H
#define HIGHSCOREWINDOW_H

#include <QWidget>
#include <QString>

namespace Ui {
class HighScoreWindow;
}

class HighScoreWindow : public QWidget
{
    Q_OBJECT

private:
    Ui::HighScoreWindow *highScoreUi;

public:
    explicit HighScoreWindow(QWidget *parent = 0);
    ~HighScoreWindow();

    void setSPScoresLabel(QString scores);

    void showHS();

};

#endif // HIGHSCOREWINDOW_H
