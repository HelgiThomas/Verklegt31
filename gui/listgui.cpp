#include "listgui.h"
#include "ui_listgui.h"

listgui::listgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::listgui)
{
    ui->setupUi(this);
}

listgui::~listgui()
{
    delete ui;
}
