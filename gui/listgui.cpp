#include "listgui.h"
#include "ui_listgui.h"

listgui::listgui(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::listgui)
{
    ui->setupUi(this);
}

listgui::~listgui()
{
    delete ui;
}

void listgui::displayScientists()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();
    ui -> display_all -> clear();
    for (int i = 0 ; i < allScientists.size();i++)
    {
        ui -> display_all -> addItem(QString::fromStdString(allScientists[i].getName));
    }
}

void listgui::displayComputers()
{
    vector<Computer> allComputers = _serviceComp.getComputers();
}

void listgui::displayRelations()
{

}
