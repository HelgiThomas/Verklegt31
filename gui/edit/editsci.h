#ifndef EDITSCIGUI_H
#define EDITSCIGUI_H

#include <QDialog>
#include <string>

#include "model/scientist.h"
#include "service/scientistservice.h"


namespace Ui {
class editscigui;
}

class editscigui : public QDialog
{
    Q_OBJECT

public:
    explicit editscigui(QWidget *parent = 0);
    ~editscigui();

    void setId(int id);
    void setName(string name);
    void setSex(string sex);
    void setBirth(int birth);
    void setDeath(int death);

    void setText();
    string chooseSex();

private slots:
    void on_radioButton_name_clicked();

    void on_radioButton_sex_clicked();

    void on_radioButton_birth_clicked();

    void on_radioButton_death_clicked();

    void on_pushButton_editSci_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::editscigui *ui;

    ScientistService _sciService;

    int _sciBirth;
    int _sciDeath;

    int _id;
    string _name;
    string _sex;
    int _birth;
    int _death;
};

#endif // EDITSCIGUI_H
