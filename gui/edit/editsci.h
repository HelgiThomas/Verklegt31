#ifndef EDITSCIGUI_H
#define EDITSCIGUI_H

#include <QWidget>

namespace Ui {
class editscigui;
}

class editscigui : public QWidget
{
    Q_OBJECT

public:
    explicit editscigui(QWidget *parent = 0);
    ~editscigui();

private:
    Ui::editscigui *ui;
};

#endif // EDITSCIGUI_H
