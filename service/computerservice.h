#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H

#include "data/computeraccess.h"
#include "data/scientistaccess.h"
#include "data/linkaccess.h"

#include <vector>

using namespace std;

class ComputerService
{
public:
    /**
     * @brief ComputerService, default constructor.
     */
    ComputerService();

    /**
     * @brief getComputers, returns a vector of all computers.
     * @return vector<Computer>.
     */
    vector<Computer> getComputers();

    /**
     * @brief addComputer, adds a new computer to the database.
     * @param newComputer
     */
    void addComputer(Computer newComputer);

    /**
     * @brief searchName/Year/Type/wasBuilt, search functions to search for all the specified inputs.
     * @param command
     * @return
     */
    vector<Computer> searchName(string command);
    vector<Computer> searchYear(string operatorOf, int command);
    vector<Computer> searchType(string command);
    vector<Computer> searchwasBuilt(string operatorOf);

    /**
     * @brief SortByName/BuildYear/CompType/WasBuilt, sort by for all the specified fields.
     * @return vector<Computer>.
     */
    vector<Computer> sortByName();
    vector<Computer> sortByBuildYear();
    vector<Computer> sortByCompType();
    vector<Computer> sortBywasBuilt();

    /**
     * @brief  sortByName/BuildYear/ComptType/wasBuilt, sort in reverse order by for all the specified fields.
     * @return vector<Computer>.
     */
    vector<Computer> sortByNameReverse();
    vector<Computer> sortByBuildYearReverse();
    vector<Computer> sortByCompTypeReverse();
    vector<Computer> sortBywasBuiltReverse ();

    /**
     * @brief removeComputer/EveryComputer, removes either a single computer or the whole list.
     * @param string name.
     */
    void removeComputer (int nameOf);
    void removeEverycomputer ();

    /**
     * @brief editComputerString/Int, edits a field in Computer.
     * @param string nameOf
     * @param string variable
     * @param string/int newElement
     */
    void editComputerString(string nameOf, string variable, string newElement);
    void editComputerInt(string nameOf, string variable, int newElement);

    /**
     * @brief validName/CompType/WasBuilt/Year/Command, validate the entries input by the user.
     * @param name, wasBuilt, year, command.
     * @return true/false.
     */
    bool validName(string name);
    bool validCompType(string compType);
    bool validWasBuilt(string wasBuilt);
    bool validYear(string year);
    bool validCommand(string command);

    /**
     * @brief lengthOfLongestName/Type, return the longest name/type to make the UI look nice.
     * @param vector<Computer> computers
     * @return integer
     */
    int lengthOfLongestName(vector<Computer> computers);
    int lengthOfLongestType(vector<Computer> computers);

private:
    vector<Computer> listOfComputer;
    ScientistAccess _SciAccess;
    ComputerAccess _ComAccess;
    LinkAccess _link;

    vector <int> allComputerID ();
};

#endif // COMPUTERSERVICE_H
