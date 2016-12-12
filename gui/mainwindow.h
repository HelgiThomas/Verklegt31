#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"


namespace Ui {
class mainwindow;
}

class mainwindow : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = 0);
    ~mainwindow();

private:
    Ui::mainwindow *ui;
    //addgui _add;

};

#endif // MAINWINDOW_H
