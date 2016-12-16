#ifndef EDITSCIGUI_H
#define EDITSCIGUI_H

#include <QDialog>
#include <QMessageBox>

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
    void setCitation(string citation);

    void displayScientists();
    void displayCitation();

private slots:
    void on_pushButton_editSci_clicked();

    void on_pushButton_back_clicked();

private:
    bool isMaleOrFemale();

    Ui::editscigui *ui;

    ScientistService _sciService;

    int _id;
    string _name;
    string _sex;
    int _birth;
    int _death;
    string _citation;
};

#endif // EDITSCIGUI_H
