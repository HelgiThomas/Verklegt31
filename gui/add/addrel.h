#ifndef ADDREL_H
#define ADDREL_H

#include <QDialog>

namespace Ui {
class addrel;
}

class addrel : public QDialog
{
    Q_OBJECT

public:
    explicit addrel(QWidget *parent = 0);
    ~addrel();

private:
    Ui::addrel *ui;
};

#endif // ADDREL_H
