#include "removecomp.h"
#include "ui_removecomp.h"

removecomp::removecomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
    //displayComputers();
}

removecomp::removecomp(vector<Computer> comp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
    _comp = comp;

    displayComputers();
}

removecomp::~removecomp()
{
    delete ui;
}


void removecomp::displayComputers()
{
    ui -> table_comp -> clearContents();
    ui -> table_comp -> setRowCount(_comp.size());

    for (unsigned int row = 0 ; row < _comp.size() ; row++)
    {
        Computer currentComputer = _comp[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number (currentComputer.getBuildYear());
        QString type = QString::fromStdString(currentComputer.getCompType());

        ui -> table_comp -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_comp -> setItem(row, 1, new QTableWidgetItem(year));
        ui -> table_comp -> setItem(row, 2, new QTableWidgetItem(type));
    }
}

/*
void removecomp::on_button_removeComp_clicked()
{
    vector<Computer> computers = _serviceComp.getComputers();
    int selectedComputer = ui->table_comp->currentIndex().row();
    Computer currentlySelected = computers.at(selectedComputer);
    int id = currentlySelected.getId();
    _serviceComp.removeComputer(id);
}
*/

void removecomp::on_button_removeComp_clicked()
{
    for (unsigned int i = 0 ; i < _comp.size() ; i++)
    {
        int id = _comp[i].getId();
        _serviceComp.removeComputer(id);
    }
}
