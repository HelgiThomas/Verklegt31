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
 * @param int nameOf
 */
void ComputerService::removeComputer (int nameOf)
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
 * @brief This function connects the edit string function in computeraccess to the concoleUI.
 * @param string nameOf
 * @param string variable
 * @param string newElement
 */
void ComputerService::editComputerString(string nameOf, string variable, string newElement)
{
    _ComAccess.editString (nameOf,variable,newElement);
}

/**
 * @brief This function connects the edit int function in computeraccess to the concoleUI.
 * @param string nameOf
 * @param string variable
 * @param int newElement
 */
void ComputerService::editComputerInt(string nameOf, string variable, int newElement)
{
    _ComAccess.editInt (nameOf,variable,newElement);
}

/**
 * @brief This function connects the search name in computeraccess to the concoleUI.
 * @param string command
 * @return vector computer.
 */
vector<Computer> ComputerService::searchName(string command)
{
    return _ComAccess.searchQueryString("Name",command);
}

/**
 * @brief This function connects the search year in computeraccess to the concoleUI.
 * @param string operatorOf
 * @param int command
 * @return vector computer.
 */


/**
 * @brief This function connects the search type in computeraccess to the concoleUI.
 * @param string command
 * @return vector computer.
 */
vector<Computer> ComputerService::searchType(string command)
{
    return _ComAccess.searchQueryString("Type",command);
}

/**
 * @brief This function connects the search was built in computeraccess to the concoleUI.
 * @param string builtOf
 * @param string operatorOf
 * @return vector computer.
 */
vector<Computer> ComputerService::searchwasBuilt(string builtOf, string operatorOf)
{
    return _ComAccess.searchQueryString("wasBuilt",operatorOf);
}

/**
 * @brief This function connects the reversed sorts by name in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByName()
{
    return _ComAccess.sortQuery("name", "ASC");
}

/**
 * @brief This function connects the reversed sorts by build year in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByBuildYear()
{
    return _ComAccess.sortQuery("year", "ASC");
}

/**
 * @brief This function connects the reversed sorts by comp type in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByCompType()
{
    return _ComAccess.sortQuery("type", "ASC");

}

/**
 * @brief This function connects the reversed sorts by was built in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortBywasBuilt()
{
    return _ComAccess.sortQuery("wasBuilt", "ASC");
}

/**
 * @brief This function connects the reversed sorts by name in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByNameReverse()
{
    return _ComAccess.sortQuery("name", "ASC");

}

/**
 * @brief This function connects the reversed sorts by build year in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByBuildYearReverse()
{
    return _ComAccess.sortQuery("year", "DESC");

}

/**
 * @brief This function connects the reversed sorts by comp type in computeraccess to the concoleUI.
 * @return vector computer.
 */
vector<Computer> ComputerService::sortByCompTypeReverse()
{
    return _ComAccess.sortQuery("type", "DESC");

}

/**
 * @brief This function connects the reversed sorts by was built in computeraccess to the concoleUI.
 * @return vector computer.
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
    bool valid = true;
    for(unsigned int i = 0; i < name.size(); i++)
    {

        if(!isalpha(name.at(i)))
        {
            valid = false;
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
        if(!isalpha(compType.at(i)))
        {
            if(compType.at(i) == ' ')
            valid = true;
            else
            valid = false;
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
 * @brief A function which returns the length of the longest type in the database.
 * @param A vector of computers.
 * @return int variable.
 */
int ComputerService::lengthOfLongestType(vector<Computer> computers)
{
    Computer temp;
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        if(temp.getCompType().size() < computers[i].getCompType().size())
        {
            temp = computers[i];
        }
    }
    return temp.getCompType().size();
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

/**
 * @brief This function connects the ID in linkaccess to the ConsoleUI.
 * @return vector computer.
 */
vector <int> ComputerService::allComputerID ()
{
    return _link.ComputerId();
}
