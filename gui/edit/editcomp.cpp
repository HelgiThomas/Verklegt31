#include "editcomp.h"
#include "ui_editcomp.h"

editcompgui::editcompgui(QWidget *parent) :
    QWidget(parent),
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
    _ID = id;
}

void editcompgui::setText()
{
    QString name = QString::fromStdString(_comp.getName());

    ui->lineEdit_2->setText(name);

    if (_comp.getCompType() == "Mechanical")
    {
        ui->radioButton->setChecked(true);
    }
    else if (_comp.getCompType() == "Transistor")
    {
        ui->radioButton_2->setChecked(true);
    }
    else if (_comp.getCompType() == "Electronic")
    {
        ui->radioButton_3->setChecked(true);
    }
    else
    {
        ui->radioButton_4->setChecked(true);
    }

    if (_comp.getWasBuilt() == "Yes")
    {
        ui->radioButton_5->setChecked(true);
    }
    else
    {
        ui->radioButton_6->setChecked(true);
    }

    if (_comp.getWasBuilt() != "No")
    {
        QString year = QString::number(_comp.getBuildYear());
        ui->comboBox_2->activated(year);
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
    ui->comboBox_2->setEnabled(true);
}

void editcompgui::on_radioButton_4_clicked()
{
    ui->lineEdit_3->setEnabled(true);
}

void editcompgui::on_pushButton_editComp_clicked()
{
    this->hide();
}

void editcompgui::on_pushButton_back_clicked()
{
    this->hide();
}
