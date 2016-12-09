#ifndef UTILITYUI_H
#define UTILITYUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"


class UtilityUI
{
public:
    UtilityUI();

    void clearScreen();

    void displayListOfScientists(vector<Scientist> Scientist);
    void displayListOfComputers(vector<Computer> Computer);

    void validateSearch(vector<Scientist>search);
    void validateSearch(vector<Computer> search);

    bool askIfCitation();
    bool askIfBuilt();

    bool isPersonAlive();

private:
    ScientistService _serviceSci;
    ComputerService _serviceComp;
};

#endif // UTILITYUI_H
