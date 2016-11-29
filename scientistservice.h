#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include "scientist.h"
#include "dataaccess.h"
#include <vector>

using namespace std;

class ScientistService
{
public:
    ScientistService();

    vector<Scientist> getScientist();
    void addScientist(const Scientist newScientist);

private:
    vector<Scientist> listOfScientist;
    DataAccess access;
};

#endif // PERFORMERSERVICE_H
