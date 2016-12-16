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

private:
    Ui::RelationGame *ui;
};

#endif // RELATIONGAME_H
