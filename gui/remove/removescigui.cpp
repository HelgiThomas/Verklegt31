#include "removescigui.h"
#include "ui_removescigui.h"
/**
 * @brief removescigui::removescigui, constructer that runs the displayScientists function
 * @param parent
 */
removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    displayScientists();
}
/**
 * @brief removescigui::~removescigui, deconstructer that deletes the ui
 */
removescigui::~removescigui()
{
    delete this;
}
/**
 * @brief removescigui::setId, , function that sets the _id variable equal to the id param
 * @param id
 */
void removescigui::setId(int id)
{
    _id = id;
}
/**
 * @brief removescigui::setName, function that sets the _name variable equal to the name param
 * @param name
 */
void removescigui::setName(string name)
{
    _name = name;
}
/**
 * @brief removescigui::setSex, function that sets the _sex variable equal to the sex param
 * @param sex
 */
void removescigui::setSex(string sex)
{
    _sex = sex;
}
/**
 * @brief removescigui::setBirth, function that sets the _birth variable equal to the birth param
 * @param birth
 */
void removescigui::setBirth(int birth)
{
    _birth = birth;
}
/**
 * @brief removescigui::setDeath, function that sets the _death variable equal to the death param
 * @param death
 */
void removescigui::setDeath(int death)
{
    _death = death;
}
/**
 * @brief removescigui::displayScientists, function that displays the scientist which the user watns to remove
 */
void removescigui::displayScientists()
{
    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(1);

    QString name = QString::fromStdString(_name);
    QString sex = QString::fromStdString (_sex);
    QString yearBorn = QString::number(_birth);
    QString yearDeath = QString::number(_death);

    ui -> table_all-> setItem(0, 0, new QTableWidgetItem(name));
    ui -> table_all -> setItem(0, 1, new QTableWidgetItem(sex));
    ui -> table_all -> setItem(0, 2, new QTableWidgetItem(yearBorn));
    ui -> table_all -> setItem(0, 3, new QTableWidgetItem(yearDeath));
}
/**
 * @brief removescigui::on_button_removeSci_clicked, sends the _id param to the removeScientist function and removes them
 */
void removescigui::on_button_removeSci_clicked()
{
    _serviceSci.removeScientist(_id);
    this->hide();
}
/**
 * @brief removescigui::on_button_removeSci_2_clicked, hides the window
 */
void removescigui::on_button_removeSci_2_clicked()
{
    this->hide();
}
