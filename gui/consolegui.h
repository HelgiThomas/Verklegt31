#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "gui/game/citationgame.h"

#include "gui/list/listgui.h"


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

    void on_button_list_5_clicked();

    void on_button_list_2_clicked();

private:
    Ui::consolegui *ui;

    CitationGame _game1;

    listgui _list;

    int _totalScore;
};

#endif // CONSOLEGUI_H
