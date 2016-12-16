#include "infocomp.h"
#include "ui_infocomp.h"
#include "service/computerservice.h"

infocomp::infocomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infocomp)
{
    ui->setupUi(this);
    displayComputers();
    displayDescription();
}

infocomp::~infocomp()
{
    delete ui;
}

void infocomp::setId(int id)
{
    _id = id;
}

void infocomp::setName(string name)
{
    _name = name;
}

void infocomp::setType(string type)
{
    _type = type;
}

void infocomp::setWasBuilt(string wasBuilt)
{
    _wasBuilt = wasBuilt;
}

void infocomp::setYear(int year)
{
    _year = year;
}

void infocomp::setDescription(string description)
{
    _description = description;
}

void infocomp::displayComputers()
{
    ui -> tableWidget -> clearContents();
    ui -> tableWidget -> setRowCount(1);

    QString name = QString::fromStdString(_name);
    QString type = QString::fromStdString (_type);
    QString wasBuilt = QString::fromStdString(_wasBuilt);
    QString year = QString::number(_year);

    ui -> tableWidget-> setItem(0, 0, new QTableWidgetItem(name));
    ui -> tableWidget -> setItem(0, 1, new QTableWidgetItem(type));
    ui -> tableWidget -> setItem(0, 2, new QTableWidgetItem(wasBuilt));
    ui -> tableWidget -> setItem(0, 3, new QTableWidgetItem(year));
}

void infocomp::displayDescription()
{
    ui -> tableWidget_2 -> clearContents();
    ui -> tableWidget_2 -> setRowCount(1);

    QString desc = QString::fromStdString(_description);

    ui -> tableWidget_2 -> setItem(0, 0, new QTableWidgetItem(desc));
}

void infocomp::on_pushButton_clicked()
{
    close();
}
