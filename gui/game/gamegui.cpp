#include "gamegui.h"
#include "ui_gamegui.h"

gamegui::gamegui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamegui)
{
    ui->setupUi(this);
}

gamegui::~gamegui()
{
    delete ui;
}

void gamegui::on_pushButton_clicked()
{

}

void gamegui::on_pushButton_2_clicked()
{

}
