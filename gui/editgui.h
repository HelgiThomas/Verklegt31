#ifndef EDITGUI_H
#define EDITGUI_H

#include <QDialog>

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
