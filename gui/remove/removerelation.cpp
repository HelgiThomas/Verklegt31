#include "removerelation.h"
#include "ui_removerelation.h"

removeRelation::removeRelation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removeRelation)
{
    ui->setupUi(this);
}

removeRelation::~removeRelation()
{
    delete ui;
}
