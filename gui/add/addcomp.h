#ifndef ADDCOMP_H
#define ADDCOMP_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include <iostream>
#include <QDialog>

using namespace std;

namespace Ui {
class addcomp;
}

class addcomp : public QDialog
{
    Q_OBJECT

public:
    explicit addcomp(QWidget *parent = 0);
    ~addcomp();

private slots:

    void on_button_addComp_clicked();

private:
    Ui::addcomp *ui;
    ComputerService _serviceComp;
};

#endif // ADDCOMP_H
