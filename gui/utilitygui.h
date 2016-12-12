#ifndef UTILITYGUI_H
#define UTILITYGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class utilitygui;
}

class utilitygui : public QDialog
{
    Q_OBJECT

public:
    explicit utilitygui(QWidget *parent = 0);
    ~utilitygui();

private:
    Ui::utilitygui *ui;
};

#endif // UTILITYGUI_H
