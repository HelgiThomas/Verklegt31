#ifndef GAMEGUI_H
#define GAMEGUI_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

namespace Ui {
class gamegui;
}

class gamegui : public QDialog
{
    Q_OBJECT

public:
    explicit gamegui(QWidget *parent = 0);
    ~gamegui();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::gamegui *ui;
};

#endif // GAMEGUI_H
