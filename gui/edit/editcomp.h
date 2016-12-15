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
    ~editcompgui();

    void setId(int id);
    void setText();

private slots:
    void on_radioButton_name_clicked();

    void on_radioButton_type_clicked();

    void on_radioButton_wasBuilt_clicked();

    void on_radioButton_year_clicked();

    void on_radioButton_4_clicked();
    void on_pushButton_editComp_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::editcompgui *ui;

    Computer _comp;
    int _ID;
};

#endif // EDITCOMPGUI_H
