#include "relationgame.h"
#include "ui_relationgame.h"

RelationGame::RelationGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RelationGame)
{
    ui->setupUi(this);
}

RelationGame::~RelationGame()
{
    delete ui;
}
