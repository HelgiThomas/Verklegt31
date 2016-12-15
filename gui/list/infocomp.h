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
    void setText();

private:
    Ui::infocomp *ui;
    ComputerService _compService;
    Computer _comp;

};

#endif // INFOCOMP_H
