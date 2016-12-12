#include "sortgui.h"
#include "ui_sortgui.h"

sortgui::sortgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortgui)
{
    ui->setupUi(this);
}

sortgui::~sortgui()
{
    delete ui;
}
