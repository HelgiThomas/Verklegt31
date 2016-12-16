#include "consolegui.h"
#include "ui_consolegui.h"

consolegui::consolegui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::consolegui)
{
    ui->setupUi(this);
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
    this->hide();
}

void consolegui::on_button_list_2_clicked()
{

}

void consolegui::on_button_list_4_clicked()
{

}

void consolegui::on_button_list_3_clicked()
{

}
