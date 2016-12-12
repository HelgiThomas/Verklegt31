#ifndef ADDGUI_H
#define ADDGUI_H

#include <QDialog>

namespace Ui {
class addgui;
}

class addgui : public QDialog
{
    Q_OBJECT

public:
    explicit addgui(QWidget *parent = 0);
    ~addgui();

private:
    Ui::addgui *ui;
};

#endif // ADDGUI_H
