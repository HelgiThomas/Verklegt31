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

void consolegui::on_button_add_clicked()
{
    _add.show();
}
