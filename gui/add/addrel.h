#ifndef ADDREL_H
#define ADDREL_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include <QDialog>
#include <vector>

namespace Ui {
class addrel;
}

class addrel : public QDialog
{
    Q_OBJECT

public:
    explicit addrel(QWidget *parent = 0);
    ~addrel();

    void displaySciRel();

    void displayRelations();

    void displayScientistandComputers();

private slots:

    void on_button_addRel_clicked();

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
