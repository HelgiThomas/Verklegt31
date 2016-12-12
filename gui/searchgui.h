#ifndef SEARCHGUI_H
#define SEARCHGUI_H

#include <QDialog>

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
