#include "citationgame.h"
#include "ui_citationgame.h"

CitationGame::CitationGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CitationGame)
{
    ui->setupUi(this);
}

CitationGame::~CitationGame()
{
    delete ui;
}
