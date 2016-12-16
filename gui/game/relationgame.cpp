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

void RelationGame::on_pushButton_clicked()
{

}

void RelationGame::on_pushButton_2_clicked()
{

}
