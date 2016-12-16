#ifndef REMOVERELATION_H
#define REMOVERELATION_H

#include <QDialog>
#include <string>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class removeRelation;
}

class removeRelation : public QDialog
{
    Q_OBJECT

public:
    explicit removeRelation(QWidget *parent = 0);
    ~removeRelation();

    void displayRelation();

    void setIdSci(int id);
    void setIdComp(int id);
    void setNameSci(string name);
    void setNameComp(string name);

private slots:
    void on_button_removeComp_clicked();

    void on_pushButton_clicked();

private:
    Ui::removeRelation *ui;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceLink;

    int _idSci;
    int _idComp;
    string _nameSci;
    string _nameComp;
};

#endif // REMOVERELATION_H
