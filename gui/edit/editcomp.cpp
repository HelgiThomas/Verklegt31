#include "editcomp.h"
#include "ui_editcomp.h"

editcompgui::editcompgui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editcompgui)
{
    ui->setupUi(this);
}

editcompgui::~editcompgui()
{
    delete ui;
}
