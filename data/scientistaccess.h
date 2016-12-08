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

class ScientistAccess
{
public:

    ScientistAccess();

    void readToDatabase(Scientist scientist);
    vector<Scientist> readFromDatabase();


    void removelist(string name);
    void removeAll();

    void editString(string nameOf, string variable, string newElement);
    void editInt(string nameOf, string variable, int newElement);


    vector<Scientist> sortQuery(string var, string command);
    vector<Scientist> searchQueryString(string command);
    vector<Scientist> searchQueryInt(int command);


    void connect();

private:

    void fileWork(Scientist scientist);

    //kommenta helgi
    void queryShortcut ();


    void edit(int id, string command);


    bool checkEntry(Scientist scientist);

    QSqlDatabase m_db;
    vector<Scientist> theList;
    int _temp;
};

#endif // SCIENTISTACCESS_H
