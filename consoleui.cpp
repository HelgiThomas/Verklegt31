#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"

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
        vector <Performer> performers = _service.getPerformers();
        for (unsigned int i = 0 ; i < performers.size();i++)
        {
            cout << performers [i].getName () << endl;
            cout << performers [i].getSex () << endl;
            cout << performers [i].getBirth () << endl;
            cout << performers [i].getDeath () << endl;
            cout << "###################";
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

        Performer newPerformer (name,sex,birth,death);
        _service.addPerformers(newPerformer);

    }
    } while (1 < 2);
}

void ConsoleUI::displayListOfPerfmers ()
{

}
