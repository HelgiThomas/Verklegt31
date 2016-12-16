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

/**
 * @brief addcomp::on_button_addComp_clicked, adds computer to the table when the button is clicked.
 */

void addcomp::on_button_addComp_clicked()
{
    int addId = 0;
    string addName;
    string addCompType;
    string addWasBuilt;
    int addBuildYear;
    QString QaddDescription = ui->text_description->toPlainText();
    ui->text_description->setText(QaddDescription);
    string addDescription = QaddDescription.toStdString();
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

    resetComp();
}

/**
 * @brief addcomp::isValidType, checks if the type that the user put in is valid.
 * @return true if the input is valid, false otherwise.
 */

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
/**
 * @brief addcomp::isValidWasBuilt, checks if the user put in wether the computer was built or not.
 * @return false if the user did not put in anything, true otherwise.
 */

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

/**
 * @brief addcomp::on_combobox_buildYear_currentIndexChanged, sets the computers build year to the build year selected in the
 * combo box.
 */

void addcomp::on_combobox_buildYear_currentIndexChanged()
{
    QString qstrBuildYear = ui->combobox_buildYear->currentText() ;
    string strBuildYear = qstrBuildYear.toStdString();
    _buildYear = atoi(strBuildYear.c_str());
}

/**
 * @brief addcomp::on_radio_yes_clicked, enables the build year combo box if the user clicks the yes radio button.
 */

void addcomp::on_radio_yes_clicked()
{
    ui->combobox_buildYear->setEnabled(true);
}

/**
 * @brief addcomp::on_radio_no_clicked, disables the build year combo box if the user clicks the no radio button.
 */

void addcomp::on_radio_no_clicked()
{
    ui->combobox_buildYear->setEnabled(false);
    _buildYear = 0;
}

/**
 * @brief addcomp::resetComp, when the user adds a computer and then wants to add another computer, the info about the
 * previously added computer does not persist in the add window.
 */

void addcomp::resetComp()
{
    ui->line_compName->setText("");
    ui->radio_mech->setAutoExclusive(false);
    ui->radio_mech->setChecked(false);
    ui->radio_mech->setAutoExclusive(true);
    ui->radio_elec->setAutoExclusive(false);
    ui->radio_elec->setChecked(false);
    ui->radio_elec->setAutoExclusive(true);
    ui->radio_trans->setAutoExclusive(false);
    ui->radio_trans->setChecked(false);
    ui->radio_trans->setAutoExclusive(true);
    ui->radio_oth->setAutoExclusive(false);
    ui->radio_oth->setChecked(false);
    ui->radio_oth->setAutoExclusive(true);
    ui->radio_yes->setAutoExclusive(false);
    ui->radio_yes->setChecked(false);
    ui->radio_yes->setAutoExclusive(true);
    ui->radio_no->setAutoExclusive(false);
    ui->radio_no->setChecked(false);
    ui->radio_no->setAutoExclusive(true);
    ui->combobox_buildYear->setCurrentIndex(2016);
    ui->line_otherType->setText("");
}
