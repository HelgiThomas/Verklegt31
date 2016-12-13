#ifndef EDITRELATIONGUI_H
#define EDITRELATIONGUI_H

#include <QWidget>

namespace Ui {
class editrelationgui;
}

class editrelationgui : public QWidget
{
    Q_OBJECT

public:
    explicit editrelationgui(QWidget *parent = 0);
    ~editrelationgui();

private:
    Ui::editrelationgui *ui;
};

#endif // EDITRELATIONGUI_H
