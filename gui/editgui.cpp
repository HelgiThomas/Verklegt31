#include "editgui.h"
#include "ui_editgui.h"

editgui::editgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editgui)
{
    ui->setupUi(this);
}

editgui::~editgui()
{
    delete ui;
}
