#include "addsci.h"
#include "ui_addsci.h"
#include "stdlib.h"

using namespace std;

addsci::addsci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsci)
{
    ui->setupUi(this);
    for(int i = 2016; i > 0; i--)
    {
        ui->combobox_birthYears->addItem(QString::number(i));
    }

    for(int i = 2016; i > 0; i--)
    {
        ui->combobox_deathYear->addItem(QString::number(i));
    }



}

addsci::~addsci()
{
    delete ui;
}



void addsci::on_button_addSci_clicked()
{

    int birthNum = 0;
    int deathNum = 0;

    int addId = 0;
    string addName = ui->line_sciName->text().toStdString();
    string addSex = isMaleOrFemale();
    birthNum = _sciBirth;
    deathNum = _sciDeath;
    QString QaddCitation = ui->line_sciCitation->toPlainText();
    ui->line_sciCitation->setText(QaddCitation);
    string addCitation = QaddCitation.toStdString();
    if(birthNum > deathNum)
    {
        //TODO: error message:
        QMessageBox::about(this, "Error!", "A person can not die before their birth!");
    }
    else if(!_serviceSci.validName(addName))
    {
        //TODO: error message:
        QMessageBox::about(this, "Error!", "The name is invalid!");
    }
    else
    {
        Scientist newSci(addId, addName, addSex, birthNum, deathNum, addCitation);
        _serviceSci.addScientist(newSci);
        exit(10);
    }

}

string addsci::isMaleOrFemale()
{
    string sex;
    if(ui->radio_male->isChecked())
    {
        sex = "Male";
    }
    else if(ui->radio_female->isChecked())
    {
        sex = "Female";
    }

    return sex;
}

void addsci::on_combobox_birthYears_currentIndexChanged(int index)
{
     QString qstrBirth = ui->combobox_birthYears->currentText() ;
     string strBirth = qstrBirth.toStdString();
     _sciBirth = atoi(strBirth.c_str());
}

void addsci::on_combobox_deathYear_currentIndexChanged(int index)
{
    QString qstrDeath = ui->combobox_deathYear->currentText();
    string strDeath = qstrDeath.toStdString();
    _sciDeath = atoi(strDeath.c_str());
}
