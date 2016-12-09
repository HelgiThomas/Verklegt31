#ifndef SCIENTISTACCESS_H
#define SCIENTISTACCESS_H

#include "model/scientist.h"

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
 * @brief The ScientistAccess class.
 */
class ScientistAccess
{
public:
    /**
     * @brief ScientistAccess, default constructor.
     */
    ScientistAccess();

    /**
     * @brief readToDatabase
     * @param scientist
     */
    void readToDatabase(Scientist scientist);
    vector<Scientist> readFromDatabase();

    /**
     * @brief removelist
     * @param nameOf
     */
    void removelist(int nameOf);
    void removeAll();

    /**
     * @brief editString
     * @param string nameOf
     * @param string variable
     * @param string/int newElement, two function - one for int and one for string.
     */
    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);

    /**
     * @brief sortQuery
     * @param string var
     * @param string command
     * @param
     */
    vector<Scientist> sortQuery(string var, string command);
    vector<Scientist> searchQueryString(string variable,string command);
    vector<Scientist> searchQueryInt(string variable, string operatorOf, int command);

    /**
     * @brief updateRelation
     * @param int nameOf
     */
    void updateRelation (int nameOf);
    void updateRelationall();

    /**
     * @brief connect
     */
    void connect();

private:

    /**
     * @brief fileWork
     * @param scientist
     */
    void fileWork(Scientist scientist);

    /**
     * @brief queryShortcut
     */
    void queryShortcut ();

    /**
     * @brief edit
     * @param id
     * @param command
     */
    void edit(int id, string command);

    /**
     * @brief checkEntry
     * @param scientist
     * @return
     */
    bool checkEntry(Scientist scientist);

    /**
     * @brief m_db
     */
    QSqlDatabase m_db;
    vector<Scientist> theList;
    int _temp;
};

#endif // SCIENTISTACCESS_H
