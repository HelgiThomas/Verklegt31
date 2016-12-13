#include "addrel.h"
#include "ui_addrel.h"

addrel::addrel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrel)
{
    ui->setupUi(this);
}

addrel::~addrel()
{
    delete ui;
}
