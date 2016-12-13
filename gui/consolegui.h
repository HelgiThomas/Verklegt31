#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/add/addsci.h"
#include "gui/add/addcomp.h"
#include "gui/editgui.h"
#include "gui/gamegui.h"
#include "gui/listgui.h"
#include "gui/removegui.h"
#include "gui/searchgui.h"
#include "gui/sortgui.h"
#include "gui/utilitygui.h"

namespace Ui {
class consolegui;
}

class consolegui : public QDialog
{
    Q_OBJECT

public:
    explicit consolegui(QWidget *parent = 0);
    ~consolegui();

private slots:


    void on_button_addSci_clicked();

    void on_button_addComp_clicked();

private:
    Ui::consolegui *ui;
    addsci _addsci;
    addcomp _addcomp;
    editgui _edit;
    gamegui _game;
    listgui _list;
    removegui _remove;
    searchgui _search;
    sortgui _sort;
    utilitygui _util;
};

#endif // CONSOLEGUI_H
