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

void removecomp::setId(int id)
{
    _ID = id;
}

void removecomp::on_button_removeComp_clicked()
{
    this->hide();
}

void removecomp::displayComputers()
{
    vector<Computer> allComputer = _serviceComp.getComputers();

    ui -> table_comp -> clearContents();
    ui -> table_comp -> setRowCount(1);

    for (unsigned int row = 0 ; row < 1; row++)
    {
        QString name = QString::fromStdString(allComputer[_ID].getName());
        QString sex = QString::fromStdString (allComputer[_ID].getCompType());
        QString yearBorn = QString::fromStdString(allComputer[_ID].getWasBuilt());
        QString yearDeath = QString::number(allComputer[_ID].getBuildYear());

        ui -> table_comp-> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_comp -> setItem(row, 1, new QTableWidgetItem(sex));
        ui -> table_comp -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> table_comp -> setItem(row, 3, new QTableWidgetItem(yearDeath));
    }
}
