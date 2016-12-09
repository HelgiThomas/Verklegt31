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
 * @brief The ComputerAccess class, handles operations within the data layer
 * related to computers.
 */
class ComputerAccess
{
public:
    /**
     * @brief ComputerAccess, default constructor.
     */
    ComputerAccess();

    /**
     * @brief readToDatabase, readFromDatabase, functions to read into and write out of the SQL database.
     * @param computer
     */
    void readToDatabase(Computer computer);
    vector<Computer> readFromDatabase();

    /**
     * @brief removelist/All, removes a single computer or all of the computers.
     * @param int nameOf
     */
    void removelist(int nameOf);
    void removeAll();

    /**
     * @brief editString/Int, edits a field within the Computer model.
     * @param string nameOf
     * @param string variable
     * @param string/int newElement, two function - one for int and one for string.
     */
    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);

    /**
     * @brief updateRelation/all, updates the relation to computers/s.
     * @param int nameOf
     */
    void updateRelation(int nameOf);
    void updateRelationall();

    /**
     * @brief sortQuery/String/Int, pulls out of the database the list of computers sorted by the appropriate variable.
     * @param string var
     * @param string command
     * @return vector of computers sorted
     */
    vector<Computer> sortQuery(string var, string command);
    vector<Computer> searchQueryString(string variable,string command);
    vector<Computer> searchQueryInt(string variable, string operatorOf, int command);

    /**
     * @brief connect, connects the SQL database.
     */
    void connect();

private:

    /**
     * @brief fileWork, helper function that writes into the file.
     * @param Computer computer
     */
    void fileWork(Computer computer);

    /**
     * @brief edit, helper function for the edit functionality.
     * @param int id
     * @param string command
     */
    void edit(int id, string command);

    /**
     * @brief checkEntry, checks whether the entry already exists.
     * @param Computer computer
     * @return
     */
    bool checkEntry(Computer computer);

    QSqlDatabase m_db;
    vector<Computer> theList;
    int _temp;
};

#endif // COMPUTERACCESS_H
