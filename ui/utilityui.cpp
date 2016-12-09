#include "utilityui.h"

#include <iomanip>

UtilityUI::UtilityUI()
{

}

/**
 * @brief clears the screen to make the menu look clean and beautiful.
 * calls for the system command "cls" for windows and "clear" for apple systems.
 */
void UtilityUI::clearScreen()
{
    #ifdef _WIN32
        system ("cls");
    #endif
    #ifdef __APPLE__
        system("clear");
    #endif
}

/**
 * @brief This function displays the list of scientists and is called when the user
 * calls for the list option in the menu.
 * @param vector scientists.
 */
void UtilityUI::displayListOfScientists (vector<Scientist> Scientist)
{
    clearScreen();
    cout << setw(4) << right << "No." << "  | ";
    cout << setw(30) << right << "Name" << " | ";
    cout << setw(6) << right << "Sex" << " | ";
    cout << setw(6) << right << "Birth" << " | ";
    cout << setw(6) << right << "Death" << " | ";
    cout << setw(52) << right << "Citation" << endl;

    for(int i = 0; i < (_serviceSci.lengthOfLongestName(Scientist) + 50); i++)
    {
        cout << "-";
    }

    for(int i = 0; i < (_serviceSci.lengthOfLongestCitation(Scientist) + 20); i++)
    {
        cout << "-";
    }
    cout << endl;

    for (unsigned int i = 0 ; i < Scientist.size();i++)
    {
        cout << setw(4) << right << i + 1 << ". | ";
        cout << setw(30) << right << Scientist [i].getName () << " | ";
        cout << setw(6) << right << Scientist [i].getSex () << " | ";
        cout << setw(6) << right << Scientist [i].getBirth () << " | ";
        cout << setw(6) << right << Scientist [i].getDeath () << " | ";
        cout << setw(64) << right << Scientist [i].getCitation () << endl;
    }
    cout << endl;
}

/**
 * @brief This function displays the list of computers and is called when the user
 * calls for the list option in the menu.
 * @param vector computers.
 */
void UtilityUI::displayListOfComputers(vector<Computer> Computer)
{
    clearScreen();
    cout << setw(4) << right  << "No." << "  | ";
    cout << setw(30) << right << "Name" << " | ";
    cout << setw(6) << right << "Year" << " | ";
    cout << setw(20) << right << "Type" << " | ";
    cout << setw(6) << right << "Built" << endl;

    for(int i = 0; i < (_serviceComp.lengthOfLongestName(Computer) + 30); i++)
    {
        cout << "-";
    }

    for(int i = 0; i < (_serviceComp.lengthOfLongestType(Computer) + 20); i++)
    {
        cout << "-";
    }
    cout << endl;

    for (unsigned int i = 0 ; i < Computer.size();i++)
    {
        cout << setw(4) << right << i + 1 << ". | ";
        cout << setw(30) << right << Computer [i].getName ()  << " | ";
        cout << setw(6) << right << Computer [i].getBuildYear ()  << " | ";
        cout << setw(20) << right << Computer [i].getCompType ()  << " | ";
        cout << setw(6) << right << Computer [i].getWasBuilt () << endl;
    }
    cout << endl;
}

/**
 * This function returns true if the scientist is alive or false if the scientist
 * is dead.
 * @return: true/false.
 */
bool UtilityUI::isPersonAlive()
{
    string input;
    cout << "Is this person alive? (Y/N) ";
    cin >> input;

    if(input == "Y" || input == "y")
    {
        return true;
    }
    else if(input == "N" || input == "n")
    {
        return false;
    }
    else
    {
        cout << "Invalid input!" << endl;
        return isPersonAlive();
    }
}

/**
 * @brief A function to validate if the list of scientists contains any names to display.
 * @param vector scientists.
 */
void UtilityUI::validateSearch(vector<Scientist>search)
{
    if (search.size() > 0)
    {
        displayListOfScientists(search);
    }
    else
    {
        cout << "Nothing found in the list." << endl;
    }
    cout << endl;
}

/**
 * @brief A function to validate if the list of computers contains any names to display.
 * @param vector computers.
 */
void UtilityUI::validateSearch(vector<Computer>search)
{
    if (search.size() > 0)
    {
        displayListOfComputers(search);
    }
    else
    {
        cout << "Nothing found in the list." << endl;
    }
    cout << endl;
}

/**
 * @brief A function to ask the user if he wants to write a citation for his new scientist
 * @return true/false
 */
bool UtilityUI::askIfCitation()
{
    string input;
    cout << "Would you like to write a citation on the scientist? (Y/N) ";

    getline(cin, input);
    getline(cin, input);

    while(input != "Y" && input != "y" && input != "n" && input != "N")
    {
        cout << "Invalid input!" << endl;
        cout << "Type either Y or N: ";
        getline(cin, input);
    }

    if(input == "y" || input == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief A function to ask the user if the computer was built.
 * @return true/false
 */
bool UtilityUI::askIfBuilt()
{
    string input;
    cout << "Was the computer built? (Y/N) ";

    getline(cin, input);
    getline(cin, input);

    while(input != "Y" && input != "y" && input != "n" && input != "N")
    {
        cout << "Invalid input!" << endl;
        cout << "Type either Y or N: ";
        getline(cin, input);
    }

    if(input == "y" || input == "Y")
    {
        return true;
    }
    else
    {
        return false;
    }
}
