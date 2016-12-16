#include "infosci.h"
#include "ui_infosci.h"
#include "service/scientistservice.h"

infosci::infosci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infosci)
{
    ui->setupUi(this);
    displayScientists();
    displayCitation();
}

infosci::~infosci()
{
    delete ui;
}

void infosci::setId(int id)
{
    _id = id;
}

void infosci::setName(string name)
{
    _name = name;
}

void infosci::setSex(string sex)
{
    _sex = sex;
}

void infosci::setBirth(int birth)
{
    _birth = birth;
}

void infosci::setDeath(int death)
{
    _death = death;
}

void infosci::setCitation(string citation)
{
    _citation = citation;
}

void infosci::displayScientists()
{
    ui -> tableWidget -> clearContents();
    ui -> tableWidget -> setRowCount(1);

    QString name = QString::fromStdString(_name);
    QString sex = QString::fromStdString (_sex);
    QString yearBorn = QString::number(_birth);
    QString yearDeath = QString::number(_death);

    ui -> tableWidget -> setItem(0, 0, new QTableWidgetItem(name));
    ui -> tableWidget -> setItem(0, 1, new QTableWidgetItem(sex));
    ui -> tableWidget -> setItem(0, 2, new QTableWidgetItem(yearBorn));
    ui -> tableWidget -> setItem(0, 3, new QTableWidgetItem(yearDeath));
}

void infosci::displayCitation()
{
    ui -> tableWidget_2 -> clearContents();
    ui -> tableWidget_2 -> setRowCount(1);

    QString citation = QString::fromStdString(_citation);

    ui -> tableWidget_2-> setItem(0, 0, new QTableWidgetItem(citation));
}

void infosci::on_pushButton_clicked()
{
    close();
}
