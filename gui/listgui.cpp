#include "listgui.h"
#include "ui_listgui.h"

listgui::listgui(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::listgui)
{
    ui->setupUi(this);
    displayScientists();
}

listgui::~listgui()
{
    delete ui;
}

void listgui::displayScientists()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();
    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(allScientists.size());

    for (unsigned int row = 0 ; row < allScientists.size() ; row++)
    {
        Scientist currentScientist = allScientists[row];

        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::fromStdString (currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString yearDeath = QString::number(currentScientist.getDeath());


        ui -> table_all -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_all -> setItem(row, 1, new QTableWidgetItem(sex));
        ui -> table_all -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> table_all -> setItem(row, 3, new QTableWidgetItem(yearDeath));

    }
}

void listgui::displayComputers()
{
    vector<Computer> allComputers = _serviceComp.getComputers();
}

void listgui::displayRelations()
{

}
