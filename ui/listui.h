#ifndef LISTUI_H
#define LISTUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

class ListUI
{
public:
    ListUI();

    void listSci();
    void listComp();
    void listRelation();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

};

#endif // LISTUI_H
