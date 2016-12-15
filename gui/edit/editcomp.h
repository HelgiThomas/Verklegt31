#ifndef EDITCOMPGUI_H
#define EDITCOMPGUI_H

#include <QDialog>

#include "model/computer.h"

namespace Ui {
class editcompgui;
}

class editcompgui : public QDialog
{
    Q_OBJECT

public:
    explicit editcompgui(QWidget *parent = 0);
    ~editcompgui();

    void setId(int id);
    void setName(string name);
    void setType(string type);
    void setWasBuilt(string wasBuilt);
    void setYear(int year);

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

    int _id;
    string _name;
    string _type;
    string _wasBuilt;
    int _year;
};

#endif // EDITCOMPGUI_H
