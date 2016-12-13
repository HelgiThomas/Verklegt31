#ifndef REMOVECOMP_H
#define REMOVECOMP_H

#include "service/computerservice.h"
#include "gui/consolegui.h"
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
    void on_button_goBack_clicked();

private:
    Ui::removecomp *ui;
    ComputerService _serviceComp;
    consolegui _consolehh;
};

#endif // REMOVECOMP_H
