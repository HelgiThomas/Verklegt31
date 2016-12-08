#include "service/computerservice.h"
#include "algorithm"

using namespace std;

/**
 * @brief This is the default constructor.
 */
ComputerService::ComputerService()
{

}

/**
 * @brief This function returns the list of all the computers in the .txt file.
 * @return vector of computers.
 */
vector <Computer> ComputerService::getComputers()
{

    listOfComputer = _ComAccess.readFromDatabase();
    return listOfComputer;

}

/**
 * @brief This function adds a new computer to the .txt file.
 * @param Computer variable.
 */
void ComputerService::addComputer(Computer newComputer)
{

    _ComAccess.readToDatabase(newComputer);

}

/**
 * @brief This function removes a computer from the .txt file.
 * @param nameOf
 */
void ComputerService::removeComputer (string nameOf)
{

   _ComAccess.removelist(nameOf);

}

/**
 * @brief This function removes all computers from the list
 */
void ComputerService::removeEverycomputer ()
{
    _ComAccess.removeAll();
}

/**
 * @brief ComputerService::editComputerString
 * @param nameOf
 * @param variable
 * @param newElement
 */
void ComputerService::editComputerString(string nameOf, string variable, string newElement)
{
    _ComAccess.editString (nameOf,variable,newElement);
}

/**
 * @brief ComputerService::editComputerInt
 * @param nameOf
 * @param variable
 * @param newElement
 */
void ComputerService::editComputerInt(string nameOf, string variable, int newElement)
{
    _ComAccess.editInt (nameOf,variable,newElement);
}

/**
 * @brief This function sorts the computers name
 * @return
 */
vector<Computer> ComputerService::sortByName()
{
    return _ComAccess.sortQuery("name", "ASC");
}

/**
 * @brief This function sorts from the computers build year
 * @return
 */
vector<Computer> ComputerService::sortByBuildYear()
{
    return _ComAccess.sortQuery("year", "ASC");
}

/**
 * @brief ComputerService::sortByCompType
 * @return
 */
vector<Computer> ComputerService::sortByCompType()
{
    return _ComAccess.sortQuery("type", "ASC");

}

/**
 * @brief ComputerService::sortBywasBuilt
 * @return
 */
vector<Computer> ComputerService::sortBywasBuilt()
{
    return _ComAccess.sortQuery("wasBuilt", "ASC");
}

/**
 * @brief ComputerService::sortByNameReverse
 * @return
 */
vector<Computer> ComputerService::sortByNameReverse()
{
    return _ComAccess.sortQuery("name", "ASC");

}

/**
 * @brief ComputerService::sortByBuildYearReverse
 * @return
 */
vector<Computer> ComputerService::sortByBuildYearReverse()
{
    return _ComAccess.sortQuery("year", "DESC");

}

/**
 * @brief ComputerService::sortByCompTypeReverse
 * @return
 */
vector<Computer> ComputerService::sortByCompTypeReverse()
{
    return _ComAccess.sortQuery("type", "DESC");

}

/**
 * @brief ComputerService::sortBywasBuiltReverse
 * @return
 */
vector<Computer> ComputerService::sortBywasBuiltReverse()
{
    return _ComAccess.sortQuery("wasBuilt", "DESC");
}

/**
 * @brief A function that validates if the name which the user asks to input is valid.
 * @param string name of the computer.
 * @return true/false.
 */
bool ComputerService::validName(string name)
{
    bool valid = false;
    for(unsigned int i = 0; i < name.size(); i++)
    {

        if(0) //<--------!IsNullOrWhitespace(name.at(i))
        {
                //TODO: Laga eitthvað með þessa if setningu..
            valid = true;
        }


    }
    return valid;
}

/**
 * @brief ComputerService::validCompType
 * @param compType
 * @return
 */
bool ComputerService::validCompType(string compType)
{
    bool valid = false;
    for(unsigned int i = 0; i < compType.size(); i++)
    {

        if(isalpha(compType.at(i)))
        {
            valid = true;
        }


    }
    return valid;
}


/**
 * @brief A function to check if the year which the user inputs into the program is valid.
 * @param string contianing year.
 * @return true/false.
 */
bool ComputerService::validYear(string strYear)
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

/**
 * @brief A function which returns the length of the longest name in the database.
 * @param vector of Computer variables.
 * @return int variable.
 */
int ComputerService::lengthOfLongestName(vector<Computer> computers)
{
    Computer temp;
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if(temp.getName().size() < computers[i].getName().size())
        {
            temp = computers[i];
        }
    }
    return temp.getName().size();
}

/**
 * @brief ComputerService::validCommand -> checks if the input from user is valid.
 * @param string command.
 * @return true/false.
 */
bool ComputerService::validCommand(string command)
{
    if(command == "1" || command == "2" || command == "3" || command == "4" || command == "name" || command == "Name" || command == "year" || command == "Year" || command == "Type" || command == "type"|| command == "Built" || command == "built")
        return true;
    else
        return false;
}
