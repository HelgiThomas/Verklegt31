#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H

#include "data/computeraccess.h"
#include "data/scientistaccess.h"
#include "data/linkaccess.h"

#include <vector>

using namespace std;

/**
 * @brief The ScientistService class, handles Business level operations for Scientists.
 */
class ScientistService
{
public:
    /**
     * @brief ScientistService, Default constructor for the class ScientistsService.
     */
    ScientistService();

    /**
     * @brief getScientists, Function to return a vector of all the Scientists.
     * @return vector<Scientist>.
     */
    vector<Scientist> getScientists();

    /**
     * @brief addScientist, Function to add a new scientist.
     * @param Scientist newScientist.
     */
    void addScientist(Scientist newScientist);

    /**
    * @brief searchName Functions to search for different things.
     * @param string/int command.
     * @return vector <Scientist>.
     */
    vector<Scientist> searchName (string command);
    vector<Scientist> searchSex (string command);
    vector<Scientist> searchBirth (string operatorOf, int command);
    vector<Scientist> searchDeath (string operatorOf, int command);

    /**
     * @brief removeScientist/Every, Function to remove a scientist from the list.
     * @param string name.
     */
    void removeScientist (int nameOf);
    void removeEveryscientist ();

    /**
     * @brief editScientistString/int, Function edits the scientists.
     * @param string nameOf
     * @param string variable
     * @param string/int newElement
     */
    void editScientistString(int id, string variable, string newElement);
    void editScientistInt (int id, string variable, int newElement);

    /**
     * @brief validName/Sex/Year/Number/Death/Command, Functions to validate if the entries when input by the user.
     * @param name, sex, year, (birth, str death), command.
     * @return true/false.
     */
    bool validName(string name);
    bool validSex(string sex);
    bool validYear(string year);
    bool validNumber(string strNum);
    bool validDeath(int birth, string strDeath);
    bool validCommand(string command);

    /**
     * @brief lengthOfLongestName/Citation, Functions to return the longest name/citaton to make the UI look nice.
     * @param vector<Scientist> scientists
     * @return integer
     */
    int lengthOfLongestName(vector<Scientist> scientists);
    int lengthOfLongestCitation (vector<Scientist> scientists);

    /**
     * @brief mOrF/makeFirstLetterBig, Functions to check and verify inputs by the user, male_or_female() and
     * make the first letter of each name a capital letter.
     * @param sex, name
     * @return string
     */
    string mOrF(string sex);
    string makeFirstLetterBig(string name);

    vector<int> allScientistID();


private:
    vector<Scientist> listOfScientist;
    ScientistAccess _SciAccess;
    ComputerAccess _ComAccess;
    LinkAccess _link;
};

#endif // PERFORMERSERVICE_H
