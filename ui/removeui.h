#ifndef REMOVEUI_H
#define REMOVEUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/listui.h"

#include "ui/utilityui.h"

/**
 * @brief The RemoveUI class
 */
class RemoveUI
{
public:
    /**
     * @brief RemoveUI
     */
    RemoveUI();

    /**
     * @brief removeSci/EverySci/Comp/EveryComp/Relation,
     */
    void removeSci();
    void removeEverySci();
    void removeComp();
    void removeEveryComp();
    void removeRelation();

private:
    UtilityUI _util;
    ListUI _list;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};

#endif // REMOVEUI_H
