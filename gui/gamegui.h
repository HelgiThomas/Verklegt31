#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QDialog>

namespace Ui {
class gamegui;
}

class gamegui : public QDialog
{
    Q_OBJECT

public:
    explicit gamegui(QWidget *parent = 0);
    ~gamegui();

private:
    Ui::gamegui *ui;
};

#endif // GAMEGUI_H
