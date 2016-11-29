#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "scientistservice.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class DataAccess
{
public:
    DataAccess();

    void readToFile(Scientist scientist);
    vector<Scientist> readFromFile();

private:
    vector<Scientist> theList;

    vector<Scientist> splitLine(string line);
};

#endif // DATAACCESS_H
