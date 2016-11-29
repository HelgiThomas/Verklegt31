#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "scientistservice.h"
#include <iostream>

class DataAccess
{
public:
    DataAccess();

    void readToFile(vector<Scientist> scientist);
    vector<Scientist> readFromFile();

private:
    vector<Scientist> theList;
};

#endif // DATAACCESS_H
