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

private:
    vector<Scientist> listOfScientist;
};

#endif // PERFORMERSERVICE_H
