#include "removecomp.h"
#include "ui_removecomp.h"

removecomp::removecomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
    displayComputers();
}

removecomp::~removecomp()
{
    delete ui;
}

void removecomp::setId(int id)
{
    _id = id;
}

void removecomp::setName(string name)
{
    _name = name;
}

void removecomp::setType(string type)
{
    _type = type;
}

void removecomp::setWasBuilt(string wasBuilt)
{
    _wasBuilt = wasBuilt;
}

void removecomp::setYear(int year)
{
    _year = year;
}

void removecomp::on_button_removeComp_clicked()
{
    _serviceComp.removeComputer(_id);
    this->hide();
}

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

void removecomp::on_pushButton_clicked()
{
    this->hide();
}
