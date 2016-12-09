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

    /**
     * @brief readToDatabase
     * @param computer
     */
    void readToDatabase(Computer computer);
    vector<Computer> readFromDatabase();

    /**
     * @brief removelist
     * @param int nameOf
     */
    void removelist(int nameOf);
    void removeAll();

    /**
     * @brief editString
     * @param nameOf
     * @param variable
     * @param newElement
     */
    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);

    /**
     * @brief updateRelation
     * @param int nameOf
     */
    void updateRelation(int nameOf);
    void updateRelationall();

    /**
     * @brief sortQuery
     * @param var
     * @param command
     * @return
     */
    vector<Computer> sortQuery(string var, string command);

    /**
     * @brief searchQueryString
     * @param variable
     * @param command
     * @return
     */
    vector<Computer> searchQueryString(string variable,string command);
    vector<Computer> searchQueryInt(string variable, string operatorOf, int command);

    /**
     * @brief connect
     */
    void connect();

private:

    /**
     * @brief fileWork
     * @param computer
     */
    void fileWork(Computer computer);

    /**
     * @brief edit
     * @param int id
     * @param string command
     */
    void edit(int id, string command);

    /**
     * @brief checkEntry
     * @param Computer computer
     * @return
     */
    bool checkEntry(Computer computer);

    /**
     * @brief m_db
     */
    QSqlDatabase m_db;
    vector<Computer> theList;
    int _temp;
};

#endif // COMPUTERACCESS_H
