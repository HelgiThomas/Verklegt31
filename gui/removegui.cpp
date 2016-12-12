#include "removegui.h"
#include "ui_removegui.h"

removegui::removegui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removegui)
{
    ui->setupUi(this);
}

removegui::~removegui()
{
    delete ui;
}
