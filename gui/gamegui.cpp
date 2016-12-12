#include "gamegui.h"
#include "ui_gamegui.h"

gamegui::gamegui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamegui)
{
    ui->setupUi(this);
}

gamegui::~gamegui()
{
    delete ui;
}
