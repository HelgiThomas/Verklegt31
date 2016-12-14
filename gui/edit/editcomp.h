#ifndef EDITCOMPGUI_H
#define EDITCOMPGUI_H

#include <QWidget>

#include "model/computer.h"

namespace Ui {
class editcompgui;
}

class editcompgui : public QWidget
{
    Q_OBJECT

public:
    explicit editcompgui(QWidget *parent = 0);
    explicit editcompgui(Computer comp, QWidget *parent = 0);
    ~editcompgui();


    void setText();
    void init();

private slots:
    void on_radioButton_name_clicked();

    void on_radioButton_type_clicked();

    void on_radioButton_wasBuilt_clicked();

    void on_radioButton_year_clicked();

    void on_radioButton_4_clicked();
    void on_pushButton_editComp_clicked();

private:
    Ui::editcompgui *ui;

    Computer _comp;
};

#endif // EDITCOMPGUI_H
