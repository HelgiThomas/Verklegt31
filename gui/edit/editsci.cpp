#include "editsci.h"
#include "ui_editsci.h"
#include "service/scientistservice.h"

editscigui::editscigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscigui)
{   
    ui->setupUi(this);

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    displayScientists();
    displayCitation();
}

editscigui::~editscigui()
{
    delete ui;
}

void editscigui::setId(int id)
{
    _id = id;
}

void editscigui::setName(string name)
{
    _name = name;
}

void editscigui::setSex(string sex)
{
    _sex = sex;
}

void editscigui::setBirth(int birth)
{
    _birth = birth;
}

void editscigui::setDeath(int death)
{
    _death = death;
}

void editscigui::setCitation(string citation)
{
    _citation = citation;
}

void editscigui::displayScientists()
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

void editscigui::displayCitation()
{
    ui -> tableWidget_2 -> clearContents();
    ui -> tableWidget_2 -> setRowCount(1);

    QString citation = QString::fromStdString(_citation);

    ui -> tableWidget_2-> setItem(0, 0, new QTableWidgetItem(citation));
}

void editscigui::on_pushButton_editSci_clicked()
{
    string name = ui->lineEdit->text().toStdString();
    string sex = ui->lineEdit_2->text().toStdString();
    int birth = ui->lineEdit_4->text().toInt();
    int death = ui->lineEdit_3->text().toInt();
    string citation = ui->lineEdit_5->text().toStdString();


    if(birth > death && death != 0)
    {
        QMessageBox::about(this, "Error!", "A person can not die before their birth!");
        ui->lineEdit_3->clear();
        ui->lineEdit_4->clear();
    }
    else if(!_sciService.validName(name))
    {
        QMessageBox::about(this, "Error!", "The name is invalid!");
        ui->lineEdit->clear();
    }
    else if(!isMaleOrFemale())
    {
        QMessageBox::about(this, "Error!", "Please choose sex!");
        ui->lineEdit_2->clear();
    }
    else
    {
        _sciService.editScientistString(_id, "name", name);
        _sciService.editScientistString(_id, "sex", sex);
        _sciService.editScientistInt(_id, "birth", birth);
        _sciService.editScientistInt(_id, "death", death);
        _sciService.editScientistString(_id, "citation", citation);
        accept();
    }
}

bool editscigui::isMaleOrFemale()
{
    string sex = ui->lineEdit_2->text().toStdString();

    if(sex == "Male" || sex == "male" || sex == "Female" || sex == "female")
    {
        return true;
    }
    else
    {
        return false;
    }
}

void editscigui::on_pushButton_back_clicked()
{
    close();
}
