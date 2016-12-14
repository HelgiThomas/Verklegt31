#ifndef SORTGUI_H
#define SORTGUI_H

#include <QDialog>
#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class sortgui;
}

class sortgui : public QDialog
{
    Q_OBJECT

public:
    explicit sortgui(QWidget *parent = 0);
    ~sortgui();

private:
    Ui::sortgui *ui;
    ScientistService _serviceSci;
};

#endif // SORTGUI_H
