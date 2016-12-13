#ifndef LISTGUI_H
#define LISTGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class listgui;
}

class listgui : public QDialog
{
    Q_OBJECT

public:
    explicit listgui(QWidget *parent = 0);

    void displayScientists  ();
    void displayComputers ();
    void displayRelations ();
    ~listgui();

private:
    Ui::listgui *ui;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // LISTGUI_H
