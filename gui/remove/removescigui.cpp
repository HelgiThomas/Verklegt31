#include "removescigui.h"
#include "ui_removescigui.h"

removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    //displayScientists();
}

removescigui::~removescigui()
{
    delete ui;
}

void removescigui::on_button_removeSci_clicked()
{

    this->destroy();
    this->hide();
}

void removescigui::setId(int id)
{
    _ID = id;
}
