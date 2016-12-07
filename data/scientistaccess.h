#ifndef SCIENTISTACCESS_H
#define SCIENTISTACCESS_H

#include "model/scientist.h"
#include "misc/utility.h"

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

class ScientistAccess
{
public:

    ScientistAccess();


    void readToDatabase(Scientist scientist);


    void removelist(string name);


    void removeAll();


    vector<Scientist> readFromDatabase();

private:

    void fileWork(Scientist scientist);


    void edit(int id, string command);


    bool checkEntry(Scientist scientist);

    QSqlDatabase m_db;
    Utility _util;
    vector<Scientist> theList;
    int _temp;
};

#endif // SCIENTISTACCESS_H
