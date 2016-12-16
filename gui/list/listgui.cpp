#include "listgui.h"
#include "ui_listgui.h"
#include "infosci.h"
#include "infocomp.h"
/**
 * @brief listgui::listgui, constructer that runs the displayAllScientists, displayAllComputers and siplayRelations functions
 * @param parent
 */
listgui::listgui(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::listgui)
{
    ui->setupUi(this);
    displayAllScientists();
    displayAllComputers();
    displayRelations ();
}
/**
 * @brief listgui::~listgui, deconstructer that deletes the ui
 */
listgui::~listgui()
{
    delete ui;
}
/**
 * @brief listgui:: displayAllScientists, gets all scientists and sends them to the displayScientists function
 */
void listgui::displayAllScientists()
{
    vector<Scientist> Scientists = _serviceSci.getScientists();
    displayScientists(Scientists);
}
/**
 * @brief listgui::displayScientists, displays all scientsits with status = 1
 */
void listgui::displayScientists(vector <Scientist> Scientists)
{
    vector<Scientist> allScientists = Scientists;
    ui -> table_scientists -> clearContents();
    ui -> table_scientists -> setRowCount(allScientists.size());

    for (unsigned int row = 0 ; row < allScientists.size() ; row++)
    {
        Scientist currentScientist = allScientists[row];

        QString id = QString::number(currentScientist.getId());
        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::fromStdString (currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString yearDeath = QString::number(currentScientist.getDeath());

        ui -> table_scientists -> setItem(row, 0, new QTableWidgetItem(id));
        ui -> table_scientists -> setItem(row, 1, new QTableWidgetItem(name));
        ui -> table_scientists -> setItem(row, 2, new QTableWidgetItem(sex));
        ui -> table_scientists -> setItem(row, 3, new QTableWidgetItem(yearBorn));
        ui -> table_scientists -> setItem(row, 4, new QTableWidgetItem(yearDeath));
    }
}
/**
 * @brief listgui::displayAllComputers,  gets all computers and sends them to the displayComputers function
 */
void listgui::displayAllComputers()
{
    vector<Computer> Computers = _serviceComp.getComputers();
    displayComputers(Computers);
}
/**
 * @brief listgui::displayComputers, displays all computers with status = 1
 */
void listgui::displayComputers(vector <Computer> Computers)
{
    vector<Computer> allComputers = Computers;
    ui -> table_computers -> clearContents();
    ui -> table_computers-> setRowCount(allComputers.size());

    for (unsigned int row = 0 ; row < allComputers.size() ; row++)
    {
        Computer currentComputer = allComputers[row];

        QString id = QString::number(currentComputer.getId());
        QString name = QString::fromStdString(currentComputer.getName());
        QString year = QString::number (currentComputer.getBuildYear());
        QString type = QString::fromStdString(currentComputer.getCompType());
        QString wasBuilt= QString::fromStdString(currentComputer.getWasBuilt());

        ui -> table_computers -> setItem(row, 0, new QTableWidgetItem(id));
        ui -> table_computers-> setItem(row, 1, new QTableWidgetItem(name));
        ui -> table_computers -> setItem(row, 2, new QTableWidgetItem(year));
        ui -> table_computers -> setItem(row, 3, new QTableWidgetItem(type));
        ui -> table_computers-> setItem(row, 4, new QTableWidgetItem(wasBuilt));
    }
}
/**
 * @brief listgui::displayRelations, displays all relations between computers and scientists were status = 1
 */
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
        cout << endl;
    }
    ui -> table_relations ->clearContents();
    ui ->table_relations -> setRowCount(lengthScientist.size());


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
/**
 * @brief listgui::on_input_filter_scientists_textChanged, this is the search function, which returns a vector of all scientists were the string/number come in
 * @param arg1
 */
void listgui::on_input_filter_scientists_textChanged(const QString &arg1)
{
    string userInput = ui ->input_filter_scientists->text().toStdString();

    vector <Scientist> allScientists =_serviceSci.searchName(userInput);

    displayScientists(allScientists);

}
/**
 * @brief listgui::on_input_filter_computers_textChanged, this is the search function, which returns a vector of all computers were the string/number come in
 * @param arg1
 */
void listgui::on_input_filter_computers_textChanged(const QString &arg1)
{
    string userInput = ui ->input_filter_computers->text().toStdString();

    vector <Computer> allComputers =_serviceComp.searchName(userInput);

    displayComputers(allComputers);
}
/**
 * @brief listgui::on_table_computers_clicked, this function sets the variables in _removecomp and _editcomp classes when the user clicks on the index
 * @param index
 */
void listgui::on_table_computers_clicked(const QModelIndex &index)
{
    vector<Computer> computer = _serviceComp.getComputers();

    int row = ui->table_computers->currentRow();
    int compId = ui->table_computers->item(row,0)->text().toInt();

    int id;
    string name;
    string type;
    string built;
    int year;

    for (unsigned int i = 0; i < computer.size(); i++)
    {
        if (computer[i].getId() == compId)
        {
            id = computer[i].getId();
            name = computer[i].getName();
            type = computer[i].getCompType();
            built = computer[i].getWasBuilt();
            year = computer[i].getBuildYear();
        }
    }

    _removeComp.setId(id);
    _removeComp.setName(name);
    _removeComp.setType(type);
    _removeComp.setWasBuilt(built);
    _removeComp.setYear(year);

    _editComp.setId(id);
    _editComp.setName(name);
    _editComp.setType(type);
    _editComp.setWasBuilt(built);
    _editComp.setYear(year);

    ui->button_remove_computer->setEnabled(true);
    ui->button_edit_computer->setEnabled(true);
}
/**
 * @brief listgui::this function sets the variables in _removeSci and _editSci classes when the user clicks on the index
 * @param index
 */
void listgui::on_table_scientists_clicked(const QModelIndex &index)
{
    vector<Scientist> scientist = _serviceSci.getScientists();

    int row = ui->table_scientists->currentRow();
    int sciId = ui->table_scientists->item(row,0)->text().toInt();

    int id;
    string name;
    string sex;
    int birth;
    int death;

    for (unsigned int i = 0; i < scientist.size(); i++)
    {
        if (scientist[i].getId() == sciId)
        {
            id = scientist[i].getId();
            name = scientist[i].getName();
            sex = scientist[i].getSex();
            birth = scientist[i].getBirth();
            death = scientist[i].getDeath();
        }
    }

    _removeSci.setId(id);
    _removeSci.setName(name);
    _removeSci.setSex(sex);
    _removeSci.setBirth(birth);
    _removeSci.setDeath(death);

    _editSci.setId(id);
    _editSci.setName(name);
    _editSci.setSex(sex);
    _editSci.setBirth(birth);
    _editSci.setDeath(death);

    ui->button_remove_scientist->setEnabled(true);
    ui->button_edit_scientist->setEnabled(true);
}
/**
 * @brief listgui::on_button_add_scientist_clicked, this function executes the _addsci class
 */
void listgui::on_button_add_scientist_clicked()
{
    _addsci.exec();
}
/**
 * @brief listgui::on_button_add_computer_clicked, this function executes the _addcomp class
 */
void listgui::on_button_add_computer_clicked()
{
    _addcomp.exec();
}
/**
 * @brief listgui::on_button_edit_scientist_clicked, this function executes the _editSci class
 */
void listgui::on_button_edit_scientist_clicked()
{
    _editSci.exec();
    //_editSci.setText();
}
/**
 * @brief listgui::on_button_edit_computer_clicked, this function executes the _editComp class
 */
void listgui::on_button_edit_computer_clicked()
{
    _editComp.exec();
    //_editSci.setText();
}
/**
 * @brief listgui::on_button_remove_scientist_clicked, this function executes the displayScientists function and the _removeSci class
 */
void listgui::on_button_remove_scientist_clicked()
{
    _removeSci.displayScientists();
    _removeSci.exec();
}
/**
 * @brief listgui::on_button_remove_computer_clicked, this function executes the displayComputers function and the _removeComputer class
 */
void listgui::on_button_remove_computer_clicked()
{
    _removeComp.displayComputers();
    _removeComp.exec();
}
/**
 * @brief listgui::on_button_info_scientist_clicked, this function exexutes the _infoSci class
 */
void listgui::on_button_info_scientist_clicked()
{
    _infoSci.exec();
}
/**
 * @brief listgui::on_button_info_comp_clicked, this function exexutes the _infoComp class
 */
void listgui::on_button_info_comp_clicked()
{
    _infoComp.exec();
}
/**
 * @brief listgui::on_button_add_relation_clicked, this function executes the _addrel class
 */
void listgui::on_button_add_relation_clicked()
{
    _addrel.exec();
}
