#ifndef GAMEUI_H
#define GAMEUI_H


#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

/**
 * @brief The GameUI class,
 */
class GameUI
{
public:
    /**
     * @brief GameUI,
     */
    GameUI();

    /**
     * @brief playCitation/Relation,
     */
    void playCitation();
    void playRelation();

private:
    UtilityUI _util;

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

    int score;
};

#endif // GAMEUI_H
