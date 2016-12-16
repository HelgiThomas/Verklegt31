#include "addsci.h"
#include "ui_addsci.h"
#include "stdlib.h"
#include "qfiledialog.h"

using namespace std;

addsci::addsci(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addsci)
{
    ui->setupUi(this);
    for(int i = 2016; i > 0; i--)
    {
        ui->combobox_birthYears->addItem(QString::number(i));
    }

    for(int i = 2016; i > 0; i--)
    {
        ui->combobox_deathYear->addItem(QString::number(i));
    }
}

addsci::~addsci()
{
    delete ui;
}
/**
 * @brief addsci::on_button_addSci_clicked, adds the scientist to the table when the button is clicked.
 */
void addsci::on_button_addSci_clicked()
{

    int birthNum = 0;
    int deathNum = 0;

    int addId = 0;
    string addName = ui->line_sciName->text().toStdString();
    string addImage = ui ->input_addsci -> text ().toStdString();
    cout << addImage;
    string addSex = chooseSex();
    birthNum = _sciBirth;
    deathNum = _sciDeath;
    QString QaddCitation = ui->line_sciCitation->toPlainText();
    ui->line_sciCitation->setText(QaddCitation);
    string addCitation = QaddCitation.toStdString();
    if(birthNum > deathNum && deathNum != 0)
    {
        //TODO: error message:
        QMessageBox::about(this, "Error!", "A person can not die before their birth!");
    }
    else if(!_serviceSci.validName(addName))
    {
        //TODO: error message:
        QMessageBox::about(this, "Error!", "The name is invalid!");
    }
    else if(!isMaleOrFemale())
    {
         QMessageBox::about(this, "Error!", "Please choose sex!");
    }
    else
    {
        Scientist newSci(addId, addName, addSex, birthNum, deathNum, addCitation, addImage);
        _serviceSci.addScientist(newSci);
        close();
    }

    resetAdd();
}
/**
 * @brief addsci::chooseSex, sets the sex of the scientist to the sex selected by the user.
 * @return returns the sex selected by the user.
 */
string addsci::chooseSex()
{
    string sex;
    if(ui->radio_male->isChecked())
    {
        sex = "Male";
    }
    else if(ui->radio_female->isChecked())
    {
        sex = "Female";
    }

    return sex;
}
/**
 * @brief addsci::isMaleOrFemale, checks wether the user has chosen a sex for the scientist
 * @return false if the user doesn't choose anyting, true otherwise.
 */
bool addsci::isMaleOrFemale()
{

    if(ui->radio_male->isChecked())
    {
        return true;
    }
    else if(ui->radio_female->isChecked())
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * @brief addsci::on_combobox_birthYears_currentIndexChanged, sets the scientists birth year to the selected birth year in
 * the combobox.
 */
void addsci::on_combobox_birthYears_currentIndexChanged()
{
     QString qstrBirth = ui->combobox_birthYears->currentText() ;
     string strBirth = qstrBirth.toStdString();
     _sciBirth = atoi(strBirth.c_str());
}
/**
 * @brief addsci::on_combobox_deathYear_currentIndexChanged, sets the scientists deat year to the selected deat year in
 * the combobox.
 */
void addsci::on_combobox_deathYear_currentIndexChanged()
{
    QString qstrDeath = ui->combobox_deathYear->currentText();
    string strDeath = qstrDeath.toStdString();
    _sciDeath = atoi(strDeath.c_str());
}
/**
 * @brief addsci::on_button_browse_clicked, lets the user browse for a photo for the scientist.
 */
void addsci::on_button_browse_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"Search for image", "", "Image files (*.png *jpg");
    ui -> input_addsci -> setText (filePath);
}
/**
 * @brief addsci::on_rbutton_dead_clicked, enables the death year combo box when the "no" radio button is clicked,
 */
void addsci::on_rbutton_dead_clicked()
{
    ui->combobox_deathYear->setEnabled(true);
}
/**
 * @brief addsci::on_rbutton_alive_clicked, disables the death year combo box when the "no" radio button is clicked,
 */
void addsci::on_rbutton_alive_clicked()
{
    ui->combobox_deathYear->setEnabled(false);
    _sciDeath = 0;
}
/**
 * @brief addsci::resetAdd, when the user adds a scientist and then wants to add another scientist, the info about the
 * previously added scientist does not persist in the add window.
 */
void addsci::resetAdd()
{
    ui->line_sciName->setText("");
    ui->combobox_birthYears->setCurrentIndex(2016);
    ui->combobox_deathYear->setCurrentIndex(2016);
    ui->radio_female->setAutoExclusive(false);
    ui->radio_female->setChecked(false);
    ui->radio_female->setAutoExclusive(true);
    ui->radio_male->setAutoExclusive(false);
    ui->radio_male->setChecked(false);
    ui->radio_male->setAutoExclusive(true);
    ui->rbutton_alive->setAutoExclusive(false);
    ui->rbutton_alive->setChecked(false);
    ui->rbutton_alive->setAutoExclusive(true);
    ui->rbutton_dead->setAutoExclusive(false);
    ui->rbutton_dead->setChecked(false);
    ui->rbutton_dead->setAutoExclusive(true);
    ui->line_sciCitation->setText("");
    ui->input_addsci->setText("");
}
