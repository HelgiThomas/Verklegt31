#include "infosci.h"
#include "ui_infosci.h"
#include "service/scientistservice.h"

infosci::infosci(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infosci)
{
    ui->setupUi(this);
}

infosci::~infosci()
{
    delete ui;
}
void infosci::setText()
{
    QString name = QString::fromStdString(_sci.getName());

    ui->info_name->setText(name);

    if(_sci.getSex() == "Male")
    {
        ui->info_sex->setText("Male");
    }
    else
    {
        ui->info_sex->setText("Female");
    }

    QString birth = QString::number(_sci.getBirth());
    ui->info_birth->setText(birth);
    if(_sci.getDeath() != 0)
    {
        QString death = QString::number(_sci.getDeath());
        ui->info_death->setText(death);
    }
}
