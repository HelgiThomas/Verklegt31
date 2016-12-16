#include "removerelation.h"
#include "ui_removerelation.h"

removeRelation::removeRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeRelation)
{
    ui->setupUi(this);
    displayRelation();
}

removeRelation::~removeRelation()
{
    delete ui;
}

void removeRelation::setIdSci(int id)
{
    _idSci = id;
}

void removeRelation::setIdComp(int id)
{
    _idComp = id;
}

void removeRelation::setNameSci(string name)
{
    _nameSci = name;
}

void removeRelation::setNameComp(string name)
{
    _nameComp = name;
}

void removeRelation::displayRelation()
{
    ui->table_comp->clearContents();
    ui->table_comp->setRowCount(1);

    QString Scientistname = QString::fromStdString(_nameSci);
    QString Computername = QString::fromStdString(_nameComp);

    ui -> table_comp->setItem(0, 0, new QTableWidgetItem(Scientistname));
    ui -> table_comp->setItem(0, 1, new QTableWidgetItem(Computername));
}

void removeRelation::on_button_removeComp_clicked()
{
    int linkId = _serviceLink.getLinkId(_idSci, _idComp);

    _serviceLink.removeRelation(linkId);
    close();
}

void removeRelation::on_pushButton_clicked()
{
    close();
}
