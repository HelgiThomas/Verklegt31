#ifndef ADDGUI_H
#define ADDGUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include <iostream>
#include <stdlib.h>
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QMessageBox>
#include <QTextStream>

using namespace std;

namespace Ui {
class addsci;
}

class addsci : public QDialog
{
    Q_OBJECT

public:
    explicit addsci(QWidget *parent = 0);
    /**
     * @brief isMaleOrFemale, checks wether the user has chosen a sex for the scientist
     * @return false if the user doesn't choose anything, true otherwise.
     */
    bool isMaleOrFemale();
    /**
     * @brief chooseSex, sets the sex of the scientist to the sex selected by the user.
     * @return returns the sex selected by the user.
     */
    string chooseSex();
    ~addsci();


private slots:
    /**
      * @brief on_button_addSci_clicked, adds the scientist to the table when the button is clicked.
      */
    void on_button_addSci_clicked();
    /**
      * @brief on_combobox_birthYears_currentIndexChanged, sets the scientists birth year to the selected birth year in
      * the combobox.
      */
    void on_combobox_birthYears_currentIndexChanged();
    /**
      * @brief on_combobox_deathYear_currentIndexChanged, sets the scientists death year to the selected death year in
      * the combobox.
      */
    void on_combobox_deathYear_currentIndexChanged();
    /**
      * @brief on_button_browse_clicked, lets the user browse for a photo for the scientist.
      */
    void on_button_browse_clicked();
    /**
      * @brief on_rbutton_dead_clicked, enables the death year combo box when the "no" radio button is clicked,
      */
    void on_rbutton_dead_clicked();
    /**
      * @brief on_rbutton_alive_clicked, disables the death year combo box when the "no" radio button is clicked,
      */
    void on_rbutton_alive_clicked();

private:
    Ui::addsci *ui;
    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
    int _sciBirth;
    int _sciDeath;
    string _sex;
    /**
      * @brief resetAdd, when the user adds a scientist and then wants to add another scientist, the info about the
      * previously added scientist does not persist in the add window.
      */
    void resetAdd();

};

#endif // ADDGUI_H
