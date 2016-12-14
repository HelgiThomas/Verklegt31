#ifndef EDITSCIGUI_H
#define EDITSCIGUI_H

#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QMessageBox>
#include <QTextStream>
#include <string>

#include "model/scientist.h"
#include "service/scientistservice.h"


namespace Ui {
class editscigui;
}

class editscigui : public QWidget
{
    Q_OBJECT

public:
    explicit editscigui(QWidget *parent = 0);
    explicit editscigui(Scientist sci, QWidget *parent = 0);
    ~editscigui();

    void setText();
    void init();
    string chooseSex();

private slots:
    void on_radioButton_name_clicked();

    void on_radioButton_sex_clicked();

    void on_radioButton_birth_clicked();

    void on_radioButton_death_clicked();

    void on_pushButton_editSci_clicked();

    void on_combobox_birthYears_currentIndexChanged(int index);

    void on_combobox_deathYear_currentIndexChanged(int index);

private:
    Ui::editscigui *ui;

    ScientistService _sciService;

    Scientist _sci;
    int _sciBirth;
    int _sciDeath;
};

#endif // EDITSCIGUI_H
