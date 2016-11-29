#include "consoleui.h"
#include "scientist.h"

#include <iostream>
#include <string>

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    do
    {
    cout << "Please enter one of the following commands: " << endl << endl;
    cout << "1. add" << endl;
    cout << "2. list" << endl;

    string command;
    cin >> command;

    if (command == "list")
    {
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
    else if (command == "add")
    {
        string name;
        string sex;
        int birth;
        int death;

        cout << "Name: ";
        cin >> name;
        cout << "Sex: ";
        cin >> sex;
        cout << "Birth: ";
        cin >> birth;
        cout << "Death: ";
        cin >> death;

        Scientist newScientist (name,sex,birth,death);
        _service.addScientist(newScientist);

    }
    } while (1 < 2);
}

void ConsoleUI::displayListOfScientists ()
{

}
