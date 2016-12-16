#ifndef CITATIONGAME_H
#define CITATIONGAME_H

#include <QDialog>
#include <QMessageBox>

#include "service/scientistservice.h"

namespace Ui {
class CitationGame;
}

class CitationGame : public QDialog
{
    Q_OBJECT

public:
    explicit CitationGame(QWidget *parent = 0);
    ~CitationGame();

    void setScore(int score);
    int getScore();

    void playCitation();

    void displayCitation();
    void displayScore();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CitationGame *ui;

    ScientistService _serviceSci;

    Scientist _sci;

    int _score;
};

#endif // CITATIONGAME_H
