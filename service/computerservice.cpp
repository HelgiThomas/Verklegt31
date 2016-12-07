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
vector <Computer> ComputerService::getComputer()
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

void ComputerService::removeEverycomputer ()
{
    _ComAccess.removeAll();
}
/**
 * @brief Compares the name and returns true if the second parameter is higher.
 * @param Computer variable.
 * @param Computer variable.
 * @return true/false
 */
struct ComputerCompareName
{
    bool operator() (Computer i,Computer j) { return (i.getName()<j.getName());}
};

/**
 * @brief Compares the build years and returns true if the second parameter is higher.
 * @param Computer variable.
 * @param Computer variable.
 * @return true/false
 */
struct ComputerCompareBuildYear
{
    bool operator() (Computer i,Computer j) { return (i.getBuildYear()<j.getBuildYear());}
};

/**
 * @brief Compares the name and returns true if the first parameter is higher.
 * @param Computer variable.
 * @param Computer variable.
 * @return true/false
 */
struct ComputerCompareNameReverse
{
    bool operator() (Computer i,Computer j) { return (i.getName()>j.getName());}
};

/**
 * @brief Comapares the build years and returns true if the first parameter is higher.
 * @param Computer variable.
 * @param Computer variable.
 * @return true/false
 */
struct ComputerCompareBirthReverse
{
    bool operator() (Computer i,Computer j) { return (i.getBuildYear()>j.getBuildYear());}
};


vector<Computer> ComputerService::sortByName()
{
    return _ComAccess.sortQuery("name", "ASC");
}

vector<Computer> ComputerService::sortByBuildYear()
{
    return _ComAccess.sortQuery("name", "ASC");
}

vector<Computer> ComputerService::sortByCompType()
{
    return _ComAccess.sortQuery("name", "ASC");

}

vector<Computer> ComputerService::sortByNameReverse()
{
    return _ComAccess.sortQuery("name", "ASC");

}

vector<Computer> ComputerService::sortByBuildYearReverse()
{
    return _ComAccess.sortQuery("name", "ASC");

}

vector<Computer> ComputerService::sortByCompTypeReverse()
{
    return _ComAccess.sortQuery("name", "ASC");

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
    if(command == "1" || command == "2" || command == "3" || command == "4" || command == "name" || command == "Name" || command == "build year" || command == "Build year")
        return true;
    else
        return false;
}
