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
    explicit removecomp(vector<Computer> comp, QWidget *parent = 0);
    ~removecomp();

private slots:
    /*void on_button_removeComp_clicked();

    void on_table_comp_clicked(const QModelIndex &index);*/

    void on_button_removeComp_clicked();

private:
    void displayComputers();

    Ui::removecomp *ui;
    ComputerService _serviceComp;

    vector<Computer> _comp;
};

#endif // REMOVECOMP_H
