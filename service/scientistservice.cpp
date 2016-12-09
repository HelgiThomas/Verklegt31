#include "service/scientistservice.h"
#include "algorithm"

using namespace std;

/**
 * @brief This is the default constructor.
 */
ScientistService::ScientistService()
{

}

/**
 * @brief This function returns the list of all the scientists in the .txt file.
 * @return vector of scientists.
 */
vector <Scientist> ScientistService::getScientists()
{

    listOfScientist = _SciAccess.readFromDatabase();
    return listOfScientist;
}

/**
 * @brief This function adds a new scientist to the .txt file.
 * @param Scienist variable.
 */
void ScientistService::addScientist(Scientist newScientist)
{
    _SciAccess.readToDatabase(newScientist);
}

/**
 * @brief This function removes a scientist from the .txt file.
 * @param nameOf
 */
void ScientistService::removeScientist (int nameOf)
{
   _SciAccess.removelist(nameOf);
}

/**
 * @brief This funtions removes all scientists.
 */
void ScientistService::removeEveryscientist()
{
    _SciAccess.removeAll();
}

/**
 * @brief This function connects the edit string function in scientistaccess to the concoleUI.
 * @param string nameOf
 * @param string variable
 * @param string newElement
 */
void ScientistService::editScientistString(string nameOf, string variable, string newElement)
{
    _SciAccess.editString (nameOf,variable,newElement);
}

/**
 * @brief This function connects the edit int function in scientistaccess to the concoleUI.
 * @param string nameOf
 * @param string variable
 * @param int newElement
 */
void ScientistService::editScientistInt (string nameOf, string variable, int newElement)
{
    _SciAccess.editInt (nameOf,variable,newElement);
}

/**
 * @brief This function connects the search name in scientistaccess to the concoleUI.
 * @param string command
 * @return vector scientist.
 */
vector<Scientist> ScientistService::searchName(string command)
{
    return _SciAccess.searchQueryString("Name",command);
}

/**
 * @brief This function connects the search sex in scientistaccess to the concoleUI.
 * @param string command
 * @return vector scientist.
 */
vector<Scientist> ScientistService::searchSex(string command)
{
    return _SciAccess.searchQueryString("Sex",command);
}

/**
 * @brief This function connects the search birth in scientistaccess to the concoleUI.
 * @param int command
 * @return vector scientist.
 */
vector<Scientist> ScientistService::searchBirth(string operatorOf, int command)
{
    return _SciAccess.searchQueryInt("birth",operatorOf,command);
}

/**
 * @brief This function connects the search death in scientistaccess to the concoleUI.
 * @param int command
 * @return vector scientist.
 */
vector<Scientist> ScientistService::searchDeath(string operatorOf,int command)
{
    return _SciAccess.searchQueryInt("death",operatorOf,command);
}

/**
 * @brief This function connects the sorts by name in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByName()
{
    return _SciAccess.sortQuery("name", "ASC");
}
/**
 * @brief This function connects the sorts by sex in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortBySex()
{
    return _SciAccess.sortQuery("sex", "ASC");
}
/**
 * @brief This function connects the sorts by birth in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByBirth()
{
    return _SciAccess.sortQuery("birth", "ASC");
}

/**
 * @brief This function connects the sorts by death in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByDeath()
{
    return _SciAccess.sortQuery("death", "ASC");
}

/**
 * @brief This function connects the reversed sorts by name in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByNameReverse()
{
    return _SciAccess.sortQuery("name", "DESC");
}

/**
 * @brief This function connects the reversed sorts by sex in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortBySexReverse()
{
    return _SciAccess.sortQuery("sex", "DESC");
}
/**
 * @brief This function connects the reversed sorts by birth in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByBirthReverse()
{
    return _SciAccess.sortQuery("birth", "DESC");
}

/**
 * @brief This function connects the reversed sorts by death in scientistaccess to the concoleUI.
 * @return vector scientist.
 */
vector<Scientist> ScientistService::sortByDeathReverse()
{
    return _SciAccess.sortQuery("death", "DESC");
}

/**
 * @brief A function that validates if the name which the user asks to input is valid.
 * @param string name of the scientist.
 * @return true/false.
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

/**
 * @brief A function to validate if the input sex from the users is valid.
 * @param string containing scientists gender.
 * @return true/false.
 */
bool ScientistService::validSex(string sex)
{
    if(sex == "female" || sex == "Female" || sex == "f" || sex == "F" || sex == "male" || sex == "Male" || sex == "m" || sex == "M")
    {
        return true;
    }
    else return false;
}

/**
 * @brief A function to check if the year which the user inputs into the program is valid.
 * @param string contianing year.
 * @return true/false.
 */
bool ScientistService::validYear(string strYear)
{

    int year = atoi(strYear.c_str());
    bool valid = false;
    for(unsigned int i = 0; i < strYear.size(); i++)
    {
        if(isdigit(strYear.at(i)) || year < 2016)
        {
            valid = true;
        }

        if(!(isdigit(strYear.at(i))) || year > 2016)
        {
            valid = false;
            return valid;
        }
    }
    return valid;
}

/**
 * @brief ScientistService::validNumber
 * @param strNum
 * @return
 */

bool ScientistService::validNumber(string strNum)
{

    int num = atoi(strNum.c_str());
    bool valid = false;
    for(unsigned int i = 0; i < strNum.size(); i++)
    {
        if(isdigit(strNum.at(i)))
        {
            valid = true;
        }

        if(!(isdigit(strNum.at(i))))
        {
            valid = false;
            return valid;
        }
    }
    return valid;
}


/**
 * @brief A function which validates the death of the scientist when the user inputs it
 * into the program.
 * @param int birth year.
 * @param string death year.
 * @return true/false.
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

/**
 * @brief A function which returns the length of the longest name in the database.
 * @param vector of Scientist variables.
 * @return int variable.
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

/**
 * @brief A function which returns the length of the longest citation in the database.
 * @param A vector of Scientists.
 * @return int variable.
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

/**
 * @brief A function which allows the user to input various form of inputs to
 * make it easier to input the scientists gender.
 * @param string containing the users input.
 * @return string sex (changed to the correct format).
 */
string ScientistService::mOrF(string sex)
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

/**
 * @brief A function to make the first letter of all names a capital letter.
 * @param string name(input from user).
 * @return string Scientist name.
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

/**
 * @brief ScientistService::validCommand, checks if the input from user is valid.
 * @param string command.
 * @return true/false.
 */
bool ScientistService::validCommand(string command)
{
    if(command == "1" || command == "2" || command == "3" || command == "4" || command == "name" || command == "Name" || command == "sex" || command == "Sex" || command == "birth" || command == "Birth" || command == "death" || command == "Death")
        return true;
    else
        return false;
}

/**
 * @brief ScientistService::allScientistID, This function connects the ID in linkaccess to the ConsoleUI.
 * @return vector scientist.
 */
vector <int> ScientistService::allScientistID ()
{
    return _link.ScientistId();
}
