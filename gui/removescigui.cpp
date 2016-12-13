#include "removescigui.h"
#include "ui_removescigui.h"

removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
}

removescigui::~removescigui()
{
    delete ui;
}

void removescigui::on_button_removeSci_clicked()
{
    int sciNum;
    string number = ui->line_numOfSci->text().toStdString();
    sciNum = atoi(number.c_str());
    _serviceSci.removeScientist(sciNum);

    exit(10);
}
