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
    bool validName(string name);
    bool validSex(string sex);
    bool validYear(string year);
    bool validDeath(int birth, string strDeath);
    bool isPersonAlive();
    int lengthOfLongestName(vector<Scientist> scientists);
    int lengthOfLongestCitation (vector<Scientist> scientists);
    string MorF(string sex);
    string makeFirstLetterBig(string name);

private:
    void displayListOfScientists(vector<Scientist> Scientist);
    void list();
    void addSci();
    void sortSci();
    void reversedSortSci();
    void searchList ();
    void validateSearch(vector<Scientist>names);

    ScientistService _service;
};

#endif // CONSOLEUI_H
