#include "scientistservice.h"
#include "dataaccess.h"
#include <vector>
#include <algorithm>

using namespace std;

ScientistService::ScientistService()
{

}
struct ScientistCompareName
{
    bool operator() (Scientist i,Scientist j) { return (i.getName()<j.getName());}
};
struct ScientistCompareSex
{
    bool operator() (Scientist i,Scientist j) { return (i.getSex()<j.getSex());}
};
struct ScientistCompareBirth
{
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()<j.getBirth());}
};
struct ScientistCompareDeath
{
    bool operator() (Scientist i,Scientist j) { return (i.getDeath()<j.getDeath());}
};

vector <Scientist> ScientistService::getScientist()
{
    DataAccess access;
    listOfScientist = access.readFromFile();
    return listOfScientist;
}

void ScientistService::addScientist(Scientist newScientist)
{
    DataAccess access;
    access.readToFile(newScientist);
}
vector<Scientist> ScientistService :: sortByName()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareName cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService :: sortBySex()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareSex cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService :: sortByBirth()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareBirth cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService :: sortByDeath()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareDeath cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}
/*
void ScientistService::addToVector(string word)
{
    listOfScientist.push_back(word.str());
}
*/

