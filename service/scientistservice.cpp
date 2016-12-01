#include "service/scientistservice.h"
#include "algorithm"


using namespace std;

/*
 * This is the default constructor.
 */
ScientistService::ScientistService()
{

}

/*
 * This function returns the list of all the scientist in the .txt file.
 * @return: List of people that are in the file.
 */
vector <Scientist> ScientistService::getScientist()
{

    listOfScientist = _access.readFromFile();
    return listOfScientist;
}

/*
 * This function adds a new scientist to the .txt file.
 * @param: Scientist variable.
 */
void ScientistService::addScientist(Scientist newScientist)
{
    _access.readToFile(newScientist);
}

/*
 * Compares the name and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareName
{
    bool operator() (Scientist i,Scientist j) { return (i.getName()<j.getName());}
};

/*
 * Compares the sex and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareSex
{
    bool operator() (Scientist i,Scientist j) { return (i.getSex()<j.getSex());}
};

/*
 * Compares the birth years and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareBirth
{
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()<j.getBirth());}
};

/*
 * Compared the death years and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareDeath
{
    bool operator() (Scientist i,Scientist j) { return (i.getDeath()<j.getDeath());}
};

/*
 * Compares the name and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareNameReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getName()>j.getName());}
};

/*
 * Compares the sex and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareSexReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getSex()>j.getSex());}
};

/*
 * Comapares the birth years and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false
 */
struct ScientistCompareBirthReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getBirth()>j.getBirth());}
};

/*
 * Compares the death years and returns true if the first parameter is higher.
 * @param: Scientist variable.
 * @param: Scientist variable.
 * @return: true/false.
 */
struct ScientistCompareDeathReverse
{
    bool operator() (Scientist i,Scientist j) { return (i.getDeath()>j.getDeath());}
};

/*
 * This function sorts the names in the scientist vector in alphabetical order.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByName()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareName cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the sex in the scientist vector in alphabetical order.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortBySex()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareSex cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the birth years in the scientist vector by the oldest scientist.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByBirth()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareBirth cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the death years in the scientist vector
 * by the scientist that died first.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByDeath()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareDeath cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the names in the scientist vector in reverse alphabetical order.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByNameReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareNameReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the sex in the scientist vector in reverse alphabetical order.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortBySexReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareSexReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the birth years in the scientist vector by the youngest scientist.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByBirthReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareBirthReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function sorts the death years in the scientist vector
 * by the scientist that died last.
 * @return: vector<Scientist>.
 */
vector<Scientist> ScientistService::sortByDeathReverse()
{
    vector<Scientist> scientists = getScientist();

    ScientistCompareDeathReverse cmp;
    std::sort(scientists.begin(), scientists.end(), cmp);

    return scientists;
}

/*
 * This function searches the input, and finds a match in the .txt file
 * if it exists.
 * @param: string input.
 * @return: vector<Scientist>.
 */
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

/*
 * This function searches the input, and finds a match in the .txt file
 * if it exists.
 * @param: string input.
 * @return: vector<Scientist>.
 */
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

/*
 * This function searches the input, and finds a match in the .txt file
 * if it exists.
 * @param: string input.
 * @return: vector<Scientist>.
 */
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

/*
 * This function searches the input, and finds a match in the .txt file
 * if it exists.
 * @param: string input.
 * @return: vector<Scientist>.
 */
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
