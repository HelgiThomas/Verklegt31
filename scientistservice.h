#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include "scientist.h"
#include <vector>

using namespace std;

class ScientistService
{
public:
    ScientistService();

    vector<Scientist> getScientist();
    void addScientist(Scientist newScientist);
    void addToVector (string word);
    vector<Scientist> sortByName();
    vector<Scientist> sortBySex();
    vector<Scientist> sortByBirth();
    vector<Scientist> sortByDeath();

private:
    vector<Scientist> listOfScientist;
};

#endif // PERFORMERSERVICE_H
