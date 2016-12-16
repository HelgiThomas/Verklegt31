#ifndef ADDREL_H
#define ADDREL_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include <QDialog>
#include <vector>
#include <QMessageBox>

namespace Ui {
class addrel;
}

class addrel : public QDialog
{
    Q_OBJECT

public:
    explicit addrel(QWidget *parent = 0);
    ~addrel();

    /**
     * @brief displayScientistandComputers, displays the names of the scientists and computers in a table.
     */
    void displayScientistandComputers();

private slots:

    /**
     * @brief on_button_addRel_clicked, adds the confirmed scientists and computers to the relation database.
     */
    void on_button_addRel_clicked();

    /**
     * @brief on_button_confirmSel_clicked, adds the selected scientist or computer to their designated vector
 * when the confirm button is clicked.
     */
    void on_button_confirmSel_clicked();

private:
    Ui::addrel *ui;
    vector <int> _sciID;
    vector <int> _compID;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // ADDREL_H
