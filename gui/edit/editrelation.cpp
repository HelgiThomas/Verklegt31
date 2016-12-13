#include "editrelation.h"
#include "ui_editrelation.h"

editrelationgui::editrelationgui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editrelationgui)
{
    ui->setupUi(this);
}

editrelationgui::~editrelationgui()
{
    delete ui;
}
