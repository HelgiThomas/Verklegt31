#include "infosci.h"
#include "ui_infosci.h"
#include "service/scientistservice.h"

infosci::infosci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infosci)
{
    ui->setupUi(this);
}

infosci::~infosci()
{
    delete ui;
}

