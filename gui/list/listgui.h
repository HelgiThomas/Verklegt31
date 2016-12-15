#ifndef LISTGUI_H
#define LISTGUI_H

#include <QDialog>
#include <QModelIndexList>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/add/addsci.h"
#include "gui/add/addcomp.h"
#include "gui/edit/editcomp.h"
#include "gui/edit/editsci.h"
#include "gui/remove/removecomp.h"
#include "gui/remove/removescigui.h"
#include "gui/list/infosci.h"
#include "gui/list/infocomp.h"

namespace Ui {
class listgui;
}

class listgui : public QDialog
{
    Q_OBJECT

public:
    explicit listgui(QWidget *parent = 0);
    ~listgui();

    void displayAllScientists();
    void displayScientists  (vector<Scientist>Scientist);

    void displayAllComputers();
    void displayComputers(vector <Computer> Computers);

    void displayRelations ();

private slots:
    void on_table_scientists_clicked(const QModelIndex &index);

    void on_table_computers_clicked(const QModelIndex &index);

    void on_input_filter_scientists_textChanged(const QString &arg1);

    void on_input_filter_computers_textChanged(const QString &arg1);

    void on_button_add_scientist_clicked();

    void on_button_add_computer_clicked();

    void on_button_edit_scientist_clicked();

    void on_button_edit_computer_clicked();

    void on_button_remove_scientist_clicked();

    void on_button_remove_computer_clicked();

    void on_button_info_scientist_clicked();

    void on_button_info_comp_clicked();

private:
    Ui::listgui *ui;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

    addsci _addsci;
    addcomp _addcomp;

    editcompgui _editComp;
    editscigui _editSci;

    removecomp _removeComp;
    removescigui _removeSci;

    infosci _infoSci;
    infocomp _infoComp;
};

#endif // LISTGUI_H
