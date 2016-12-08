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
    vector<Computer> readFromDatabase();


    void removelist(string nameOf);
    void removeAll();

    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);


    vector<Computer> sortQuery(string var, string command);
    vector<Computer> searchQueryString(string variable,string command);
    vector<Computer> searchQueryInt(string variable, string operatorOf, int command);


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
