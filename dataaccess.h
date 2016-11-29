#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "scientist.h"
#include <vector>
#include <string>

class DataAccess
{
public:
    DataAccess();

    bool readToFile(Scientist scientist);
    vector<Scientist> readFromFile();

private:
    vector<Scientist> theList;

    vector<string> splitLine(string line);
    int convertStringToInt(string s);
};

#endif // DATAACCESS_H
