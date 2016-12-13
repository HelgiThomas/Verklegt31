#ifndef REMOVESCIGUI_H
#define REMOVESCIGUI_H

#include "service/scientistservice.h"
#include "gui/listgui.h"
#include <QDialog>

namespace Ui {
class removescigui;
}

class removescigui : public QDialog
{
    Q_OBJECT

public:
    explicit removescigui(QWidget *parent = 0);
    ~removescigui();

private slots:
    void on_button_removeSci_clicked();

private:
    Ui::removescigui *ui;
    ScientistService _serviceSci;
    listgui _list;
};

#endif // REMOVESCIGUI_H
