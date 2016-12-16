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
     * @brief editRelation/sci/comp,
     * @param int nrID
     * @param int sciID
     * @param int compID
     */
    void editRelation (int nrID, int sciID, int compID);
    void editSci(int changeID,int newSciID);
    void editComp(int changeID,int newCompID);

    /**
     * @brief getSciComps,
     * @param Sci
     */
    void getSciComps(string Sci);
    void getCompScis(string Comp);
    int getLinkId(int sciId, int compId);

    /**
     * @brief removeRelation
     * @param int nrID
     */
    void removeRelation (int nrID);

    /**
     * @brief connect, connects the SQL database.
     */
    void connect();
    void closeConn();
    /**
     * @brief checkEntry, checks entry of new relation
     * @param sciID
     * @param compID
     * @return  true or false
     */
    bool checkEntry(int scientistId, int computerId);

private:
    QSqlDatabase m_db;
};

#endif // LINKACCESS_H
