#include "addcomp.h"
#include "ui_addcomp.h"

addcomp::addcomp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcomp)
{
    ui->setupUi(this);

    for(int i = 2016; i > 0; i--)
    {
        ui->combobox_buildYear->addItem(QString::number(i));
    }

}

addcomp::~addcomp()
{
    delete ui;
}

void addcomp::on_button_addComp_clicked()
{
    int addId = 0;
    string addName = ui->line_compName->text().toStdString();
    string addCompType = _type;
    string addWasBuilt = _wasBuilt;
    int addBuildYear;
    if(ui->radio_yes->isChecked())
    {
        addBuildYear = _buildYear;
    }
    else if(ui->radio_no->isChecked())
    {
        addBuildYear = 0;
    }

    if(!isValidType())
    {
        QMessageBox::about(this, "Error!", "Please choose at least one type!");
    }
    else if(!isValidWasBuilt())
    {
        QMessageBox::about(this, "Error!", "Please say whether the computer was built or not!");
    }
    else
    {
        cout << addId << endl << addName << endl << addBuildYear << endl<< addCompType << endl << addWasBuilt;
        Computer newComp(addId, addName, addBuildYear, addCompType, addWasBuilt);
        _serviceComp.addComputer(newComp);
        exit(10);
    }


}

bool addcomp::isValidType()
{
    bool valid = true;
    if(ui->radio_elec->isChecked())
    {
        _type = "Electronic";
    }
    else if(ui->radio_mech->isChecked())
    {
        _type = "Mechanical";
    }
    else if(ui->radio_trans->isChecked())
    {
        _type = "Transistor";
    }
    else if(ui->radio_oth->isChecked())
    {
        _type = "Other";
    }
    else
    {
        valid = false;
    }
    return valid;

}

bool addcomp::isValidWasBuilt()
{
    bool valid = true;

    if(ui->radio_yes->isChecked())
    {
        _wasBuilt = "Yes";
    }
    else if(ui->radio_no->isChecked())
    {
        _wasBuilt = "No";
    }
    else
    {
        valid = false;
    }

    return valid;
}

void addcomp::on_combobox_buildYear_currentIndexChanged(int index)
{
    _buildYear = index;
    cout << _buildYear;
}
