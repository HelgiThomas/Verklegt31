#include "addrel.h"
#include "ui_addrel.h"

addrel::addrel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrel)
{
    ui->setupUi(this);
    _list.displayAllScientists();
}

addrel::~addrel()
{
    delete ui;
}

void addrel::on_button_addSciRel_clicked()
{
    vector<Scientist> scientists = _serviceSci.getScientists();
    int selectedScientist = ui->table_scientists->currentIndex().row();
    Scientist currentlySelected = scientists.at(selectedScientist);
    int id = currentlySelected.getId();
    _sciID.push_back(id);

}

void addrel::on_button_addCompRel_clicked()
{
    vector<Computer> computers = _serviceComp.getComputers();
    int selectedComputer = ui->table_comp->currentIndex().row();
    Computer currentlySelected = computers.at(selectedComputer);
    int id = currentlySelected.getId();
    _compID.push_back(id);
}

/*void addrel::displayRelations(vector <Scientist> scientists, vector <Computer> computers)
{
    vector<Scientist> sci = scientists;
    vector<Computer> comp = computers;

    //ui -> table_rel -> clearContents();
    int size;
    if(sci.size() > comp.size())
    {
        ui -> table_rel -> setRowCount(sci.size());
        size = sci.size();
    }
    else
    {
        ui -> table_rel -> setRowCount(comp.size());
        size = comp.size();
    }

    for (unsigned int row = 0; row < size; row++)
    {
        if()
       // Scientist currentScientist.getName() = sci[row];
       // Computer currentComputer.getName() = comp[row];

        QString sciName = QString::fromStdString(currentScientist.getName());
        QString compName = QString::fromStdString (currentComputer.getName());



        ui -> table_rel -> setItem(row, 0, new QTableWidgetItem(sciName));
        ui -> table_rel -> setItem(row, 1, new QTableWidgetItem(compName));


    }
} */


void addrel::displaySciRel()
{
    _list.displayAllScientists();
}
