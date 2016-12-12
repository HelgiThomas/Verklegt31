#ifndef LISTGUI_H
#define LISTGUI_H

#include <QDialog>

namespace Ui {
class listgui;
}

class listgui : public QDialog
{
    Q_OBJECT

public:
    explicit listgui(QWidget *parent = 0);
    ~listgui();

private:
    Ui::listgui *ui;
};

#endif // LISTGUI_H
