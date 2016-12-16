#ifndef CITATIONGAME_H
#define CITATIONGAME_H

#include <QDialog>

namespace Ui {
class CitationGame;
}

class CitationGame : public QDialog
{
    Q_OBJECT

public:
    explicit CitationGame(QWidget *parent = 0);
    ~CitationGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CitationGame *ui;
};

#endif // CITATIONGAME_H
