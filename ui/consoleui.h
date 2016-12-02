#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "service/scientistservice.h"

/*
 *
 */
class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
    void clearScreen();
    bool isPersonAlive();

private:
    void displayListOfScientists(vector<Scientist> Scientist);
    void list();
    void addSci();
    void sortSci();
    void reversedSortSci();
    void searchList ();
    void validateSearch(vector<Scientist>names);
    bool askIfCitation();
    void removeSci ();

    ScientistService _service;
};


#endif // CONSOLEUI_H
