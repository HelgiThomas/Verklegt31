#include "editrelation.h"
#include "ui_editrelation.h"

editrelationgui::editrelationgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editrelationgui)
{
    ui->setupUi(this);
}

editrelationgui::~editrelationgui()
{
    delete ui;
}
