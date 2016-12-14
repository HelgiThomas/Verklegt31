#ifndef EDITSCIGUI_H
#define EDITSCIGUI_H

#include <QWidget>

#include "service/scientistservice.h"

namespace Ui {
class editscigui;
}

class editscigui : public QWidget
{
    Q_OBJECT

public:
    explicit editscigui(QWidget *parent = 0);
    ~editscigui();

private slots:
    //void on_pushButton_editSci_clicked();

private:
    Ui::editscigui *ui;
    ScientistService _serviceSci;
};

#endif // EDITSCIGUI_H
