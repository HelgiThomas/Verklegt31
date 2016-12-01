#include "service/scientistservice.h"
#include "algorithm"


using namespace std;

ScientistService::ScientistService()
{

}

vector <Scientist> ScientistService::getScientist()
{

    listOfScientist = _access.readFromFile();
    return listOfScientist;
}

void ScientistService::addScientist(Scientist newScientist)
{
    _access.readToFile(newScientist);
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

struct ScientistCompareNameReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getName()>j.getName());}
};

struct ScientistCompareSexReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getSex()>j.getSex());}
};

struct ScientistCompareBirthReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()>j.getBirth());}
};

struct ScientistCompareDeathReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getDeath()>j.getDeath());}
};

vector<Scientist> ScientistService::sortByName()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareName cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortBySex()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareSex cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortByBirth()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareBirth cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortByDeath()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareDeath cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortByNameReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareNameReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortBySexReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareSexReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortByBirthReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareBirthReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

vector<Scientist> ScientistService::sortByDeathReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareDeathReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}
vector <Scientist> ScientistService::searchName (string command)
{
    vector<Scientist> allNames;
    vector<Scientist> allScientists = _access.readFromFile();
    for (unsigned int i = 0 ; i < allScientists.size();i++)
    {
        if ((command == allScientists[i].getName()))
        {
           allNames.push_back(allScientists[i]);
        }
    }
    return allNames;
}
vector <Scientist> ScientistService::searchSex (string command)
{
    vector<Scientist> allSex;
    vector<Scientist> allScientists = _access.readFromFile();
    for (unsigned int i = 0 ; i < allScientists.size();i++)
    {
        if ((command == allScientists[i].getSex()))
        {
           allSex.push_back(allScientists[i]);
        }
    }
    return allSex;
}
vector <Scientist> ScientistService::searchBirth (int command)
{
    vector<Scientist> allBirth;
    vector<Scientist> allScientists = _access.readFromFile();
    for (unsigned int i = 0 ; i < allScientists.size();i++)
    {
        if ((command) == (allScientists[i].getBirth()))
        {
           allBirth.push_back(allScientists[i]);
        }
    }
    return allBirth;
}
vector <Scientist> ScientistService::searchDeath (int command)
{
    vector<Scientist> allDeath;
    vector<Scientist> allScientists = _access.readFromFile();
    for (unsigned int i = 0 ; i < allScientists.size();i++)
    {
        if ((command) == (allScientists[i].getDeath()))
        {
           allDeath.push_back(allScientists[i]);
        }
    }
    return allDeath;
}
