#ifndef LISTUI_H
#define LISTUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

/**
 * @brief The ListUI class,
 */
class ListUI
{
public:
    /**
     * @brief ListUI,
     */
    ListUI();

    /**
     * @brief listSci/Comp/Relation,
     */
    void listSci();
    void listComp();

    void listAllRelations();
    void listCompRelation();
    void listSciRelation();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

};

#endif // LISTUI_H
