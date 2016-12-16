#ifndef ADDCOMP_H
#define ADDCOMP_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include <iostream>
#include <QDialog>
#include <QMessageBox>

using namespace std;

namespace Ui {
class addcomp;
}

/**
 * @brief The addcomp class, handles operations in the add computers window.
 */

class addcomp : public QDialog
{
    Q_OBJECT

public:
    explicit addcomp(QWidget *parent = 0);
    ~addcomp();

    /**
     * @brief isValidType, checks if the type that the user put in is valid.
     * @return true if the input is valid, false otherwise.
     * @return
     */
    bool isValidType();

    /**
     * @brief isValidWasBuilt, checks if the user put in wether the computer was built or not.
     * @return false if the user did not put in anything, true otherwise.
     * @return
     */
    bool isValidWasBuilt();

private slots:

    /**
     * @brief on_button_addComp_clicked, adds computer to the table when the button is clicked.
     */
    void on_button_addComp_clicked();

    /**
     * @brief on_combobox_buildYear_currentIndexChanged,adds computer to the table when the button is clicked.
     */
    void on_combobox_buildYear_currentIndexChanged();

    /**
     * @brief on_radio_yes_clicked, disables the build year combo box if the user clicks the yes radio button.
     */
    void on_radio_yes_clicked();

    /**
     * @brief on_radio_no_clicked, enable the build year combo box if the user clicks the yes radio button.
     */
    void on_radio_no_clicked();

private:
    Ui::addcomp *ui;
    ComputerService _serviceComp;
    string _type;
    string _wasBuilt;
    string _description;
    int _buildYear;

    /**
     * @brief resetComp,  when the user adds a computer and then wants to add another computer, the info about the
     * previously added computer does not persist in the add window.
     */
    void resetComp();
};

#endif // ADDCOMP_H
