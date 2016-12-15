#ifndef REMOVECOMP_H
#define REMOVECOMP_H

#include "service/computerservice.h"

#include <QDialog>

namespace Ui {
class removecomp;
}

class removecomp : public QDialog
{
    Q_OBJECT

public:
    explicit removecomp(QWidget *parent = 0);
    ~removecomp();

    void setId(int id);

private slots:
    void on_button_removeComp_clicked();

private:
    void displayComputers();

    Ui::removecomp *ui;
    ComputerService _serviceComp;

    int _ID;
};

#endif // REMOVECOMP_H
