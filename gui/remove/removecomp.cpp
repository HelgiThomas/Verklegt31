#include "removecomp.h"
#include "ui_removecomp.h"

removecomp::removecomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
    displayComputers();
}

removecomp::~removecomp()
{
    delete ui;
}

void removecomp::on_button_removeComp_clicked()
{
    vector<Computer> computers = _serviceComp.getComputers();
    int selectedComputer = ui->table_comp->currentIndex().row();
    Computer currentlySelected = computers.at(selectedComputer);
    int id = currentlySelected.getId();
    _serviceComp.removeComputer(id);

    exit(10);
}

void removecomp::displayComputers()
{
    vector<Computer> computers = _serviceComp.getComputers();
    ui -> table_comp -> clearContents();
    ui -> table_comp -> setRowCount(computers.size());

    for (unsigned int row = 0 ; row < computers.size() ; row++)
    {
        Computer currentComputer = computers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number (currentComputer.getBuildYear());
        QString type = QString::fromStdString(currentComputer.getCompType());

        ui -> table_comp -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_comp -> setItem(row, 1, new QTableWidgetItem(year));
        ui -> table_comp -> setItem(row, 2, new QTableWidgetItem(type));
    }
}



void removecomp::on_table_comp_clicked(const QModelIndex &index)
{
    ui->button_removeComp->setEnabled(true);
}
