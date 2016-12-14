#ifndef REMOVERELATION_H
#define REMOVERELATION_H

#include <QWidget>

namespace Ui {
class removeRelation;
}

class removeRelation : public QWidget
{
    Q_OBJECT

public:
    explicit removeRelation(QWidget *parent = 0);
    ~removeRelation();

private:
    Ui::removeRelation *ui;
};

#endif // REMOVERELATION_H
