#include "editcomp.h"
#include "ui_editcomp.h"

editcompgui::editcompgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcompgui)
{
    ui->setupUi(this);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    displayComputers();
    displayDescription();
}

editcompgui::~editcompgui()
{
    delete ui;
}

void editcompgui::setId(int id)
{
    _id = id;
}

void editcompgui::setName(string name)
{
    _name = name;
}

void editcompgui::setType(string type)
{
    _type = type;
}

void editcompgui::setWasBuilt(string wasBuilt)
{
    _wasBuilt = wasBuilt;
}

void editcompgui::setYear(int year)
{
    _year = year;
}

void editcompgui::setDescription(string description)
{
    _description = description;
}

void editcompgui::displayComputers()
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

void editcompgui::displayDescription()
{
    ui -> tableWidget_2 -> clearContents();
    ui -> tableWidget_2 -> setRowCount(1);

    QString desc = QString::fromStdString(_description);

    ui -> tableWidget_2 -> setItem(0, 0, new QTableWidgetItem(desc));
}

void editcompgui::on_pushButton_editComp_clicked()
{
    string name = ui->lineEdit->text().toStdString();
    string type = ui->lineEdit_2->text().toStdString();
    string wasBuilt = ui->lineEdit_3->text().toStdString();
    int year = ui->lineEdit_4->text().toInt();
    string desc = ui->lineEdit_5->text().toStdString();

    if(!isValidWasBuilt())
    {
        QMessageBox::about(this, "Error!", "Please say whether the computer was built or not! (Either yes or no)");
        ui->lineEdit_3->clear();
    }
    else if(!_serviceComp.validName(type))
    {
        QMessageBox::about(this, "Error!", "Please enter a valid other computer type!");
        ui->lineEdit->clear();
    }
    else
    {
        _serviceComp.editComputerString(_id, "name", name);
        _serviceComp.editComputerString(_id, "type", type);
        _serviceComp.editComputerString(_id, "wasBuilt", wasBuilt);
        _serviceComp.editComputerInt(_id, "year", year);
        _serviceComp.editComputerString(_id, "description", desc);
        accept();
    }
}

bool editcompgui::isValidWasBuilt()
{
    string wasBuilt = ui->lineEdit_3->text().toStdString();

    if(wasBuilt == "yes" || wasBuilt == "yes" || wasBuilt == "No" || wasBuilt == "no")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void editcompgui::on_pushButton_back_clicked()
{
    close();
}


