#include "removescigui.h"
#include "ui_removescigui.h"

removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    displayScientists();
}

removescigui::~removescigui()
{
    delete ui;
}

void removescigui::on_button_removeSci_clicked()
{

    this->destroy();
    this->hide();
}

void removescigui::setId(int id)
{
    _ID = id;
}

void removescigui::displayScientists()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();

    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(1);

    QString name = QString::fromStdString(allScientists[_ID].getName());
    QString sex = QString::fromStdString (allScientists[_ID].getSex());
    QString yearBorn = QString::number(allScientists[_ID].getBirth());
    QString yearDeath = QString::number(allScientists[_ID].getDeath());

    ui -> table_all-> setItem(0, 0, new QTableWidgetItem(name));
    ui -> table_all -> setItem(0, 1, new QTableWidgetItem(sex));
    ui -> table_all -> setItem(0, 2, new QTableWidgetItem(yearBorn));
    ui -> table_all -> setItem(0, 3, new QTableWidgetItem(yearDeath));
}
