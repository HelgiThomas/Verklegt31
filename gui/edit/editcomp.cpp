#include "editcomp.h"
#include "ui_editcomp.h"

editcompgui::editcompgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcompgui)
{
    ui->setupUi(this);

    setText();
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

void editcompgui::setText()
{
    QString name = QString::fromStdString(_name);

    ui->lineEdit_2->setText(name);

    if (_type == "Mechanical")
    {
        ui->radioButton->setChecked(true);
    }
    else if (_type == "Transistor")
    {
        ui->radioButton_2->setChecked(true);
    }
    else if (_type == "Electronic")
    {
        ui->radioButton_3->setChecked(true);
    }
    else
    {
        ui->radioButton_4->setChecked(true);
    }

    if (_wasBuilt == "Yes")
    {
        ui->radioButton_5->setChecked(true);
    }
    else
    {
        ui->radioButton_6->setChecked(true);
    }

    if (_wasBuilt != "No")
    {
        QString year = QString::number(_year);
        ui->lineEdit_4->setText(year);
    }
}


void editcompgui::on_radioButton_name_clicked()
{
    ui->lineEdit_2->setEnabled(true);
}

void editcompgui::on_radioButton_type_clicked()
{
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton_3->setEnabled(true);
    ui->radioButton_4->setEnabled(true);
}

void editcompgui::on_radioButton_wasBuilt_clicked()
{
    ui->radioButton_5->setEnabled(true);
    ui->radioButton_6->setEnabled(true);
}

void editcompgui::on_radioButton_year_clicked()
{
    ui->lineEdit_4->setEnabled(true);
}

void editcompgui::on_radioButton_4_clicked()
{
    ui->lineEdit_3->setEnabled(true);
}

void editcompgui::on_pushButton_editComp_clicked()
{
    string oldName = "";

    this->hide();
}

void editcompgui::on_pushButton_back_clicked()
{
    this->hide();
}
