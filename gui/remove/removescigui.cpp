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

void removescigui::setID(int id)
{
   _ID = id;
}

void removescigui::on_button_removeSci_clicked()
{

    this->hide();
}

void removescigui::displayScientists()
{
    vector<Scientist> allScientists = _serviceSci.getScientists();
    int tempID = 3;
    cout << "the ID is: " << tempID;
    ui -> table_all -> clearContents();
    ui -> table_all -> setRowCount(1);

    for (unsigned int row = 0 ; row < 1; row++)
    {
        QString name = QString::fromStdString(allScientists[tempID].getName());
        QString sex = QString::fromStdString (allScientists[tempID].getSex());
        QString yearBorn = QString::number(allScientists[tempID].getBirth());
        QString yearDeath = QString::number(allScientists[tempID].getDeath());

        ui -> table_all-> setItem(row, 0, new QTableWidgetItem(name));
        ui -> table_all -> setItem(row, 1, new QTableWidgetItem(sex));
        ui -> table_all -> setItem(row, 2, new QTableWidgetItem(yearBorn));
        ui -> table_all -> setItem(row, 3, new QTableWidgetItem(yearDeath));
    }
}

/*void removescigui::on_button_removeSci_clicked()
{
    for (unsigned int i = 0 ; i < _sci.size() ; i++)
    {
        int id = _sci[i].getId();
        _serviceSci.removeScientist(id);
    }
}*/
