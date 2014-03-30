/*CPS111 Team Project
 *Team 4: Stephen Sidwell, Nick Marsceau, and Daniel Tan
 *highscorewindow.h - this file contains class definitions and method declarations for the
 *                    HighScoreWindow class.
 */

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

private slots:
    void on_btnResetScores_clicked();
};

#endif // HIGHSCOREWINDOW_H
