#ifndef ADDGUI_H
#define ADDGUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"
#include <stdlib.h>

#include <QDialog>

namespace Ui {
class addgui;
}

class addgui : public QDialog
{
    Q_OBJECT

public:
    explicit addgui(QWidget *parent = 0);
    ~addgui();


private slots:

    void on_button_addSci_clicked();

private:
    Ui::addgui *ui;
    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

};

#endif // ADDGUI_H
