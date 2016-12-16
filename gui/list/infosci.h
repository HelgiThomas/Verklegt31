#ifndef INFOSCI_H
#define INFOSCI_H

#include <QDialog>
#include "service/scientistservice.h"
#include "model/scientist.h"

namespace Ui {
class infosci;
}

class infosci : public QDialog
{
    Q_OBJECT

public:
    explicit infosci(QWidget *parent = 0);
    ~infosci();

private:
    Ui::infosci *ui;
    ScientistService _sciService;
    Scientist _sci;

};

#endif // INFOSCI_H
