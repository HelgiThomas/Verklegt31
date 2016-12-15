#include "removescigui.h"
#include "ui_removescigui.h"

removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    displayScientists();
}

removescigui::~removescigui()
{
    delete this;
}

void removescigui::setId(int id)
{
    _id = id;
}

void removescigui::setName(string name)
{
    _name = name;
}

void removescigui::setSex(string sex)
{
    _sex = sex;
}

void removescigui::setBirth(int birth)
{
    _birth = birth;
}

void removescigui::setDeath(int death)
{
    _death = death;
}

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

void removescigui::on_button_removeSci_clicked()
{
    _serviceSci.removeScientist(_id);
    this->hide();
}

void removescigui::on_button_removeSci_2_clicked()
{
    this->hide();
}
