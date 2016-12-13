#ifndef REMOVECOMP_H
#define REMOVECOMP_H

#include "service/computerservice.h"
#include "gui/listgui.h"
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

private slots:
    void on_button_removeComp_clicked();

private:
    Ui::removecomp *ui;
    ComputerService _serviceComp;
    listgui _list;
};

#endif // REMOVECOMP_H
