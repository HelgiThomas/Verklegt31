#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/add/addsci.h"
#include "gui/add/addcomp.h"
#include "gui/edit/editcomp.h"
#include "gui/edit/editrelation.h"
#include "gui/edit/editsci.h"
#include "gui/gamegui.h"
#include "gui/listgui.h"
#include "gui/removescigui.h"
#include "gui/removecomp.h"
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

    void on_button_removeSci_clicked();
    void on_button_removeComp_clicked();

    void on_button_list_clicked();

private:
    Ui::consolegui *ui;
    addsci _addsci;
    addcomp _addcomp;
    editscigui _editsci;
    editcompgui _editcomp;
    editrelationgui _editrelation;
    gamegui _game;
    listgui _list;
    removescigui _removeSci;
    removecomp _removeComp;
    searchgui _search;
    sortgui _sort;
    utilitygui _util;
};

#endif // CONSOLEGUI_H
