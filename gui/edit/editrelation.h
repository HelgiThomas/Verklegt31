#ifndef EDITRELATIONGUI_H
#define EDITRELATIONGUI_H

#include <QDialog>

namespace Ui {
class editrelationgui;
}

class editrelationgui : public QDialog
{
    Q_OBJECT

public:
    explicit editrelationgui(QWidget *parent = 0);
    ~editrelationgui();

private:
    Ui::editrelationgui *ui;
};

#endif // EDITRELATIONGUI_H
