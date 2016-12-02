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

void ScientistService::removeScientist (string nameOf)
{
    _access.removeScientistlist(nameOf);
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
    command = makeFirstLetterBig(command);
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

/*
 * A function that validates if the name which the user asks to input is valid.
 * @param: string name of the scientist.
 * @return: true/false.
 */
bool ScientistService::validName(string name)
{
    bool valid = false;
    for(unsigned int i = 0; i < name.size(); i++)
    {

        if(isalpha(name.at(i)))
        {
            valid = true;
        }


    }
    return valid;
}


/*
 * A function to validate if the input sex from the users is valid.
 * @param: string containing scientists gender.
 * @return: true/false.
 */
bool ScientistService::validSex(string sex)
{
    if(sex == "female" || sex == "Female" || sex == "f" || sex == "F" || sex == "male" || sex == "Male" || sex == "m" || sex == "M")
    {
        return true;
    }
    else return false;
}

/*
 * A function to check if the year which the user inputs into the program is valid.
 * @param: string contianing year.
 * @return: true/false.
 */
bool ScientistService::validYear(string strYear)
{
    int year = atoi(strYear.c_str());
    for(unsigned int i = 0; i < strYear.size(); i++)
        {
            if(!(isdigit(strYear.at(i))) || year > 2016)
            {
                return false;
            }

        }
    return true;
}

/*
 * A function which validates the death of the scientist when the user inputs it
 * into the program.
 * @param: int birth year.
 * @param: string death year.
 * @return: true/false.
 */
bool ScientistService::validDeath(int birth, string strDeath)
{
    int death;
    death = atoi(strDeath.c_str());
    if(birth > death)
    {
        return false;
    }
    else return true;
}


/*
 * A function which returns the length of the longest name in the database.
 * @param: vector of Scientist variables.
 * @return: int variable.
 */
int ScientistService::lengthOfLongestName(vector<Scientist> scientists)
{
    Scientist temp;
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        if(temp.getName().size() < scientists[i].getName().size())
        {
            temp = scientists[i];
        }
    }
    return temp.getName().size();
}

/*
 * A function which returns the length of the longest citation the database.
 * @param: A vector of Scientists.
 * @return: int variable.
 */
int ScientistService::lengthOfLongestCitation(vector<Scientist> scientists)
{
    Scientist temp;
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        if(temp.getName().size() < scientists[i].getCitation().size())
        {
            temp = scientists[i];
        }
    }
    return temp.getCitation().size();
}

/*
 * A function which allows the user to input various form of inputs to
 * make it easier to input the scientists gender.
 * @param: string containing the users input.
 * @return: string sex (changed to the correct format).
 */
string ScientistService::MorF(string sex)
{
    if(sex == "female" || sex == "f" || sex == "F")
    {
        sex = "Female";
    }
    if(sex == "male" || sex == "m" || sex == "M")
    {
        sex = "Male";
    }
    return sex;
}

/*
 * A function to make the first letter of all names a capital letter.
 * @param: string name(input from user).
 * @return: string Scientist name.
 */
string ScientistService::makeFirstLetterBig(string name)
{
    if(name[0] >= 97)
    {
        name[0] -= 32;
    }
    for(unsigned int i = 0; i < name.size(); i++)
    {
        if(name[i] == 32 && name[i+1] >= 97)
        {
            name[i+1] -= 32;
        }
    }
    return name;
}

bool ScientistService::validCommand(string command)
{
    if(command == "1" || command == "2" || command == "3" || command == "4" || command == "name" || command == "Name" || command == "sex" || command == "Sex" || command == "birth" || command == "Birth" || command == "death" || command == "Death")
        return true;
    else return false;
}
