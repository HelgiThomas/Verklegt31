#ifndef COMPUTERACCESS_H
#define COMPUTERACCESS_H

#include "model/computer.h"
#include "misc/utility.h"

#include <iostream>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief The ComputerAccess class, handles everything
 * related to computers and the database.
 */
class ComputerAccess
{
public:
    /**
     * @brief ComputerAccess, default constructor.
     */
    ComputerAccess();

    void readToFile(Computer computer);


    void removeComputerlist(string nameOf);


    void removeEveryComputer();


    vector<Computer> readFromFile();

private:
    QSqlDatabase m_db;
    Utility util;

    void fileWork(Computer computer);


    void editComputer(int id, string command);


    bool checkEntry(Computer computer);

    vector<Computer> theList;
    int _temp = 0;
};

#endif // COMPUTERACCESS_H
