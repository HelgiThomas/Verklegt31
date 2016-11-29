#include <iostream>
#include <string>
#include "consoleui.h"
#include "performer.h"
using namespace std;
ConsoleUI::ConsoleUI()
{

}
void ConsoleUI::run()
{
    cout << "Please enter one of the following commands: " << endl;
    cout << "a" << endl;

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


    }
}
 void ConsoleUI::displayListOfPerfmers ()
 {

 }
