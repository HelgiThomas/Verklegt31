#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include "data/dataaccess.h"
#include <vector>

using namespace std;


class ScientistService
{
public:
    /**
     * @brief Default constructor for the class ScientistsService.
     */
    ScientistService();

    /**
     * @brief Function to return a vector of all the Scientists.
     * @return vector<Scientist>.
     */
    vector<Scientist> getScientist();

    /**
     * @brief Function to add a new scientist.
     * @param Scientist newScientist.
     */
    void addScientist(Scientist newScientist);

    /**
     * @brief Functions to search for different things.
     * @param string/int command.
     * @return vector <Scientist>.
     */
    vector<Scientist> searchName (string command);
    vector<Scientist> searchSex (string command);
    vector<Scientist> searchBirth (int command);
    vector<Scientist> searchDeath (int command);

    /**
     * @brief Functions to sort by different means.
     * @return vector<Scientist>.
     */
    vector<Scientist> sortByName();
    vector<Scientist> sortBySex();
    vector<Scientist> sortByBirth();
    vector<Scientist> sortByDeath();

    /**
     * @brief Functions to sort in reverse order by various different means.
     * @return vector<Scientist>.
     */
    vector<Scientist> sortByNameReverse();
    vector<Scientist> sortBySexReverse();
    vector<Scientist> sortByBirthReverse();
    vector<Scientist> sortByDeathReverse();

    /**
     * @brief Function to remove a scientist from the list.
     * @param string name.
     */
    void removeScientist (string name);

    /**
     * @brief Functions to validate if the entries when input by the user.
     * @param name, sex, year, (birth, str Death), command.
     * @return true/false.
     */
    bool validName(string name);
    bool validSex(string sex);
    bool validYear(string year);
    bool validDeath(int birth, string strDeath);
    bool validCommand(string command);

    /**
     * @brief Functions to return the longest Name/Citaton to make the UI look nice.
     * @param vector<Scientist> scientists
     * @return integer
     */
    int lengthOfLongestName(vector<Scientist> scientists);
    int lengthOfLongestCitation (vector<Scientist> scientists);

    /**
     * @brief Functions to check and verify inputs by the user, Male_or_Female() and
     * make the first letter of each name a capital letter.
     * @param sex, name
     * @return string
     */
    string MorF(string sex);
    string makeFirstLetterBig(string name);

private:
    vector<Scientist> listOfScientist;
    DataAccess _access;
};

#endif // PERFORMERSERVICE_H
