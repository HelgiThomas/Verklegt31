#ifndef EDITCOMPGUI_H
#define EDITCOMPGUI_H

#include <QDialog>
#include <QMessageBox>

#include "model/computer.h"
#include "service/computerservice.h"

namespace Ui {
class editcompgui;
}

class editcompgui : public QDialog
{
    Q_OBJECT

public:
    explicit editcompgui(QWidget *parent = 0);
    ~editcompgui();

    void setId(int id);
    void setName(string name);
    void setType(string type);
    void setWasBuilt(string wasBuilt);
    void setYear(int year);
    void setDescription(string description);

    void displayComputers();
    void displayDescription();

private slots:
    void on_pushButton_editComp_clicked();

    void on_pushButton_back_clicked();

private:
    bool isValidWasBuilt();

    Ui::editcompgui *ui;

    ComputerService _serviceComp;

    int _id;
    string _name;
    string _type;
    string _wasBuilt;
    int _year;
    string _description;
};

#endif // EDITCOMPGUI_H
