#include "removecomp.h"
#include "ui_removecomp.h"
/**
 * @brief removecomp::removecomp, constructer that runs the displayComputers function
 * @param parent
 */
removecomp::removecomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
    displayComputers();
}

removecomp::~removecomp()
{
 /**
  * @brief removecomp::~removecomp, deconstucter that deletes the ui
  */
    delete ui;
}
/**
  * @brief removecomp::setId, function that sets the _id variable equal to the id param
  * @param id
  */
void removecomp::setId(int id)
{
    _id = id;
}
/**
 * @brief removecomp::setName, function that sets the _name variable equal to the name param
 * @param name
 */
void removecomp::setName(string name)
{
    _name = name;
}
/**
 * @brief removecomp::setType, function that sets the _type variable equal to the type param
 * @param type
 */
void removecomp::setType(string type)
{
    _type = type;
}
/**
 * @brief removecomp::setWasBuilt, function that sets the _wasBuilt variable equal to the wasBuilt param
 * @param wasBuilt
 */

void removecomp::setWasBuilt(string wasBuilt)
{
    _wasBuilt = wasBuilt;
}
/**
 * @brief removecomp::setYear, function that sets the _year variable equal to the year param
 * @param year
 */
void removecomp::setYear(int year)
{
    _year = year;
}
/**
 * @brief removecomp::on_button_removeComp_clicked, function that sends the _id variable to the removeComputer function and removes the computer
 */
void removecomp::on_button_removeComp_clicked()
{
    _serviceComp.removeComputer(_id);
    close();
}
/**
 * @brief removecomp::displayComputers, this function displays the computer that the user wants to remove
 */
void removecomp::displayComputers()
{
    ui -> table_comp -> clearContents();
    ui -> table_comp -> setRowCount(1);

    QString name = QString::fromStdString(_name);
    QString type = QString::fromStdString (_type);
    QString wasBuilt = QString::fromStdString(_wasBuilt);
    QString year = QString::number(_year);

    ui -> table_comp-> setItem(0, 0, new QTableWidgetItem(name));
    ui -> table_comp -> setItem(0, 1, new QTableWidgetItem(type));
    ui -> table_comp -> setItem(0, 2, new QTableWidgetItem(wasBuilt));
    ui -> table_comp -> setItem(0, 3, new QTableWidgetItem(year));
}
/**
 * @brief removecomp::on_pushButton_clicked, this function hides the screen
 */
void removecomp::on_pushButton_clicked()
{
    close();
}
