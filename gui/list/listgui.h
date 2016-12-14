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

    void displayAllScientists();
    void displayScientists  (vector<Scientist>Scientist);

    void displayAllComputers();
    void displayComputers(vector <Computer> Computers);

    void displayRelations ();

    ~listgui();

private slots:
    void on_table_scientists_clicked(const QModelIndex &index);

    void on_table_computers_clicked(const QModelIndex &index);

    void on_input_filter_scientists_textChanged(const QString &arg1);

    void on_input_filter_computers_textChanged(const QString &arg1);

    void on_button_remove_computer_clicked();

    void on_button_remove_scientist_clicked();

private:
    Ui::listgui *ui;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // LISTGUI_H
