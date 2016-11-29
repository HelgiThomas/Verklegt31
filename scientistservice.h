#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include "dataaccess.h"
#include <vector>

using namespace std;

class ScientistService
{
public:
    ScientistService();

    vector<Scientist> getScientist();
    bool addScientist(Scientist newScientist);
    vector<Scientist> sortByName();
    vector<Scientist> sortBySex();
    vector<Scientist> sortByBirth();
    vector<Scientist> sortByDeath();

private:
    DataAccess data;
};

#endif // PERFORMERSERVICE_H
