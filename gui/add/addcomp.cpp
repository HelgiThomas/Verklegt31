#include "addcomp.h"
#include "ui_addcomp.h"

addcomp::addcomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcomp)
{
    ui->setupUi(this);
}

addcomp::~addcomp()
{
    delete ui;
}

void addcomp::on_button_addComp_clicked()
{

    int buildYearNum = 0;


    int addId = 0;
    string addName = ui->line_compName->text().toStdString();
    string addCompType = ui->line_compType->text().toStdString();
    string addWasBuilt = ui->line_compWasBuilt->text().toStdString();
    string addBuildYear = ui->line_compBuildYear->text().toStdString();

    buildYearNum = atoi(addBuildYear.c_str());


    Computer newComp(addId, addName, buildYearNum, addCompType, addWasBuilt);

    _serviceComp.addComputer(newComp);

}
