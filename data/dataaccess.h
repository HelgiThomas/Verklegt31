#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "model/scientist.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class DataAccess
{
public:
    DataAccess();

    void readToFile(Scientist scientist);
    bool checkEntry (Scientist scientist);
    vector<Scientist> readFromFile();

private:
    vector<Scientist> theList;
    int _temp;

};

#endif // DATAACCESS_H
