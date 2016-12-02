#include "ui/consoleui.h"
#include "model/scientist.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

/*
 * A default consructor, no need to initialize any variables.
 */
ConsoleUI::ConsoleUI()
{

}

/*
 * This is the first menu function, which the user chooses a command
 * to select between the various functions we've got in our program.
 */
void ConsoleUI::run()
{
    do
    {
    cout << "Please enter the name or number of one of the commands below:" << endl << endl;
    cout << "1. Add" << endl;
    cout << "2. Remove" << endl;
    cout << "3. List" << endl;
    cout << "4. Sort" << endl;
    cout << "5. Reversed sort" << endl;
    cout << "6. Search " << endl;
    cout << "7. Quit" << endl << endl << "=> ";

    string command;
    cin >> command;
    cout << endl;

    if (command == "add" || command == "Add" || command == "1")
      {
          addSci();
      }
      else if (command == "Remove" || command == "remove" || command == "2")
      {
         removeSci ();
      }
      else if (command == "list" || command == "List" || command == "3")
      {
          list();
      }
      else if (command == "sort" || command == "Sort" || command == "4")
      {
          sortSci();
      }
      else if (command == "reversed" || command == "Reversed" || command == "reversed sort" || command == "Reversed sort"|| command == "5")
      {
          reversedSortSci();
      }
      else if (command == "search" || command == "Search" || command == "6")
      {
          searchList();
      }
      else if (command == "quit" || command == "Quit" || command == "7")
      {
          exit(10);
      }
      else
      {
          clearScreen();
          cout << "Invalid command!" << endl << endl;
      }
    } while (1 < 2);
}

/*
 * This function is called when the list command is selected by the user.
 * It lists out all the users in the order they were put into the program.
 */
void ConsoleUI::list()
{
    vector <Scientist> Scientist = _service.getScientist();
    displayListOfScientists(Scientist);
    cout << endl;
}

/*
 * This function is called when the user chooses the add command.
 * It asks the user to put in the correct information to add an new scientist.
 * Also handles errors if the user puts the wrong information into a certain field.
 */
void ConsoleUI::addSci()
{
    clearScreen();
    string name;
    string sex;
    string citation;
    string strBirth;
    string strDeath;
    int birth;
    int death;

    cout << "Name: ";
    std::getline(cin, name);
    std::getline(cin, name);

    while(!validName(name))
    {
        cout << "Invalid name!" << endl;
        cout << "Name: ";
        std::getline(cin, name);

    }
    name = makeFirstLetterBig(name);
    cout << "Sex: ";
    cin >> sex;
    while(!validSex(sex))
    {
        if(sex == "yes")
        {
            cout << "A prostitute has been sent to your location." << endl;
            cout << "Sex: ";
            cin >> sex;
        }
        else
        {
            cout << "Invalid sex!" << endl;
            cout << "Sex: ";
            cin >> sex;
        }
    }
    sex = MorF(sex);

    cout << "Year of birth: ";
    cin >> strBirth;

    while(validYear(strBirth) == false)
        {
            cout << "Invalid input!" << endl;
            cout << "Year of birth: ";
            cin >> strBirth;
        }

    birth = atoi(strBirth.c_str());
    if(!isPersonAlive())
    {
        cout << "Year of death: ";
        cin >> strDeath;

        while(validYear(strDeath) == false || validDeath(birth, strDeath) == false)
            {
                cout << "Invalid input!" << endl;
                cout << "Year of death: ";
                cin >> strDeath;
            }
        death = atoi(strDeath.c_str());
     }
     else
     {
        death = 0000;
      }
   if(askIfCitation())
   {
        cout << "Citation: " ;
        std::getline(cin, citation);
   }
   else
   {
       citation = "No citation to be displayed.";
   }
   Scientist newScientist (name,sex,birth,death,citation);
   _service.addScientist(newScientist);
    cout << "Scientist added." << endl << endl;
    string input;
    cout << endl << "Press any key to continue, and then press Enter...";
    cin >> input;

        clearScreen();


}
void ConsoleUI::removeSci ()
{
    string nameOf;
    cout << "Which scientist would you like to remove? " << endl << endl << "=> ";;
    std::getline(cin, nameOf);
    std::getline(cin, nameOf);

    _service.removeScientist (nameOf);
    cout << endl << "Scientist removed " << endl << endl;

}

/*
 * This is the function that's called when the user selects the sort command.
 * It sorts the list of scientists by either Name, Sex, Birth or Death. Depending
 * the the command the user selects.
 */
void ConsoleUI::sortSci()
{
    clearScreen();
    cout << "What would you like to sort it by?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Sex" << endl;
    cout << "3. Birth" << endl;
    cout << "4. Death" << endl << endl << "=> ";

    string command;
    cin >> command;

    if(command == "name" || command == "Name" || command == "1")
    {
        vector<Scientist> Scientist = _service.sortByName();
        displayListOfScientists(Scientist);
    }
    else if(command == "sex" || command == "Sex" || command == "2")
    {
        vector<Scientist> Scientist = _service.sortBySex();
        displayListOfScientists(Scientist);
    }
    else if(command == "birth" || command == "Birth" || command == "3")
    {
        vector<Scientist> Scientist = _service.sortByBirth();
        displayListOfScientists(Scientist);
    }
    else if(command == "death" || command == "Death" || command == "4")
    {
        vector<Scientist> Scientist = _service.sortByDeath();
        displayListOfScientists(Scientist);
    }
    else
    {
        cout << "Invalid sort!" << endl;
        sortSci();
    }
}

/*
 * This function works exactly the same as the function the sortSci() function but
 * reverses the sorting. It can sort by either Name, Sex, Birth and Death.
 */
void ConsoleUI::reversedSortSci()
{
    clearScreen();
    cout << "What would you like to reverse sort it by?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Sex" << endl;
    cout << "3. Birth" << endl;
    cout << "4. Death" << endl << endl << "=> ";

    string command;
    cin >> command;

    if(command == "name" || command == "Name" || command == "1")
    {
        vector<Scientist> Scientist = _service.sortByNameReverse();
        displayListOfScientists(Scientist);
    }
    else if(command == "sex" || command == "Sex" || command == "2")
    {
        vector<Scientist> Scientist = _service.sortBySexReverse();
        displayListOfScientists(Scientist);
    }
    else if(command == "birth" || command == "Birth" || command == "3")
    {
        vector<Scientist> Scientist = _service.sortByBirthReverse();
        displayListOfScientists(Scientist);
    }
    else if(command == "death" || command == "Death" || command == "4")
    {
        vector<Scientist> Scientist = _service.sortByDeathReverse();
        displayListOfScientists(Scientist);
    }
    else
    {
        cout << "Invalid sort!" << endl;
        reversedSortSci();
    }
}

/*
 * This function search the list of scientists and you can choose to sort by either
 * Name, Sex, Birth and Death. GÆTUM KANNSKI LÍKA LEITAÐ Í ÖLLU SHITTINU??
 */
void ConsoleUI::searchList ()
{
    clearScreen();

    string command;
    cout << "By what would you like to search for? " << endl;
    cout << "1. Name" << endl;
    cout << "2. Sex" << endl;
    cout << "3. Birth" << endl;
    cout << "4. Death" << endl << endl;
    cout << "=> ";
    cin >> command;


    if(command == "name" || command == "Name" || command == "1")
    {
        clearScreen();
        string nameOf;
        cout << "Which name would you like to search for? " << endl << endl << "=> ";
        std::getline(cin, nameOf);
        std::getline(cin, nameOf);
        vector<Scientist>names = _service.searchName (nameOf);
        validateSearch(names);
    }
    else if(command == "sex" || command == "Sex" || command == "2")
    {
        clearScreen();
        string sexOf;
        cout << "Which sex would you like to search for? " << endl << endl << "=> ";
        cin >> sexOf;
        vector<Scientist>names = _service.searchSex (sexOf);
        validateSearch(names);

    }
    else if(command == "birth" || command == "Birth" || command == "3")
    {
        clearScreen();
        int birthOf;
        cout << "Which year of birth would you like to search for? " << endl << endl << "=> ";
        cin >> birthOf;
        vector<Scientist>names = _service.searchBirth (birthOf);
        validateSearch(names);
    }
    else if(command == "death" || command == "Death" || command == "4")
    {
        clearScreen();
        int deathOf;
        cout << "Which date of death would you like to serach for? " << endl << endl << "=> ";
        cin >> deathOf;
        vector<Scientist>names =_service.searchDeath (deathOf);
        validateSearch(names);

    }
}

/*
 * This function displays the list of scientists and is called when the user
 * calls for the list option the menu.
 * @param: vector Scientists.
 */
void ConsoleUI::displayListOfScientists (vector<Scientist> Scientist)
{
    clearScreen();
    cout << setw(lengthOfLongestName(Scientist)) << left;
    cout << "Name" << "\t\t";
    cout << "Sex" << " \t\t";
    cout << "Birth" << "\t\t";
    cout << "Death" << "\t\t";
    cout << "Citation" << "\t\t" << endl;

    for(int i = 0; i < (lengthOfLongestName(Scientist) + 50); i++)
    {
        cout << "-";
    }

    for(int i = 0; i < (lengthOfLongestCitation(Scientist) + 20); i++)
    {
        cout << "-";
    }
    cout << endl;

    for (unsigned int i = 0 ; i < Scientist.size();i++)
    {

        cout << setw(lengthOfLongestName(Scientist)) << left;
        cout << Scientist [i].getName () << "\t | \t";
        cout << Scientist [i].getSex () << "\t | \t";
        cout << Scientist [i].getBirth () << "\t | \t";
        cout << Scientist [i].getDeath () << "\t | \t";
        cout << Scientist [i].getCitation () << "\t\t" << endl;
    }
    cout << endl;
}

/*
 * This function clears the screen to make the menu look clean and beautiful.
 * calls for the system command "cls" for windows and "clear" for apple systems.
 */
void ConsoleUI::clearScreen()
{
    #ifdef _WIN32
        system ("cls");
    #endif
    #ifdef __APPLE__
        system("clear");
    #endif

}

/*
 * A function that validates if the name which the user asks to input is valid.
 * @param: string name of the scientist.
 * @return: true/false.
 */
bool ConsoleUI::validName(string name)
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
bool ConsoleUI::validSex(string sex)
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
bool ConsoleUI::validYear(string strYear)
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
bool ConsoleUI::validDeath(int birth, string strDeath)
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
int ConsoleUI::lengthOfLongestName(vector<Scientist> scientists)
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
int ConsoleUI::lengthOfLongestCitation(vector<Scientist> scientists)
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
 * A function which returns true if the scientist is alive or false if the scientist
 * is dead.
 * @return: true/false.
 */
bool ConsoleUI::isPersonAlive()
{
    string input;
    cout << "Is this person alive? (Y/N): ";
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

/*
 * A function which allows the user to input various form of inputs to
 * make it easier to input the scientists gender.
 * @param: string containing the users input.
 * @return: string sex (changed to the correct format).
 */
string ConsoleUI::MorF(string sex)
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
string ConsoleUI::makeFirstLetterBig(string name)
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

/*
 * A function to validate if the list of scientists contains any names to display.
 * @param: Vector of Scientists.
 */
void ConsoleUI::validateSearch(vector<Scientist>names)
{
    if (names.size() > 0)
    {
     displayListOfScientists(names);
    }
    else
    {
     cout << "Nothing found in the list." << endl;
    }
    cout << endl;
}

bool ConsoleUI::askIfCitation()
{
    string input;
    cout << "Would you like to write a citation on the scientist? (Y/N) ";
    std::getline(cin, input);
    std::getline(cin, input);

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
        cout << endl << "Invalid input!";
        return askIfCitation();
    }

}
