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

class LinkAccess
{
public:
    LinkAccess();

    void link(int scientistId, int computerId);

    vector<int> ScientistId ();
    vector<int> ComputerId ();
    vector<int> RelationId ();

    void editRelation (int nrID, int SciID, int CompID);

    void removeRelation (int nrID);

    void connect();

private:
    QSqlDatabase m_db;
};

#endif // LINKACCESS_H
