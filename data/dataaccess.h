#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "model/scientist.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief The DataAccess class, used to write to files and read from files (Data Layer).
 */
class DataAccess
{
public:
    /**
     * @brief Default constructor for the DataAccess class.
     */
    DataAccess();

    /**
     * @brief Function to read information about scientists to the file ComputerScientist.txt
     * @param Scientists scientist
     */
    void readToFile(Scientist scientist);

    /**
     * @brief Function to read information from the file into the program again.
     * @return vector<Scientists>
     */
    vector<Scientist> readFromFile();

    /**
     * @brief Funciton to remove a Scientist from the list of Scientists.
     * @param String name
     */
    void removeScientistlist(string name);

private:
    /**
     * @brief A helper function to write information into file, also provides
     * ways to differ between apple and windows computers.
     * @param scientist
     */
    void fileWork(Scientist scientist);

    /**
     * @brief functions to check if the entries are valid and correct.
     * @param Scientist scientist
     */
    void firstEntry(Scientist scientist);
    void secondEntry(Scientist scientist);
    bool checkEntry(Scientist scientist);

    vector<Scientist> theList;
    int _temp = 0;
};

#endif // DATAACCESS_H
