#include "editdisplay.h"
#include "ui_editdisplay.h"

editdisplay::editdisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editdisplay)
{
    ui->setupUi(this);
}

editdisplay::~editdisplay()
{
    delete ui;
}
