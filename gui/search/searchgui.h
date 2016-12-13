#ifndef SEARCHGUI_H
#define SEARCHGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"


namespace Ui {
class searchgui;
}

class searchgui : public QDialog
{
    Q_OBJECT

public:
    explicit searchgui(QWidget *parent = 0);
    ~searchgui();

private:
    Ui::searchgui *ui;
};

#endif // SEARCHGUI_H
