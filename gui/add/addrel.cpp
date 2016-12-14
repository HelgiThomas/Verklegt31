#include "addrel.h"
#include "ui_addrel.h"

addrel::addrel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrel)
{
    ui->setupUi(this);
    displayScientistandComputers();
}

addrel::~addrel()
{
    delete ui;
}


void addrel::displayScientistandComputers()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();
    vector<Computer> allComputers = _serviceComp.getComputers();
    ui -> table_sciAndComp -> clearContents();

    if (allScientists.size() > allComputers.size())
    {
       ui -> table_sciAndComp -> setRowCount(allScientists.size());

       for (unsigned int row = 0 ; row < allScientists.size(); row++)
       {
           Scientist currentScientist = allScientists[row];

           QString scientistName = QString::fromStdString(currentScientist.getName());

           QString emptyString = QString::fromStdString("");

           ui -> table_sciAndComp -> setItem(row, 0, new QTableWidgetItem(scientistName));

           if(row < allComputers.size() )
           {
               Computer currentComputer = allComputers[row];
               QString computerName = QString::fromStdString (currentComputer.getName());

               ui -> table_sciAndComp -> setItem(row, 1, new QTableWidgetItem(computerName));
           }
           else if  (row >= allComputers.size() )
           {
               ui -> table_sciAndComp -> setItem(row, 1, new QTableWidgetItem(emptyString));
           }
       }
    }
    else if (allComputers.size() > allScientists.size())
    {
        ui -> table_sciAndComp -> setRowCount(allComputers.size());

        for (unsigned int row = 0 ; row < allComputers.size(); row++)
        {

            Computer currentComputer = allComputers[row];

            QString computerName = QString::fromStdString (currentComputer.getName());
            QString emptyString = QString::fromStdString("");

            if(row < allScientists.size() )
            {
                Scientist currentScientist = allScientists[row];
                QString scientistName = QString::fromStdString(currentScientist.getName());

                ui -> table_sciAndComp -> setItem(row, 0, new QTableWidgetItem(scientistName));
            }
            else if  (row >= allScientists.size() )
            {
                ui -> table_sciAndComp -> setItem(row, 0, new QTableWidgetItem(emptyString));
            }

             ui -> table_sciAndComp -> setItem(row, 1, new QTableWidgetItem(computerName));

        }
    }
}

