#ifndef INFOSCI_H
#define INFOSCI_H

#include <QDialog>
#include "service/scientistservice.h"
#include "model/scientist.h"

namespace Ui {
class infosci;
}

class infosci : public QDialog
{
    Q_OBJECT

public:
    explicit infosci(QWidget *parent = 0);
    ~infosci();

    void setId(int id);
    void setName(string name);
    void setSex(string sex);
    void setBirth(int birth);
    void setDeath(int death);
    void setCitation(string citation);

    void displayScientists();
    void displayCitation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::infosci *ui;

    ScientistService _sciService;
    Scientist _sci;

    int _id;
    string _name;
    string _sex;
    int _birth;
    int _death;
    string _citation;
};

#endif // INFOSCI_H
