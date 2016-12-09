#ifndef EDITUI_H
#define EDITUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"
#include "ui/listui.h"

class EditUI
{
public:
    EditUI();

    void editSci();
    void editComp();
    void editRelation();

private:
    UtilityUI _util;
    ListUI _list;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // EDITUI_H
