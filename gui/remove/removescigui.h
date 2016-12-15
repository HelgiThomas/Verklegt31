#ifndef REMOVESCIGUI_H
#define REMOVESCIGUI_H

#include "service/scientistservice.h"
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

    void setId(int id);
private slots:
    void on_button_removeSci_clicked();

private:
    //void displayScientists();

    Ui::removescigui *ui;
    ScientistService _serviceSci;
    int _ID;
};

#endif // REMOVESCIGUI_H
