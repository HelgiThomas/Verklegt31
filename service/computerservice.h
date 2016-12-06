#ifndef COMPUTERSERVICE_H
#define COMPUTERSERVICE_H
#include "data/dataaccess.h"
#include <vector>

using namespace std;

class ComputerService
{
public:
    /**
     * @brief Default constructor for the class ComputerService.
     */
    ComputerService();

    /**
     * @brief Function to return a vector of all the Computers.
     * @return vector<Computer>.
     */
    vector<Computer> getComputer();

    /**
     * @brief Function to add a new computer.
     * @param Computer newComputer.
     */
    void addComputer(Computer newComputer);

    /**
     * @brief Functions to search for different things.
     * @param string/int command.
     * @return vector <Computer>.
     */
    vector<Computer> searchName (string command);
    vector<Computer> searchBuildYear (int command);
    vector<Computer> searchCompType(string command);

    /**
     * @brief Functions to sort by different means.
     * @return vector<Computer>.
     */
    vector<Computer> sortByName();
    vector<Computer> sortByBuildYear();
    vector<Computer> sortByCompType();

    /**
     * @brief Functions to sort in reverse order by various different means.
     * @return vector<Computer>.
     */
    vector<Computer> sortByNameReverse();
    vector<Computer> sortByBuildYearReverse();
    vector<Computer> sortByCompTypeReverse();

    /**
     * @brief Function to remove a computer from the list.
     * @param string name.
     */
    void removeComputer (string name);
    //comment below helgi
    void removeEverycomputer ();

    /**
     * @brief Functions to validate if the entries when input by the user.
     * @param name, wasBuilt, year, command.
     * @return true/false.
     */
    bool validName(string name);
    bool validCompType(string compType);
    bool validWasBuilt(string wasBuilt);
    bool validYear(string year);
    bool validCommand(string command);

    /**
     * @brief Functions to return the longest name to make the UI look nice.
     * @param vector<Computer> computers
     * @return integer
     */
    int lengthOfLongestName(vector<Computer> computers);

private:
    vector<Computer> listOfComputer;
    DataAccess _access;
};

#endif // COMPUTERSERVICE_H