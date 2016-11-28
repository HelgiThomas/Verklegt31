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
    cout << "listajslkajsdklajsdlkajsdlkajsdlaksjdlaksdjalksjdr" << endl;
<<<<<<< HEAD
    cout << "Halloooo";
=======
    cout << "Er þessi lína núna hjá ykkur?" << endl;
>>>>>>> origin/master
    string command;
    cin >> command;

    if (command == "list")
    {
        vector <Performer> performers = _service.getPerformers();
        for (unsigned int i = 0 ; i < performers.size();i++)
        {
            cout << performers [i].getName () << endl;
        }

    }
    else if (command == "add")
    {
        string name;
        string sex;
        int birth;
        int death;

        cin >> name;
        cin >> sex;
        cin >> birth;
        cin >> death;


    }
}
 void ConsoleUi::displayListOfPerfmers ()
 {

 }
