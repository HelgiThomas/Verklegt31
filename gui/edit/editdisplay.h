#ifndef EDITDISPLAY_H
#define EDITDISPLAY_H

#include <QWidget>

namespace Ui {
class editdisplay;
}

class editdisplay : public QWidget
{
    Q_OBJECT

public:
    explicit editdisplay(QWidget *parent = 0);
    ~editdisplay();

private:
    Ui::editdisplay *ui;
};

#endif // EDITDISPLAY_H
