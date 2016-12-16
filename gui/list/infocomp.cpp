#include "infocomp.h"
#include "ui_infocomp.h"
#include "service/computerservice.h"

infocomp::infocomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infocomp)
{
    ui->setupUi(this);
}

infocomp::~infocomp()
{
    delete ui;
}
