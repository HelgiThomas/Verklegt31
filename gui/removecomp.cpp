#include "removecomp.h"
#include "ui_removecomp.h"

removecomp::removecomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecomp)
{
    ui->setupUi(this);
}

removecomp::~removecomp()
{
    delete ui;
}

void removecomp::on_button_removeComp_clicked()
{
    int compNum;
    string number = ui->line_numOfComp->text().toStdString();
    compNum = atoi(number.c_str());
    _serviceComp.removeComputer(compNum);

    exit(10);
}



