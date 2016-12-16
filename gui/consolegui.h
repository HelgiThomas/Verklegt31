#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/add/addsci.h"
#include "gui/add/addcomp.h"
#include "gui/add/addrel.h"
#include "gui/edit/editcomp.h"
#include "gui/edit/editrelation.h"
#include "gui/edit/editsci.h"
#include "gui/game/gamegui.h"
#include "gui/list/listgui.h"
#include "gui/remove/removescigui.h"
#include "gui/remove/removecomp.h"
#include "gui/search/searchgui.h"
#include "gui/sort/sortgui.h"
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

    void on_button_list_clicked();

private:
    Ui::consolegui *ui;
    addsci _addsci;
    addcomp _addcomp;
    addrel _addrel;
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
