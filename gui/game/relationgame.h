#ifndef RELATIONGAME_H
#define RELATIONGAME_H

#include <QDialog>

namespace Ui {
class RelationGame;
}

class RelationGame : public QDialog
{
    Q_OBJECT

public:
    explicit RelationGame(QWidget *parent = 0);
    ~RelationGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RelationGame *ui;
};

#endif // RELATIONGAME_H
