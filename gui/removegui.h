#ifndef REMOVEGUI_H
#define REMOVEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"


namespace Ui {
class removegui;
}

class removegui : public QDialog
{
    Q_OBJECT

public:
    explicit removegui(QWidget *parent = 0);
    ~removegui();

private:
    Ui::removegui *ui;
};

#endif // REMOVEGUI_H
