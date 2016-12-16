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

/**
 * @brief addrel::displayScientistandComputers, displays the names of the scientists and computers in a table.
 */
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

/**
 * @brief addrel::on_button_confirmSel_clicked, adds the selected scientist or computer to their designated vector
 * when the confirm button is clicked.
 */
void addrel::on_button_confirmSel_clicked()
{
    vector <Scientist> scientists = _serviceSci.getScientists();
    vector <Computer> computers = _serviceComp.getComputers();
    unsigned int row = ui->table_sciAndComp->currentIndex().row();
    unsigned int col = ui->table_sciAndComp->currentIndex().column();
    int sciId, compId;

    //cout << row << " " << col << " " << endl;
    if(col == 0)
    {
        if(row > (scientists.size() - 1))
        {
            QMessageBox::about(this, "Error!", "This scientist item is empty, please choose a valid item!" );
        }
        else
        {
        sciId = scientists.at(row).getId();
        _sciID.push_back(sciId);
        }

    }
    else if(col == 1)
    {
        if(row > (computers.size() - 1))
        {
            QMessageBox::about(this, "Error!", "This computer item is empty, please choose a valid item!");
        }
        else
        {
        compId = computers.at(row).getId();
        _compID.push_back(compId);
        }

    }

}
/**
 * @brief addrel::on_button_addRel_clicked, adds the confirmed scientists and computers to the relation database.
 */

void addrel::on_button_addRel_clicked()
{
    int compSize = _compID.size();
    int sciSize = _sciID.size();

    for (int i = 0 ; i < sciSize; i++)
    {
        int scientistID = _sciID.at(i);
        for (int k = 0; k < compSize; k++)
        {

            int computerID = _compID.at(k);
            _serviceGen.link(scientistID, computerID);
        }
    }
    close();

}
