#include "searchgui.h"
#include "ui_searchgui.h"

searchgui::searchgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchgui)
{
    ui->setupUi(this);
}

searchgui::~searchgui()
{
    delete ui;
}
