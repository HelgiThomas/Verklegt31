#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "model/scientist.h"
#include "model/computer.h"
#include <iostream>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
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

    void connect ();

    /**
     * @brief Function to read information about scientists to the .txt file.
     * @param Scientists scientist
     */

    void readToFile(Scientist scientist);
    // need to comment
    void readToFileComputer(Computer computer);

    /**
     * @brief Function to remove a Scientist from the list of Scientists.
     * @param string name
     */
    void removeScientistlist(string name);

    void removeComputerlist(string nameOf);
    // Commenta helgi
    void removeEveryscienst ();
    //commenta helgi
    void removeEveryComputer ();

    /**
     * @brief Function to read information from the file into the program again.
     * @return vector<Scientists>
     */
    vector<Scientist> readFromFile();
    //need to comment
    vector<Computer> readFromFileComputer();



private:
    QSqlDatabase m_db;

    /**
     * @brief A helper function to write information into file, also provides
     * ways to differ between apple and windows computers.
     * @param scientist
     */
    void fileWork(Scientist scientist);

    // commenta helgi
    void editScientist (int id, string command);
    /**
     * @brief Functions to check if the entries are valid and correct.
     * @param Scientist scientist
     */
    bool checkEntry(Scientist scientist);

    vector<Scientist> theList;
    int _temp = 0;
};

#endif // DATAACCESS_H
