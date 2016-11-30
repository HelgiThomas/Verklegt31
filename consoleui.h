#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run ();
    void clearScreen();
    bool validName(string name);
    bool validSex(string sex);
    bool validYear(string year);
    bool validDeath(int birth, string strDeath);
    int lengthOfLongestName(vector<Scientist> scientists);

private:
    void displayListOfScientists ();
    void list();
    void addSci();
    void sortSci();

    ScientistService _service;
};

#endif // CONSOLEUI_H
