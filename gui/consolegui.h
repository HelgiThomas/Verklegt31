#ifndef CONSOLEGUI_H
#define CONSOLEGUI_H

#include <QDialog>

namespace Ui {
class consolegui;
}

class consolegui : public QDialog
{
    Q_OBJECT

public:
    explicit consolegui(QWidget *parent = 0);
    ~consolegui();

private:
    Ui::consolegui *ui;
};

#endif // CONSOLEGUI_H
