#ifndef SCIENTISTACCESS_H
#define SCIENTISTACCESS_H

#include "model/scientist.h"
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
 * @brief The ScientistAccess class
 */
class ScientistAccess
{
public:
    /**
     * @brief ScientistAccess, default constructor.
     */
    ScientistAccess();

    void readToFile(Scientist scientist);


    void removeScientistlist(string name);


    void removeEveryscienst ();


    vector<Scientist> readFromFile();

private:
    QSqlDatabase m_db;
    Utility util;

    void fileWork(Scientist scientist);


    void editScientist (int id, string command);


    bool checkEntry(Scientist scientist);

    vector<Scientist> theList;
    int _temp = 0;
};

#endif // SCIENTISTACCESS_H
