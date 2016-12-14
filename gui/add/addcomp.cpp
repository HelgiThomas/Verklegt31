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
    string addName;
    string addCompType;
    string addWasBuilt;
    int addBuildYear;
    string addDescription;
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
    else if(!_serviceComp.validName(_type))
    {
         QMessageBox::about(this, "Error!", "Please enter a valid other computer type!");
    }
    else
    {
        addName = ui->line_compName->text().toStdString();
        addCompType = _type;
        addWasBuilt = _wasBuilt;
        Computer newComp(addId, addName, addBuildYear, addCompType, addWasBuilt, addDescription);
        _serviceComp.addComputer(newComp);
        this->hide();
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
        string compType = ui->line_otherType->text().toStdString();
        _type = compType;
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
    QString qstrBuildYear = ui->combobox_buildYear->currentText() ;
    string strBuildYear = qstrBuildYear.toStdString();
    _buildYear = atoi(strBuildYear.c_str());
}
