#ifndef EDITGUI_H
#define EDITGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class editgui;
}

class editgui : public QDialog
{
    Q_OBJECT

public:
    explicit editgui(QWidget *parent = 0);
    ~editgui();

private:
    Ui::editgui *ui;
};

#endif // EDITGUI_H
