#ifndef SORTUI_H
#define SORTUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"

#include "ui/utilityui.h"

class SortUI
{
public:
    SortUI();

    void sortSci();
    void sortComp();

    void reversedSortSci();
    void reversedSortComp();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
};

#endif // SORTUI_H
