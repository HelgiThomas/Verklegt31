#include "consolegui.h"
#include "ui_consolegui.h"

consolegui::consolegui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consolegui)
{
    ui->setupUi(this);
    _totalScore = 0;
}

consolegui::~consolegui()
{
    delete ui;
}

void consolegui::on_button_list_clicked()
{
    _list.exec();
}

void consolegui::on_button_list_5_clicked()
{
    close();
}

void consolegui::on_button_list_2_clicked()
{
    _game1.setScore(_totalScore);
    _game1.displayCitation();
    _game1.displayScore();
    _game1.exec();
    _totalScore += _game1.getScore();
}
