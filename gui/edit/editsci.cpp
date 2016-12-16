#include "editsci.h"
#include "ui_editsci.h"
#include "service/scientistservice.h"

editscigui::editscigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editscigui)
{
    ui->setupUi(this);

    setText();
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

void editscigui::setText()
{

    cout << "loooool" << endl;
    QString name = QString::fromStdString(_name);

    ui->eName->setText(name);

    if (_sex == "Male")
    {
        ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton_2->setChecked(true);
    }

    QString birth = QString::number(_birth);
    ui->eName_2->setText(birth);

    if (_death != 0)
    {
        QString death = QString::number(_death);
        ui->eName_3->setText(death);
    }
}


void editscigui::on_checkBox_name_clicked()
{
    if(ui->checkBox_name->isChecked())
    {
        ui->eName->setEnabled(true);
    }
    else
    {
        ui->eName->setEnabled(false);
    }

}

void editscigui::on_checkBox_sex_clicked()
{
    if(ui->checkBox_sex->isChecked())
    {
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
    }
    else
    {
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(false);
    }
}

void editscigui::on_checkBox_birth_clicked()
{
    if(ui->checkBox_birth->isChecked())
    {
        ui->eName_2->setEnabled(true);
    }
    else
    {
         ui->eName_2->setEnabled(false);
    }
}

void editscigui::on_checkBox_death_clicked()
{
    if(ui->checkBox_death->isChecked())
    {
        ui->eName_3->setEnabled(true);
    }
    else
    {
        ui->eName_3->setEnabled(false);
    }

}


string editscigui::chooseSex()
{
    string sex;
    if(ui->radioButton->isChecked())
    {
        sex = "Male";
    }
    else if(ui->radioButton_2->isChecked())
    {
        sex = "Female";
    }

    return sex;
}

void editscigui::on_pushButton_editSci_clicked()
{
    string oldName = _name;

    vector<Scientist> Scientist = _sciService.getScientists();
    if(ui->checkBox_name->isChecked())
    {
       string newName = ui->eName->text().toStdString();
       _sciService.editScientistString(oldName, "name", newName);
    }

    if(ui->checkBox_sex->isChecked())
    {
       string newSex = chooseSex();
        _sciService.editScientistString(oldName, "sex", newSex);
    }

    if(ui->checkBox_birth->isChecked())
    {
       int newBirth = ui->eName_2->text().toInt();
        _sciService.editScientistInt(oldName, "birth", newBirth);
    }

    if(ui->checkBox_death->isChecked())
    {
       int newDeath = ui->eName_3->text().toInt();
        _sciService.editScientistInt(oldName,"death",newDeath);

    }







    this->hide();
}

void editscigui::on_pushButton_back_clicked()
{
    this->hide();
}
