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
    ui -> list_all -> clear ();

    for (unsigned int i = 0 ; i < allScientists.size() ;i++)
    {
        Scientist currentScientist = allScientists[i];
        ui -> list_all -> addItem(QString::fromStdString(currentScientist.getName()));
    }
}

void listgui::displayComputers()
{
    vector<Computer> allComputers = _serviceComp.getComputers();
}

void listgui::displayRelations()
{

}
