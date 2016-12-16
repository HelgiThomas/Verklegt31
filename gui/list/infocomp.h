#ifndef INFOCOMP_H
#define INFOCOMP_H

#include <QDialog>
#include "service/computerservice.h"
#include "model/computer.h"

namespace Ui {
class infocomp;
}

class infocomp : public QDialog
{
    Q_OBJECT

public:
    explicit infocomp(QWidget *parent = 0);
    ~infocomp();

    void setId(int id);
    void setName(string name);
    void setType(string type);
    void setWasBuilt(string wasBuilt);
    void setYear(int year);
    void setDescription(string description);

    void displayComputers();
    void displayDescription();

private slots:
    void on_pushButton_clicked();

private:
    Ui::infocomp *ui;

    ComputerService _compService;
    Computer _comp;

    int _id;
    string _name;
    string _type;
    string _wasBuilt;
    int _year;
    string _description;
};

#endif // INFOCOMP_H
