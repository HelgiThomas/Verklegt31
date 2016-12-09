#ifndef GAMEUI_H
#define GAMEUI_H


#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

#include "ui/utilityui.h"

class GameUI
{
public:
    GameUI();

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
