#include "citationgame.h"
#include "ui_citationgame.h"

CitationGame::CitationGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CitationGame)
{
    ui->setupUi(this);
    playCitation();
}

CitationGame::~CitationGame()
{
    delete ui;
}

void CitationGame::setScore(int score)
{
    _score = score;
}

int CitationGame::getScore()
{
    return _score;
}

void CitationGame::displayScore()
{
    ui -> tableWidget_2 -> clearContents();
    ui -> tableWidget_2 -> setRowCount(1);

    QString score = QString::number(_score);

    ui -> tableWidget_2-> setItem(0, 0, new QTableWidgetItem(score));
}

void CitationGame::displayCitation()
{
    ui -> tableWidget -> clearContents();
    ui -> tableWidget -> setRowCount(1);

    QString citation = QString::fromStdString(_sci.getCitation());

    ui -> tableWidget-> setItem(0, 0, new QTableWidgetItem(citation));
}

void CitationGame::playCitation()
{
    vector<Scientist> sci = _serviceSci.getScientists();

    int r = rand()%(sci.size()) + 0;

    _sci = sci[r];

    displayCitation();
}

void CitationGame::on_pushButton_clicked()
{
    close();
}

void CitationGame::on_pushButton_2_clicked()
{
    string guess = ui->lineEdit->text().toStdString();

    if (guess == _sci.getCitation())
    {
        QMessageBox::about(this, "You guessed Correctly!", "");
        _score++;
        ui->lineEdit->clear();
    }
    else
    {
        QMessageBox::about(this, "You guessed Incorrectly!", "");
        ui->lineEdit->clear();
    }
}
