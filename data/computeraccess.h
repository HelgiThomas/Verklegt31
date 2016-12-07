#ifndef COMPUTERACCESS_H
#define COMPUTERACCESS_H

#include "model/computer.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>

#include <iostream>
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

    void readToDatabase(Computer computer);


    void removelist(string nameOf);


    void removeAll();


    vector<Computer> readFromDatabase();
    vector<Computer> sortQuery(string var, string command);

    void connect();

private:

    void fileWork(Computer computer);


    void edit(int id, string command);


    bool checkEntry(Computer computer);

    QSqlDatabase m_db;
    vector<Computer> theList;
    int _temp;
};

#endif // COMPUTERACCESS_H
