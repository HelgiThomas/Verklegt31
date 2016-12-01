#include "ui/consoleui.h"
#include "model/scientist.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    do
    {
    cout << "Please enter one of the following commands: " << endl << endl;
    cout << "0. Instructions" << endl;
    cout << "1. Add" << endl;
    cout << "2. List" << endl;
    cout << "3. Reversed sort" << endl;
    cout << "4. Sort" << endl;
    cout << "5. Search " << endl;
    cout << "6. Quit" << endl << endl << "=> ";

    string command;
    cin >> command;


    if (command == "add" || command == "Add" || command == "1")
      {
          addSci();
      }
      else if (command == "list" || command == "List" || command == "2")
      {
          list();
      }
      else if (command == "reversed" || command == "Reversed" || command == "reversed sort" || command == "Reversed sort"|| command == "3")
      {
          reversedSortSci();
      }
      else if (command == "sort" || command == "Sort" || command == "4")
      {
          sortSci();
      }
      else if (command == "search" || command == "Search" || command == "5")
      {
          searchList();
      }
      else if (command == "quit" || command == "Quit" || command == "6")
      {
          exit(10);
      }
      else
      {
          cout << "Invalid command!" << endl;
      }
    } while (1 < 2);
}

void ConsoleUI::list()
{
    vector <Scientist> Scientist = _service.getScientist();
    displayListOfScientists(Scientist);
    cout << endl;
}

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
        cout << "Name: " << endl;
        std::getline(cin, name);
        std::getline(cin, name);

    }
    name = makeFirstLetterBig(name);
    cout << "Sex: ";
    cin >> sex;
    while(!validSex(sex))
    {
        if(sex == "yes")
        {
            cout << "A prostitute has been sent to your location" << endl;
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
   cout << "Citation: " ;
   std::getline(cin, citation);
   std::getline(cin, citation);

   Scientist newScientist (name,sex,birth,death,citation);
   _service.addScientist(newScientist);
    cout << "Scientist added." << endl << endl;

}

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
        cout << "Which year of birth would you like to search for? " << endl << endl; "=> ";
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
void ConsoleUI::displayListOfScientists (vector<Scientist> Scientist)
{
    clearScreen();
    cout << setw(lengthOfLongestName(Scientist)) << left;
    cout << "Name" << "\t\t";
    cout << "Sex" << " \t\t";
    cout << "Birth" << "\t\t";
    cout << "Death" << "\t\t";
    cout << "Citation" << "\t\t" << endl;

    for(int i = 0; i < (lengthOfLongestName(Scientist) + 100); i++)
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

void ConsoleUI::clearScreen()
{
    #ifdef _WIN32
    system ("cls");
    #endif
    #ifdef __APPLE__
    system("clear");
    #endif

}

bool ConsoleUI::validName(string name)
{
    bool valid = true;
    for(unsigned int i = 0; i < name.size(); i++)
    {
        if(!((name[i] >= 'A' && name[i] < '[') || (name[i] > '`' && name[i] <= 'z') || name[i] == ' '))
        {
            valid = false;
        }
    }
    return valid;
}

bool ConsoleUI::validSex(string sex)
{
    if(sex == "female" || sex == "Female" || sex == "f" || sex == "F" || sex == "male" || sex == "Male" || sex == "m" || sex == "M")
    {
        return true;
    }
    else return false;
}

bool ConsoleUI::validYear(string strYear)
{
    int year = atoi(strYear.c_str());
    for(unsigned int i = 0; i < strYear.size(); i++)
        {
            if(isalpha(strYear.at(i)) || year > 2016)
            {
                return false;
            }

        }
    return true;
}

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

bool ConsoleUI::isPersonAlive()
{
    string input;
    cout << "Is this person alive? Press Y for \"Yes\" and N for \"No\": ";
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
