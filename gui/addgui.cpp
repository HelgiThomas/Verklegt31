#include "addgui.h"
#include "ui_addgui.h"

addgui::addgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addgui)
{
    ui->setupUi(this);
}

addgui::~addgui()
{
    delete ui;
}
