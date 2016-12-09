#ifndef SEARCHUI_H
#define SEARCHUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

/**
 * @brief The SearchUI class.
 */
class SearchUI
{
public:
    /**
     * @brief SearchUI.
     */
    SearchUI();

    /**
     * @brief searchScientistList/Computer.
     */
    void searchScientistList();
    void searchComputerList ();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // SEARCHUI_H
