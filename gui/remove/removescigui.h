#ifndef REMOVESCIGUI_H
#define REMOVESCIGUI_H

#include "service/scientistservice.h"
#include <QDialog>

namespace Ui {
class removescigui;
}

class removescigui : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief removescigui, constructer for the removescigui class
     * @param parent
     */
    explicit removescigui(QWidget *parent = 0);
    ~removescigui();
    /**
     * @brief setId/setName/setSex/setBirth/setDeath, functions that set the variable equal to the param sent in
     * @param id, name, sex, birth, death
     */
    void setId(int id);
    void setName(string name);
    void setSex(string sex);
    void setBirth(int birth);
    void setDeath(int death);
    /**
     * @brief displayScientists, function that displays the scientist choosen
     */
    void displayScientists();

private slots:
    /**
     * @brief on_button_removeSci_clicked, function that removes the science
     */
    void on_button_removeSci_clicked();
    void on_button_removeSci_2_clicked();
private:

    Ui::removescigui *ui;
    ScientistService _serviceSci;

    int _id;
    string _name;
    string _sex;
    int _birth;
    int _death;
};

#endif // REMOVESCIGUI_H
