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
    void addScientist(Scientist newScientist);
    vector<Scientist> sortByName();
    vector<Scientist> sortBySex();
    vector<Scientist> sortByBirth();
    vector<Scientist> sortByDeath();
    vector<Scientist> sortByNameReverse();
    vector<Scientist> sortBySexReverse();
    vector<Scientist> sortByBirthReverse();
    vector<Scientist> sortByDeathReverse();

private:
    vector<Scientist> listOfScientist;
    DataAccess _access;
};

#endif // PERFORMERSERVICE_H
