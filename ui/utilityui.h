#ifndef UTILITYUI_H
#define UTILITYUI_H

#include "service/scientistservice.h"
#include "service/computerservice.h"

/**
 * @brief The UtilityUI class
 */
class UtilityUI
{
public:
    /**
     * @brief UtilityUI
     */
    UtilityUI();

    /**
     * @brief clearScreen
     */
    void clearScreen();

    /**
     * @brief displayListOfScientists/Computers
     * @param vector Scientist/Computer
     */
    void displayListOfScientists(vector<Scientist> Scientist);
    void displayListOfComputers(vector<Computer> Computer);

    /**
     * @brief validateSearch
     * @param vector Scientists/Computer
     */
    void validateSearch(vector<Scientist>search);
    void validateSearch(vector<Computer> search);

    /**
     * @brief askIfCitation/Built
     * @return
     */
    bool askIfCitation();
    bool askIfBuilt();

    /**
     * @brief isPersonAlive,
     * @return
     */
    bool isPersonAlive();

private:
    ScientistService _serviceSci;
    ComputerService _serviceComp;
};

#endif // UTILITYUI_H
