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
    string isMaleOrFemale();
    ~addsci();


private slots:

    void on_button_addSci_clicked();

    void on_combobox_birthYears_currentIndexChanged(int index);

    void on_combobox_deathYear_currentIndexChanged(int index);

private:
    Ui::addsci *ui;
    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
    int _sciBirth;
    int _sciDeath;

};

#endif // ADDGUI_H
