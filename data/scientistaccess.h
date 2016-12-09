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
 * @brief The ScientistAccess class, handles operations within the data layer
 * related to Scientists.
 */
class ScientistAccess
{
public:
    /**
     * @brief ScientistAccess, default constructor.
     */
    ScientistAccess();

    /**
     * @brief readToDatabase, readFromDatabase, functions to read into and write out of the SQL database.
     * @param scientist
     */
    void readToDatabase(Scientist scientist);
    vector<Scientist> readFromDatabase();

    /**
     * @brief removelist/All, removes a single computer or all of the scientists.
     * @param int nameOf
     */
    void removelist(int nameOf);
    void removeAll();

    /**
     * @brief editString/Int, edits a field within the Scientist model.
     * @param string nameOf
     * @param string variable
     * @param string/int newElement, two function - one for int and one for string.
     */
    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);

    /**
     * @brief updateRelation/all, updates the relation to scientist/s.
     * @param int nameOf
     */
    void updateRelation(int nameOf);
    void updateRelationall();

    /**
     * @brief sortQuery/String/Int, pulls out of the database the list of scientists sorted by the appropriate variable.
     * @param string var
     * @param string command
     * @return vector of scientists sorted
     */
    vector<Scientist> sortQuery(string var, string command);
    vector<Scientist> searchQueryString(string variable,string command);
    vector<Scientist> searchQueryInt(string variable, string operatorOf, int command);

    /**
     * @brief connect, connects the SQL database.
     */
    void connect();

private:

    /**
     * @brief fileWork, helper function that writes into the file.
     * @param scientist
     */
    void fileWork(Scientist scientist);

    /**
     * @brief queryShortcut, for pull out of the database.
     */
    void queryShortcut ();

    /**
     * @brief edit, helper function for the edit functionality.
     * @param int id
     * @param string command
     */
    void edit(int id, string command);

    /**
     * @brief checkEntry, checks whether the entry already exists.
     * @param Scientist scientist
     * @return
     */
    bool checkEntry(Scientist scientist);

    QSqlDatabase m_db;
    vector<Scientist> theList;
    int _temp;
};

#endif // SCIENTISTACCESS_H
