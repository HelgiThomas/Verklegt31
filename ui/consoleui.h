#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/addui.h"
#include "ui/editui.h"
#include "ui/listui.h"
#include "ui/removeui.h"
#include "ui/searchui.h"
#include "ui/sortui.h"
#include "ui/gameui.h"
#include "ui/utilityui.h"

/**
 * @brief ConsoleUI class, handles the interface/menu for the program.
 */
class ConsoleUI
{
public:
    /**
     * @brief Default constructor for the class.
     */
    ConsoleUI();

    /**
     * @brief First function which calls the various other menu functions.
     */
    void run();

private:
    void consoleAdd();
    void consoleRemove();
    void consoleList();
    void consoleEdit();
    void consoleSort();
    void consoleRevSort();
    void consoleSearch();
    void consoleGame();

    AddUI _add;
    EditUI _edit;
    ListUI _list;
    RemoveUI _remove;
    SearchUI _search;
    SortUI _sort;
    UtilityUI _util;
    GameUI _game;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;
};


#endif // CONSOLEUI_H

