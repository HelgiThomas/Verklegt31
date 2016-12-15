#include "infocomp.h"
#include "ui_infocomp.h"
#include "service/computerservice.h"

infocomp::infocomp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infocomp)
{
    ui->setupUi(this);
}

infocomp::~infocomp()
{
    delete ui;
}

void infocomp::setText()
{
    QString name = QString::fromStdString(_comp.getName());

    ui->info_name->setText(name);

    if(_comp.getCompType() == "Mechanical")
    {
        ui->info_type->setText("Mechanical");
    }
    else if(_comp.getCompType() == "Transistor")
    {
        ui->info_type->setText("Transistor");
    }
    else if(_comp.getCompType() == "Electronic")
    {
        ui->info_type->setText("Electronic");
    }
    else
    {
        ui->info_type->setText("Other");
    }

    if(_comp.getWasBuilt() == "Yes")
    {
        ui->info_built->setText("Yes");
    }
    else
    {
        ui->info_built->setText("No");
    }

    if(_comp.getWasBuilt() != "No")
    {
        QString year = QString::number(_comp.getBuildYear());
        ui->info_year->setText(year);
    }
}
