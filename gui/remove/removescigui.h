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
    int setID();
    void setID(int id);
private slots:

    void on_button_removeSci_clicked();

private:
    void displayScientists();
    int _ID;

    Ui::removescigui *ui;
    ScientistService _serviceSci;
    vector<Scientist> _sci;
};

#endif // REMOVESCIGUI_H
