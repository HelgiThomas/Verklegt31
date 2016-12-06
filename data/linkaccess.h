#ifndef LINKACCESS_H
#define LINKACCESS_H

#include "model/computer.h"
#include "model/scientist.h"
#include "misc/utility.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LinkAccess
{
public:
    LinkAccess();

    bool link(int scientistId, int computerId);

private:
    QSqlDatabase m_db;
    Utility util;
};

#endif // LINKACCESS_H
