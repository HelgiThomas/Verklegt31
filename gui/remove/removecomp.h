#ifndef REMOVECOMP_H
#define REMOVECOMP_H

#include "service/computerservice.h"

#include <QDialog>

namespace Ui {
class removecomp;
}

class removecomp : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief removecomp
     * @param parent
     */
    explicit removecomp(QWidget *parent = 0);
    ~removecomp();
    /**
     * @brief setId
     * @param id
     */
    void setId(int id);
    void setName(string name);
    void setType(string type);
    void setWasBuilt(string wasBuilt);
    void setYear(int year);
    /**
     * @brief displayComputers
     */
    void displayComputers();

private slots:
    /**
     * @brief on_button_removeComp_clicked
     */
    void on_button_removeComp_clicked();
    void on_pushButton_clicked();

private:
    Ui::removecomp *ui;
    ComputerService _serviceComp;

    int _id;
    string _name;
    string _type;
    string _wasBuilt;
    int _year;
};

#endif // REMOVECOMP_H
