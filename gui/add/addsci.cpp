#include "addsci.h"
#include "ui_addsci.h"


using namespace std;

addsci::addsci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsci)
{
    ui->setupUi(this);
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
    string addSex = ui->line_sciSex->text().toStdString();
    string addBirth = ui->line_sciBirth->text().toStdString();
    string addDeath = ui->line_sciDeath->text().toStdString();
    string addCitation = ui->line_sciCitation->text().toStdString();

    birthNum = atoi(addBirth.c_str());
    deathNum = atoi(addDeath.c_str());

    Scientist newSci(addId, addName, addSex, birthNum, deathNum, addCitation);
    _serviceSci.addScientist(newSci);



    exit(10);
}
