#include "consoleui.h"
#include "scientist.h"

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    do
    {
    cout << "Please enter one of the following commands: " << endl << endl;
    cout << "1. Add" << endl;
    cout << "2. List" << endl;
    cout << "3. Sort" << endl;
    cout << "4. Quit" << endl << endl;

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
    else if (command == "sort" || command == "Sort" || command == "3")
    {
        sortSci();
    }
    else if (command == "quit" || command == "Quit" || command == "4")
    {
        exit(10);
    }
    } while (1 < 2);
}

void ConsoleUI::list()
{
    clearScreen();
    vector <Scientist> Scientists = _service.getScientist();
    for (unsigned int i = 0 ; i < Scientists.size()-1;i++)
    {
        cout << Scientists [i].getName () << "\t\t";
        cout << Scientists [i].getSex () << "\t\t";
        cout << Scientists [i].getBirth () << "\t\t";
        cout << Scientists [i].getDeath () << "\t\t" << endl;
    }
    cout << endl;
}

void ConsoleUI::addSci()
{
    clearScreen();
    string name;
    string sex;
    string strBirth;
    string strDeath;
    int birth;
    int death;

    cout << "Name: ";
    cin >> name;
    while(!validName(name))
    {
        cout << "Invalid name!" << endl;
        cout << "Name: " << endl;
        cin >> name;
    }
    cout << "Sex: ";
    cin >> sex;
    while(!validSex(sex))
    {
        cout << "Invalid sex!" << endl;
        cout << "Sex: ";
        cin >> sex;
    }

    cout << "Year of birth: ";
    cin >> strBirth;

    while(validYear(strBirth) == false)
        {
            cout << "Invalid input!" << endl;
            cout << "Year of birth: ";
            cin >> strBirth;
        }

    birth = atoi(strBirth.c_str());

    cout << "Year of death: ";
    cin >> strDeath;

    while(validYear(strDeath) == false || validDeath(birth, strDeath) == false)
        {
            cout << "Invalid input!" << endl;
            cout << "Year of death: ";
            cin >> strDeath;
        }
    death = atoi(strDeath.c_str());

    Scientist newScientist (name,sex,birth,death);
    _service.addScientist(newScientist);

}

void ConsoleUI::sortSci()
{
    cout << "What would you like to sort it by?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Sex" << endl;
    cout << "3. Birth" << endl;
    cout << "4. Death" << endl << endl;

    string command;
    cin >> command;

    if(command == "name" || command == "Name" || command == "1")
    {
        vector<Scientist> Scientist = _service.sortByName();

        for (unsigned int i = 1 ; i < Scientist.size();i++)
        {
            cout << Scientist [i].getName () << "\t\t";
            cout << Scientist [i].getSex () << "\t\t";
            cout << Scientist [i].getBirth () << "\t\t";
            cout << Scientist [i].getDeath () << "\t\t" << endl;
        }
    }
    else if(command == "sex" || command == "Sex" || command == "2")
    {
        vector<Scientist> Scientist = _service.sortBySex();

        for (unsigned int i = 1 ; i < Scientist.size();i++)
        {
            cout << Scientist [i].getName () << "\t\t";
            cout << Scientist [i].getSex () << "\t\t";
            cout << Scientist [i].getBirth () << "\t\t";
            cout << Scientist [i].getDeath () << "\t\t" << endl;
        }
    }
    else if(command == "birth" || command == "Birth" || command == "3")
    {
        vector<Scientist> Scientist = _service.sortByBirth();

        for (unsigned int i = 0 ; i < Scientist.size();i++)
        {
            cout << Scientist [i].getName () << "\t\t";
            cout << Scientist [i].getSex () << "\t\t";
            cout << Scientist [i].getBirth () << "\t\t";
            cout << Scientist [i].getDeath () << "\t\t" << endl;
        }
    }
    else if(command == "death" || command == "Death" || command == "4")
    {
        vector<Scientist> Scientist = _service.sortByDeath();

        for (unsigned int i = 0 ; i < Scientist.size()-1;i++)
        {
            cout << Scientist [i].getName () << "\t\t";
            cout << Scientist [i].getSex () << "\t\t";
            cout << Scientist [i].getBirth () << "\t\t";
            cout << Scientist [i].getDeath () << "\t\t" << endl;
        }
    }
    else
    {
        cout << "Invalid sort!" << endl;
        sortSci();
    }
}

void ConsoleUI::displayListOfScientists ()
{

}

void ConsoleUI::clearScreen()
{
    system("cls");
    system("clear");
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
    if(sex == "female" || sex == "male")
    {
        return true;
    }
    else return false;
}

bool ConsoleUI::validYear(string year)
{
    for(int i = 0; i < year.size(); i++)
        {
            if(isalpha(year.at(i)))
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
