#include "utilitygui.h"
#include "ui_utilitygui.h"

utilitygui::utilitygui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::utilitygui)
{
    ui->setupUi(this);
}

utilitygui::~utilitygui()
{
    delete ui;
}
