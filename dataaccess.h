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

    vector<string> splitLine(string line);
    int convertStringToInt(string s);
};

#endif // DATAACCESS_H
