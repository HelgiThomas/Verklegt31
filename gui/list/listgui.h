#ifndef LISTGUI_H
#define LISTGUI_H

#include <QDialog>
#include <QModelIndexList>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/add/addsci.h"
#include "gui/add/addcomp.h"
#include "gui/add/addrel.h"
#include "gui/edit/editcomp.h"
#include "gui/edit/editsci.h"
#include "gui/remove/removecomp.h"
#include "gui/remove/removescigui.h"
#include "gui/list/infosci.h"
#include "gui/list/infocomp.h"

namespace Ui {
class listgui;
}
/**
 * @brief The listgui class, the class of listgui
 */
class listgui : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief listgui, constructer of the listgui class
     * @param parent
     */
    explicit listgui(QWidget *parent = 0);
    ~listgui();
    /**
     * @brief displayAllScientists/displayAllComputers,displayRelations, functions that call on the display functions
     */
    void displayAllScientists();
    void displayAllComputers();
    void displayRelations ();

    /**
     * @brief displayScientists/displayComputers, functions that take a vector as a param and displays the vector
     * @param Scientist/Computers
     */
    void displayScientists  (vector<Scientist>Scientist);
    void displayComputers(vector <Computer> Computers);
private slots:
    /**
     * @brief on_input_filter_scientists/computers_textChanged, functions that return a vector of the searched string
     * @param arg1
     */
    void on_input_filter_scientists_textChanged(const QString &arg1);
    void on_input_filter_computers_textChanged(const QString &arg1);
    /**
     * @brief on_table_scientists/computers_clicked, functions set the variables equal to the index that the user is on
     * @param index
     */
    void on_table_scientists_clicked(const QModelIndex &index);
    void on_table_computers_clicked(const QModelIndex &index);
    /**
     * @brief on_button_add_scientist/computer/relation_clicked, functions that run the add classes
     */
    void on_button_add_scientist_clicked();
    void on_button_add_computer_clicked();
    void on_button_add_relation_clicked();
    /**
     * @brief on_button_edit_scientist_clicked, functiosn that run the edit classes
     */
    void on_button_edit_scientist_clicked();
    void on_button_edit_computer_clicked();
    /**
     * @brief on_button_remove_scientist_clicked, functions that run the remove classes
     */
    void on_button_remove_scientist_clicked();
    void on_button_remove_computer_clicked();
    /**
     * @brief on_button_info_scientist_clicked, functions that run the info classes
     */
    void on_button_info_scientist_clicked();
    void on_button_info_comp_clicked();

private:
    Ui::listgui *ui;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

    addsci _addsci;
    addcomp _addcomp;
    addrel _addrel;

    editcompgui _editComp;
    editscigui _editSci;

    removecomp _removeComp;
    removescigui _removeSci;

    infosci _infoSci;
    infocomp _infoComp;
};

#endif // LISTGUI_H
