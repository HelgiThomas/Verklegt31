#include "editsci.h"
#include "ui_editsci.h"
#include "service/scientistservice.h"

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


/*void editscigui::on_pushButton_editSci_clicked()
{
    if(ui->radioButton_name->isChecked())
    {
        vector<Scientist> scientist = _serviceSci.getScientists();
        int selectedScientist = ui->table_comp->currentIndex().row();
        Scientist currentlySelected = scientist.at(selectedComputer);
        int id = currentlySelected.getId();
        int newElement =
        _serviceSci.editScientistString(scientist.getName(),"name", newElement);
    }


}*/
