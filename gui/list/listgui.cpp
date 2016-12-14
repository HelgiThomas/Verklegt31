#include "listgui.h"
#include "ui_listgui.h"

listgui::listgui(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::listgui)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
    displayRelations ();
}

listgui::~listgui()
{
    delete ui;
}
void listgui::displayAllScientists()
{
    vector<Scientist> Scientists = _serviceSci.getScientists();
    displayScientists(Scientists);
}

void listgui::displayScientists(vector <Scientist> Scientists)
{
    vector<Scientist> allScientists = Scientists;
    ui -> table_scientists -> clearContents();
    ui -> table_scientists -> setRowCount(allScientists.size());

    for (unsigned int row = 0 ; row < allScientists.size() ; row++)
    {
        Scientist currentScientist = allScientists[row];

        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::fromStdString (currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString yearDeath = QString::number(currentScientist.getDeath());

        ui -> table_scientists -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_scientists -> setItem(row, 1, new QTableWidgetItem(sex));
        ui -> table_scientists -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> table_scientists -> setItem(row, 3, new QTableWidgetItem(yearDeath));
    }
}

void listgui::on_input_filter_scientists_textChanged(const QString &arg1)
{
    string userInput = ui ->input_filter_scientists->text().toStdString();

    vector <Scientist> allScientists =_serviceSci.searchName(userInput);

    displayScientists(allScientists);

}

void listgui::displayAllComputers()
{
    vector<Computer> Computers = _serviceComp.getComputers();
    displayComputers(Computers);
}

void listgui::displayComputers(vector <Computer> Computers)
{
    vector<Computer> allComputers = Computers;
    ui -> table_computers -> clearContents();
    ui -> table_computers-> setRowCount(allComputers.size());

    for (unsigned int row = 0 ; row < allComputers.size() ; row++)
    {
        Computer currentComputer = allComputers[row];

        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number (currentComputer.getBuildYear());
        QString type = QString::fromStdString(currentComputer.getCompType());
        QString wasBuilt= QString::fromStdString(currentComputer.getWasBuilt());

        ui -> table_computers-> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_computers -> setItem(row, 1, new QTableWidgetItem(year));
        ui -> table_computers -> setItem(row, 2, new QTableWidgetItem(type));
        ui -> table_computers-> setItem(row, 3, new QTableWidgetItem(wasBuilt));
    }
}

void listgui::on_input_filter_computers_textChanged(const QString &arg1)
{
    string userInput = ui ->input_filter_computers->text().toStdString();

    vector <Computer> allComputers =_serviceComp.searchName(userInput);

    displayComputers(allComputers);
}

void listgui::displayRelations()
{
    vector<int>ScientistID = _serviceSci.allScientistID();
    vector<int>ComputerID = _serviceComp.allComputerID();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector<Scientist> lengthScientist;
    vector<Scientist> tempSci;

    for (unsigned int i = 0 ; i < ComputerID.size(); i++)
    {
        for (unsigned int k = 0; k < Computers.size(); k++)
        {
            if(ComputerID[i] == Computers[k].getId())
            {
                lengthComputer.push_back(Computers[k]);
                break;
            }
        }
    }
    for (unsigned int i = 0 ; i < ScientistID.size(); i++)
    {
        for (unsigned int k = 0; k < Scientists.size();k++)
        {
            if(ScientistID[i] == Scientists[k].getId())
            {
                lengthScientist.push_back(Scientists[k]);
            }
        }
    }
    ui -> table_relations ->clearContents();
    ui ->table_relations -> setRowCount( lengthScientist.size());

    for (unsigned int row = 0 ; row < lengthScientist.size(); row++)
    {
       Scientist currentScientist = lengthScientist[row];
       Computer currentComputer = lengthComputer[row];
       QString Scientistname = QString::fromStdString(currentScientist.getName());
       QString Computername = QString::fromStdString(currentComputer.getName());

       ui -> table_relations-> setItem(row, 0, new QTableWidgetItem(Scientistname));
       ui -> table_relations -> setItem(row, 1, new QTableWidgetItem(Computername));

    }
}
