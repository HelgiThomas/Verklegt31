#ifndef ADDUI_H
#define ADDUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

class AddUI
{
public:
    AddUI();

    void addSci();
    void addComp();
    void addRelation();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // ADDUI_H
