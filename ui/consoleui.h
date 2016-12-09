#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "service/scientistservice.h"
#include "service/computerservice.h"
#include "service/generalservice.h"

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
    /**
     * @brief Function to call the system commands to clear the screen.
     * Works for both windows and apple computer.
     */
    void clearScreen();

private:
    /**
     * @brief These are the various other menu functions which the user can on
     * to do the activities within the program.
     * @param vector<Scientist> Scientist
     */
    void displayListOfScientists(vector<Scientist> Scientist);
    void displayListOfComputers(vector<Computer> Computer);
    void listSci();
    void listComp();
    void listRelation();
    void addSci();
    void addComp();
    void addRelation();
    void editSci ();
    void editComp ();
    void editRelation ();
    void sortSci();
    void sortComp();
    void reversedSortSci();
    void reversedSortComp();
    void searchScientistList();
    void searchComputerList ();
    void playGame();


    /**
     * @brief Function to see if the object you are searching for exists or not.
     * @param vector<Scientist> names
     */
    void validateSearch(vector<Scientist>search);
    void validateSearch(vector<Computer> search);

    /**
     * @brief Function which asks the user if he wants to add a citation or not.
     * @return true/false
     */
    bool askIfCitation();

    bool askIfBuilt();

    /**
     * @brief Function to remove a scientist from the list.
     */
    void removeSci();

    // ekki gleyma ad kommenta below helgi
    void removeEverySci();

    void removeComp();

    void removeRelation();

    void removerelation ();


    /**
     * @brief Function to check if the person is still alive.
     * Also validates if the input from the user is valid.
     * @return
     */
    bool isPersonAlive();

    ScientistService _serviceSci;
    ComputerService _serviceComp;
    GeneralService _serviceGen;

    int score;
};


#endif // CONSOLEUI_H

