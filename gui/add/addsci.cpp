#include "addsci.h"
#include "ui_addsci.h"


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

    for(int i = 2016; 1950 < i; i--)
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
    //string addDeath = ui->line_sciDeath->text().toStdString(); */
    string addCitation = ui->line_sciCitation->text().toStdString();

   // birthNum = atoi(addBirth.c_str());
   // deathNum = atoi(addDeath.c_str());

 //   Scientist newSci(addId, addName, addSex, birthNum, deathNum, addCitation);
  //  _serviceSci.addScientist(newSci);



    exit(10);
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


void addsci::on_combobox_birthYears_activated(int index)
{
    _sciBirth = ui->combobox_birthYears->itemData(index).toInt();
}
