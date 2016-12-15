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
    explicit removescigui(QWidget *parent = 0);
    ~removescigui();

    void setId(int id);
    void setName(string name);
    void setSex(string sex);
    void setBirth(int birth);
    void setDeath(int death);

    void displayScientists();

private slots:
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
