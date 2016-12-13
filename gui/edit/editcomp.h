#ifndef EDITCOMPGUI_H
#define EDITCOMPGUI_H

#include <QWidget>

namespace Ui {
class editcompgui;
}

class editcompgui : public QWidget
{
    Q_OBJECT

public:
    explicit editcompgui(QWidget *parent = 0);
    ~editcompgui();

private:
    Ui::editcompgui *ui;
};

#endif // EDITCOMPGUI_H
