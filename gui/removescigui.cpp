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
    vector<Scientist> scientists = _serviceSci.getScientists();
    int selectedScientist = ui->table_all->currentIndex().row();
    Scientist currentlySelected = scientists.at(selectedScientist);
    int id = currentlySelected.getId();
    _serviceSci.removeScientist(id);

    exit(10);
}

void removescigui::displayScientists()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();
    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(allScientists.size());

    for (unsigned int row = 0 ; row < allScientists.size() ; row++)
    {
        Scientist currentScientist = allScientists[row];

        QString name = QString::fromStdString(currentScientist.getName());
        QString sex = QString::fromStdString (currentScientist.getSex());
        QString yearBorn = QString::number(currentScientist.getBirth());
        QString yearDeath = QString::number(currentScientist.getDeath());


        ui -> table_all -> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_all -> setItem(row, 1, new QTableWidgetItem(sex));
        ui -> table_all -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> table_all -> setItem(row, 3, new QTableWidgetItem(yearDeath));

    }
}


void removescigui::on_table_all_clicked(const QModelIndex &index)
{
     ui->button_removeSci->setEnabled(true);
}
