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


void addrel::on_button_confirmSel_clicked()
{
    vector <Scientist> scientists = _serviceSci.getScientists();
    vector <Computer> computers = _serviceComp.getComputers();
    int row = ui->table_sciAndComp->currentIndex().row();
    int col = ui->table_sciAndComp->currentIndex().column();
    int sciId, compId;

    //cout << row << " " << col << " " << endl;
    if(col == 0)
    {
        sciId = scientists.at(row).getId();
        _sciID.push_back(sciId);

    }
    else if(col == 1)
    {
        compId = computers.at(row).getId();
        _compID.push_back(compId);

    }

}

void addrel::on_button_addRel_clicked()
{
    int compSize = _compID.size();
    int sciSize = _sciID.size();
    cout << "Sci size " << _sciID.size() << endl;
    cout << "Comp size " << _compID.size() << endl;
   /* for (unsigned int i = 0 ; i < _sciID.size();i++)
    {
        cout << i << endl;
        cout << _sciID[i] << endl;
    }
    cout << "hello" << endl;

    for (int i = 0 ; i < compSize;i++)
    {
        cout << _compID[i] << "  " << endl << endl;
    }
    cout << "goodbye" << endl; */

    for (int i = 0 ; i < sciSize; i++)
    {
        int scientistID = _sciID.at(i);
        for (int k = 0; k < compSize; k++)
        {

            int computerID = _compID.at(k);
            cout << "These are the ID's going into the function - SciID: " << scientistID << " CompID: " << computerID << endl;
            //_serviceGen.link(scientistID, computerID);
        }
    }

}
