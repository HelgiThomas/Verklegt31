#include "editsci.h"
#include "ui_editsci.h"

editscigui::editscigui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editscigui)
{
    ui->setupUi(this);
}

editscigui::~editscigui()
{
    delete ui;
}
