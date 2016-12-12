#ifndef REMOVEGUI_H
#define REMOVEGUI_H

#include <QDialog>

namespace Ui {
class removegui;
}

class removegui : public QDialog
{
    Q_OBJECT

public:
    explicit removegui(QWidget *parent = 0);
    ~removegui();

private:
    Ui::removegui *ui;
};

#endif // REMOVEGUI_H
