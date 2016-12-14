#include "editsci.h"
#include "ui_editsci.h"
#include "service/scientistservice.h"

editscigui::editscigui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editscigui)
{
    ui->setupUi(this);
}

editscigui::editscigui(Scientist sci, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editscigui)
{
    ui->setupUi(this);
    _sci = sci;

    //setText();
}

editscigui::~editscigui()
{
    delete ui;
}

void editscigui::setText()
{
    QString name = QString::fromStdString(_sci.getName());

    ui->eName->setText(name);

    if (_sci.getSex() == "Male")
    {
        ui->radioButton->setChecked(true);
    }
    else
    {
        ui->radioButton_2->setChecked(true);
    }

    QString birth = QString::number(_sci.getBirth());
    ui->comboBox->activated(birth);

    if (_sci.getDeath() != 0)
    {
        QString death = QString::number(_sci.getDeath());
        ui->comboBox_2->activated(death);
    }
}


void editscigui::on_radioButton_name_clicked()
{
    ui->eName->setEnabled(true);
}

void editscigui::on_radioButton_sex_clicked()
{
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
}

void editscigui::on_radioButton_birth_clicked()
{
    ui->comboBox->setEnabled(true);
}

void editscigui::on_radioButton_death_clicked()
{
    ui->comboBox_2->setEnabled(true);
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
    string oldName = _sci.getName();

    vector<Scientist> Scientist = _sciService.getScientists();

    string newName = ui->eName->text().toStdString();
    string newSex = chooseSex();
    int newBirth = _sciBirth;
    int newDeath = _sciDeath;

    _sciService.editScientistString(oldName, "name", newName);
    _sciService.editScientistString(oldName, "sex", newSex);
    _sciService.editScientistInt(oldName, "birth", newBirth);

    for (unsigned int i = 0; i < Scientist.size(); i++)
    {
        if (Scientist[i].getName() == oldName)
        {
            newBirth = Scientist[i].getBirth();
            if (newDeath < newBirth)
            {
                QMessageBox::about(this, "Error!", "The death is invalid!");
            }
        }
    }

    _sciService.editScientistInt(oldName,"death",newDeath);
}

void editscigui::on_combobox_birthYears_currentIndexChanged(int index)
{
     QString qstrBirth = ui->comboBox->currentText() ;
     string strBirth = qstrBirth.toStdString();
     _sciBirth = atoi(strBirth.c_str());
}

void editscigui::on_combobox_deathYear_currentIndexChanged(int index)
{
    QString qstrDeath = ui->comboBox_2->currentText();
    string strDeath = qstrDeath.toStdString();
    _sciDeath = atoi(strDeath.c_str());
}
