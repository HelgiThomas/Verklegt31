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

class addcomp : public QDialog
{
    Q_OBJECT

public:
    explicit addcomp(QWidget *parent = 0);
    ~addcomp();
    bool isValidType();
    bool isValidWasBuilt();

private slots:

    void on_button_addComp_clicked();

    void on_combobox_buildYear_currentIndexChanged(int index);

    void on_radio_yes_clicked();

    void on_radio_no_clicked();

private:
    Ui::addcomp *ui;
    ComputerService _serviceComp;
    string _type;
    string _wasBuilt;
    int _buildYear;

    void resetComp();
};

#endif // ADDCOMP_H
