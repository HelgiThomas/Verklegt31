#include "editcomp.h"
#include "ui_editcomp.h"

editcompgui::editcompgui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcompgui)
{
    ui->setupUi(this);
    for(int i = 2016; i > 0; i--)
    {
        ui->lineEdit_4->addItem(QString::number(i));
    }

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
        ui->lineEdit_4->setCurrentText(year);
    }
}


void editcompgui::on_radioButton_name_clicked()
{
    if(ui->radioButton_name->isChecked())
    {
        ui->lineEdit_2->setEnabled(true);
    }
    else
    {
        ui->lineEdit_2->setEnabled(false);
    }

}

void editcompgui::on_radioButton_type_clicked()
{
    if(ui->radioButton_type->isChecked())
    {

        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
        ui->radioButton_3->setEnabled(true);
        ui->radioButton_4->setEnabled(true);

        if(ui->radioButton_4->isChecked())
        {
            ui->lineEdit_3->setEnabled(true);
        }
        else
        {
            ui->lineEdit_3->setEnabled(false);
        }

    }
    else
    {
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
        ui->radioButton_3->setEnabled(false);
        ui->radioButton_4->setEnabled(false);
        ui->lineEdit_3->setEnabled(false);
    }

}

void editcompgui::on_radioButton_wasBuilt_clicked()
{
    if(ui->radioButton_wasBuilt->isChecked())
    {
        ui->radioButton_5->setEnabled(true);
        ui->radioButton_6->setEnabled(true);
    }
    else
    {
        ui->radioButton_5->setEnabled(false);
        ui->radioButton_6->setEnabled(false);
    }
}

void editcompgui::on_radioButton_year_clicked()
{
    if(ui->radioButton_year->isChecked())
    {
        ui->lineEdit_4->setEnabled(true);
    }
    else
    {
        ui->lineEdit_4->setEnabled(false);
    }
}

void editcompgui::on_radioButton_4_clicked()
{
    ui->lineEdit_3->setEnabled(true);
}

void editcompgui::on_pushButton_editComp_clicked()
{
    string oldName = _name;

    vector<Computer> computers = _serviceComp.getComputers();

    string addName = ui->lineEdit_2->text().toStdString();
    string addType = _type;
    string addWasBuilt = _wasBuilt;


    int addBuildYear = _year;

    if(ui->radioButton_name->isChecked())
    {
       _serviceComp.editComputerString(oldName, "name", addName);
    }

    if(ui->radioButton_type->isChecked())
    {
        if(ui->radioButton_4->isChecked())
        {
            addType = ui->lineEdit_3->text().toStdString();
             _serviceComp.editComputerString(oldName, "type", addType);
        }
        else
        {
            _serviceComp.editComputerString(oldName, "type", addType);
        }

    }

    if(ui->radioButton_wasBuilt->isChecked())
    {
        _serviceComp.editComputerString(oldName, "built", addWasBuilt);
    }

    if(ui->radioButton_year->isChecked())
    {
        _serviceComp.editComputerInt(oldName, "year", addBuildYear);
    }

    this->hide();
}

void editcompgui::on_pushButton_back_clicked()
{
    this->hide();
}

void editcompgui::on_radioButton_clicked()
{
    ui->lineEdit_3->setEnabled(false);
    _type = "Mechanical";
}

void editcompgui::on_radioButton_2_clicked()
{
    ui->lineEdit_3->setEnabled(false);
    _type = "Transistor";
}

void editcompgui::on_radioButton_3_clicked()
{
    ui->lineEdit_3->setEnabled(false);
    _type = "Electronic";
}

void editcompgui::on_radioButton_6_clicked()
{
    _wasBuilt = "Yes";
}

void editcompgui::on_radioButton_5_clicked()
{
    _wasBuilt = "No";
    _year = 0;
}

void editcompgui::on_lineEdit_4_currentIndexChanged(int index)
{
    QString qstrBuildYear = ui->lineEdit_4->currentText();
    string strBuildYear = qstrBuildYear.toStdString();
    _year = atoi(strBuildYear.c_str());
}

