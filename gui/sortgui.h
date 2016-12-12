#ifndef SORTGUI_H
#define SORTGUI_H

#include <QDialog>

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
};

#endif // SORTGUI_H
