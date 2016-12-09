#ifndef LINKACCESS_H
#define LINKACCESS_H

#include "model/computer.h"
#include "model/scientist.h"

#include <QSql>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief The LinkAccess class, handles operations within the data layer
 * related to links between Scientists and Computer.
 */
class LinkAccess
{
public:
    /**
     * @brief LinkAccess, default constructor.
     */
    LinkAccess();

    /**
     * @brief This function will link the scientistID and computerID
     * @param int scientistId
     * @param int computerId
     */
    void link(int scientistId, int computerId);

    /**
     * @brief ScientistId
     * @return vector of ints containing Ids,
     */
    vector<int> ScientistId ();
    vector<int> ComputerId ();
    vector<int> RelationId ();

    /**
     * @brief editRelation
     * @param int nrID
     * @param int sciID
     * @param int compID
     */
    void editRelation (int nrID, int sciID, int compID);

    /**
     * @brief removeRelation
     * @param int nrID
     */
    void removeRelation (int nrID);

    /**
     * @brief connect, connects the SQL database.
     */
    void connect();

private:
    QSqlDatabase m_db;
};

#endif // LINKACCESS_H
