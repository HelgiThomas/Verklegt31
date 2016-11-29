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

    if (command == "list" || command == "List" || command == "1")
    {
        list();
    }
    else if (command == "add" || command == "Add" || command == "2")
    {
        addSci();
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
    for (unsigned int i = 0 ; i < Scientists.size();i++)
    {
        cout << Scientists [i].getName () << endl;
        cout << Scientists [i].getSex () << endl;
        cout << Scientists [i].getBirth () << endl;
        cout << Scientists [i].getDeath () << endl;
        cout << "###################" << endl;
    }
}

void ConsoleUI::addSci()
{
    clearScreen();
    string name;
    string sex;
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
    cout << "Date of birth: ";
    cin >> birth;
    cout << "Date of death: ";
    cin >> death;

    Scientist newScientist (name,sex,birth,death);
    _service.addScientist(newScientist);

}

void ConsoleUI::sortSci()
{

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
        if(!((name[i] >= 'A' && name[i] < '[') || (name[i] > '`' && name[i] <= 'z')))
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
