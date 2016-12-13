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

private slots:
    void on_button_removeSci_clicked();

    void on_table_all_clicked(const QModelIndex &index);

private:
    Ui::removescigui *ui;
    ScientistService _serviceSci;
    void displayScientists();
};

#endif // REMOVESCIGUI_H
