#include "removescigui.h"
#include "ui_removescigui.h"

removescigui::removescigui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    displayScientists();
}

removescigui::removescigui(vector<Scientist> sci, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removescigui)
{
    ui->setupUi(this);
    _sci = sci;

    //displayScientists();
}

removescigui::~removescigui()
{
    delete ui;
}


/*void removescigui::on_button_removeSci_clicked()
{
    vector<Scientist> scientists = _serviceSci.getScientists();
    int selectedScientist = ui->table_all->currentIndex().row();
    Scientist currentlySelected = scientists.at(selectedScientist);
    int id = currentlySelected.getId();
    _serviceSci.removeScientist(id);

}*/

void removescigui::displayScientists()
{
    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(_sci.size());

    for (unsigned int row = 0 ; row < _sci.size() ; row++)
    {
        Scientist currentScientist = _sci[row];

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


void removescigui::on_button_removeSci_clicked()
{
    for (unsigned int i = 0 ; i < _sci.size() ; i++)
    {
        int id = _sci[i].getId();
        _serviceSci.removeScientist(id);
    }
}
