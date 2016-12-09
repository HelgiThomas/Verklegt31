#ifndef SORTUI_H
#define SORTUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"

#include "ui/utilityui.h"

/**
 * @brief The SortUI class,
 */
class SortUI
{
public:
    /**
     * @brief SortUI,
     */
    SortUI();

    /**
     * @brief sortSci/Comp,
     */
    void sortSci();
    void sortComp();

    /**
     * @brief reversedSortSci/Comp,
     */
    void reversedSortSci();
    void reversedSortComp();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
};

#endif // SORTUI_H
