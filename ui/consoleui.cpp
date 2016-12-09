#include "ui/consoleui.h"
#include "model/scientist.h"
#include "model/computer.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

/**
 * @brief A default consructor, no need to initialize any variables.
 */
ConsoleUI::ConsoleUI()
{
    score = 0;
}

/**
 * @brief This is the first menu function, which the user chooses a command
 * to select between the various functions we've got in our program.
 */
void ConsoleUI::run()
{
    clearScreen();
    do
    {
        cout << "Please enter the name or number of one of the commands below:" << endl << endl;
        cout << "1. Add" << endl;
        cout << "2. Remove" << endl;
        cout << "3. List" << endl;
        cout << "4. Edit" << endl;
        cout << "5. Sort" << endl;
        cout << "6. Reversed sort" << endl;
        cout << "7. Search " << endl;
        cout << "8. Game" << endl;
        cout << "9. Quit" << endl << endl << "=> ";

        string command;
        cin >> command;
        cout << endl;

        if (command == "add" || command == "Add" || command == "1")
        {
            clearScreen ();
            string choice;
            cout << "What would you like to add? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Back" << endl << endl << "=> ";
            cin >> choice;
            if (choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                addSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                addComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                addRelation();
            }
            else if(choice == "back" || choice == "Back" || choice == "4")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }
        }
        else if (command == "Remove" || command == "remove" || command == "2")
        {
            clearScreen();
            string choice;
            cout << "What would you like to remove? " << endl;
            cout << "1. Person" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Everyone" << endl;
            cout << "5. Back" << endl << endl << "=> ";
            cin >> choice;
            if (choice == "person" || choice == "Person" || choice == "1")
            {
                removeSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                removeComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                //removeRelation();
            }
            else if (choice == "everyone" || choice == "Everyone" || choice == "4")
            {
                removeEverySci();
            }
            else if(choice == "back" || choice == "Back" || choice == "5")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }

        }
        else if (command == "list" || command == "List" || command == "3")
        {
            clearScreen();
            string choice;
            cout << "What would you like to list? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Back" << endl << endl << "=> ";
            cin >> choice;
            if(choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                listSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                listComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                listRelation();
            }
            else if(choice == "back" || choice == "Back" || choice == "4")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }
        }
        else if (command == "edit" || command == "Edit" || command == "4")
        {
            clearScreen ();
            string choice;
            cout << "What would you like to edit? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Back" << endl << endl << "=> ";
            cin >> choice;
            if (choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                editSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                editComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                //editRelation();
            }
            else if(choice == "back" || choice == "Back" || choice == "4")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }
        }
        else if (command == "sort" || command == "Sort" || command == "5")
        {
            clearScreen();
            string choice;
            cout << "Would you like to Sort by, Scientist or Computer?? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Back" << endl << endl << "=> ";
            cin >> choice;
            if(choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                sortSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                sortComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                //sortRelation();
            }
            else if(choice == "back" || choice == "Back" || choice == "4")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }
        }
        else if (command == "reversed" || command == "Reversed" || command == "reversed sort" || command == "Reversed sort"|| command == "6")
        {
            clearScreen();
            string choice;
            cout << "Would you like to Reverse Sort by, Scientist or Computer?? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Relation" << endl;
            cout << "4. Back" << endl << endl << "=> ";
            cin >> choice;
            if(choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                reversedSortSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                reversedSortComp();
            }
            else if(choice == "relation" || choice == "Relation" || choice == "3")
            {
                //reversedSortRelation();
            }
            else if(choice == "back" || choice == "Back" || choice == "4")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }
        }
        else if (command == "search" || command == "Search" || command == "7")
        {
            clearScreen();
            string choice;
            cout << "Would you like to Search by, Scientist or Computer?? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Back" << endl << endl << "=> ";
            cin >> choice;
            if(choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                searchScientistList();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                searchComputerList();
            }
            else if(choice == "back" || choice == "Back" || choice == "3")
            {
                clearScreen();
                run();
            }
            else
            {
                clearScreen();
                cout << "Invalid command!" << endl << endl;
            }


        }
        else if(command == "Game" || command == "game" || command == "8")
        {
            playGame();
        }
        else if (command == "quit" || command == "Quit" || command == "9")
        {
            exit(1);
        }
        else
        {
            clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    } while (1 < 2);
}

/**
 * @brief This function is called when the list command is selected by the user.
 * It lists out all the users in the order they were put into the program.
 */
void ConsoleUI::listSci()
{
    vector<Scientist> Scientist = _serviceSci.getScientists();
    displayListOfScientists(Scientist);
    cout << endl;
}

void ConsoleUI::listComp()
{
    vector <Computer> Computer = _serviceComp.getComputers();
    displayListOfComputers(Computer);
    cout << endl;
}


/**
 * @brief This function is called when the user chooses the add command.
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

    while(!_serviceSci.validName(name))
    {
        cout << "Invalid name!" << endl;
        cout << "Name: ";
        std::getline(cin, name);

    }
    name = _serviceSci.makeFirstLetterBig(name);
    cout << "Sex: ";
    cin >> sex;
    while(!_serviceSci.validSex(sex))
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
    sex = _serviceSci.mOrF(sex);

    cout << "Year of birth: ";
    cin >> strBirth;

    while(_serviceSci.validYear(strBirth) == false)
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

        while(_serviceSci.validYear(strDeath) == false || _serviceSci.validDeath(birth, strDeath) == false)
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
    int id = 0;
    Scientist newScientist (id, name,sex,birth,death,citation);
    _serviceSci.addScientist(newScientist);
    cout << "Scientist added." << endl << endl;
    string input;
    cout << "Press Enter to continue...";
    getline(cin, input);

    clearScreen();
}

/**
 * @brief ConsoleUI::addComp
 */
void ConsoleUI::addComp()
{
    clearScreen();
    string name;
    string strBuiltYear;
    string compType;
    string wasBuilt;
    int builtYear;

    cout << "Name: ";
    std::getline(cin, name);
    std::getline(cin, name);

    name = _serviceSci.makeFirstLetterBig(name);

    cout << "Build year: ";
    cin >> strBuiltYear;
    while(_serviceComp.validYear(strBuiltYear) == false)
    {
        cout << "Invalid input!" << endl;
        cout << "Build year: ";
        cin >> strBuiltYear;
    }
    builtYear = atoi(strBuiltYear.c_str());
    cout << "Computer type: ";
    cin >> compType;

    compType = _serviceSci.makeFirstLetterBig(compType);

    if(askIfBuilt())
    {
        wasBuilt = "Yes";
    }
    else
    {
        wasBuilt = "No";
    }

    int id = 0;
    Computer newComputer (id, name, builtYear, compType, wasBuilt);
    _serviceComp.addComputer(newComputer);
    cout << "Computer added." << endl << endl;
    string input;
    cout << "Press Enter to continue...";
    getline(cin, input);

    clearScreen();
}

/**
 * @brief ConsoleUI::addRelation
 */
void ConsoleUI::addRelation()
{
    clearScreen();
    unsigned int sci;
    unsigned int com;
    vector<Scientist> s;
    vector<Computer> c;
    vector<int> sc;
    vector<int> co;
    int count = 0;


    cout << "List of Scientist:" << endl;
    vector<Scientist> Scientists = _serviceSci.getScientists();
    displayListOfScientists(Scientists);

    string YoN1 = "y";
    while(YoN1 == "y" || YoN1 == "Y" || YoN1 == "yes" || YoN1 == "Yes")
    {
        cout << endl;
        cout << "Pick a scientists you would like to add a relation to (their ID): ";

        cin >> sci;

        if(count == 0)
        {
            while(sci > Scientists.size() || sci < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                cin >> sci;
            }
        }

        else
        {
            while(!_serviceGen.validRelation(sci, sc) || sci > Scientists.size() || sci < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                cin >> sci;
            }
        }

        cout << endl;
        cout << "You picked " << Scientists[sci-1].getName() << endl;

        s.push_back(Scientists[sci-1]);
        sc.push_back(sci);


        cout << "Would you like to add another scientist (Y/N)?" << endl;
        cin >> YoN1;
        count++;
    }

    count = 0;
    cout << "List of Computers:" << endl;
    vector<Computer> Computers = _serviceComp.getComputers();
    displayListOfComputers(Computers);
    string YoN2 = "y";

    while(YoN2 == "y" || YoN2 == "Y" || YoN2 == "yes" || YoN2 == "Yes")
    {
        cout << endl;
        cout << "Pick computers you want to relate to that/those scientist/s (their IDs): ";

        cin >> com;

        if(count == 0)
        {
            while(com > Computers.size() || com < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                cin >> com;
            }
        }

        else
        {
            while(!_serviceGen.validRelation(com, co) || com > Computers.size() || com < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                cin >> com;
            }
        }

        cout << "You picked " << Computers[com-1].getName() << endl;
        c.push_back(Computers[com-1]);
        co.push_back(com);

        cout << "Would you like to add another computer? ";
        cin >> YoN2;
        count++;
    }

    for (unsigned int i = 0; i < s.size(); i++)
    {
        for (unsigned int j = 0; j < c.size(); j++)
        {
            _serviceGen.link(s[i].getId(), c[j].getId());
        }
    }
}

void ConsoleUI::listRelation()
{
    vector<int>ScientistID = _serviceSci.allScientistID ();
    vector<int>ComputerID = _serviceComp.allComputerID ();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector <Scientist> lengthScientist;
    vector<Scientist> tempSci;

    for (unsigned int i = 0 ; i < ComputerID.size(); i++)
    {
        for (unsigned int k = 0; k < Computers.size(); k++)
        {
            if(ComputerID[i] == Computers[k].getId())
            {
                lengthComputer.push_back(Computers[k]);
                break;
            }
        }
    }

    for (unsigned int i = 0 ; i < ScientistID.size(); i++)
    {
        for (unsigned int k = 0; k < Scientists.size();k++)
        {
            if(ScientistID[i] == Scientists[k].getId())
            {
                lengthScientist.push_back(Scientists[k]);
            }
        }
    }
    clearScreen();
    cout << "No." << "\t";
    cout << setw(_serviceSci.lengthOfLongestName(lengthScientist)) << left;
    cout << "ScientistID" << "\t\t";
    cout << "ComputerID" << " \t\t";

    cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << i + 1 << ". | " << "\t";
        cout << setw(_serviceSci.lengthOfLongestName(lengthScientist)) << left;
        cout << lengthScientist[i].getName();
        cout << "\t | \t";
        cout << lengthComputer[i].getName();
        cout << endl;
    }
    cout << endl;
}


void ConsoleUI::editSci()
{
    string nameOf;
    string variable;

    vector<Scientist> Scientist = _serviceSci.getScientists();
    displayListOfScientists(Scientist);

    cout << "Which Scientist would you like to edit? " << endl << endl << "=> ";

    std::getline(cin, nameOf);
    std::getline(cin,nameOf);
    cout << endl;

    while(!_serviceSci.validCommand(variable))
    {
        cout << "Which element would you like to edit?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Sex" << endl;
        cout << "3. Birth" << endl;
        cout << "4. Death" << endl << endl << "=> ";

        cin >> variable;

        if(variable == "name" || variable == "Name" || variable == "1")
        {
            string newName;
            cout << endl << "What would you like to change the name too? " << endl << endl << "=> ";
            std::getline(cin, newName);
            std::getline(cin,newName);
            _serviceSci.editScientistString(nameOf,variable,newName);

        }
        else if(variable == "sex" || variable == "Sex" || variable == "2")
        {
            string newSex;
            cout << endl << "What would you like to change the sex too? " << endl << endl << "=> ";
            std::getline(cin, newSex);
            std::getline(cin,newSex);
            while((!_serviceSci.validSex(newSex)))
            {
                  cout << "Not valid!" << endl;
                  cout << endl << "What would you like to change the sex too? " << endl << endl << "=> ";
                  std::getline(cin, newSex);
            }
            newSex = _serviceSci.mOrF(newSex);
            _serviceSci.editScientistString(nameOf,variable,newSex);
        }
        else if(variable == "birth" || variable == "Birth" || variable == "3")
        {
            int newBirth;
            string strNewBirth;
            cout << endl << "What would you like to change the birth too? " << endl << endl << "=> ";
            getline(cin, strNewBirth);
            getline(cin, strNewBirth);
            while(!_serviceSci.validYear(strNewBirth))
            {
                cout << "Not valid!" << endl;
                cout << endl << "What would you like to change the birth too? " << endl << endl << "=> ";
                getline(cin, strNewBirth);
            }
            newBirth = atoi(strNewBirth.c_str());
            _serviceSci.editScientistInt(nameOf,variable,newBirth);
        }
        else if(variable == "death" || variable == "Death" || variable == "4")
        {
            int newDeath;
            cout << endl << "What would you like to change the death too? " << endl << endl << "=> ";
            cin >> newDeath;
            _serviceSci.editScientistInt(nameOf,variable,newDeath);
        }
        else
        {
            clearScreen();
            cout << "Invalid edit!" << endl << endl;
        }
    }
}
void ConsoleUI::editComp()
{
    string nameOf;
    string variable;

    vector <Computer> Computer = _serviceComp.getComputers();
    displayListOfComputers(Computer);

    cout << "Which Computer would you like to edit? " << endl << endl << "=> ";
    std::getline(cin, nameOf);
    std::getline(cin,nameOf);
    cout << endl;

    while(!_serviceComp.validCommand(variable))
    {
        cout << "What would you like to edit?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Type" << endl;
        cout << "4. Built" << endl << endl << "=> ";

        cin >> variable;

        if( variable == "name" || variable == "Name" || variable == "1")
        {
            if(variable == "1")
            {
                variable = "name";
            }
            string newName;
            cout << endl << "What would you like to change the name too? " << endl << endl << "=> ";
            std::getline(cin, newName);
            std::getline(cin,newName);
            _serviceComp.editComputerString(nameOf,variable,newName);
        }
        else if(variable == "year" || variable == "Year" || variable == "2")
        {
            if(variable == "2")
            {
                variable = "year";
            }
            int newYear;
            cout << endl << "What would you like to change the year too? " << endl << endl << "=> ";
            cin >> newYear;
            _serviceComp.editComputerInt(nameOf,variable,newYear);
        }
        else if(variable == "type" || variable == "Type" || variable == "3")
        {
            if(variable == "3")
            {
                variable = "type";
            }
            string newType;
            cout << endl << "What would you like to change the type too? " << endl << endl << "=> ";
            std::getline(cin, newType);
            std::getline(cin, newType);
            _serviceComp.editComputerString(nameOf,variable,newType);
        }
        else if(variable == "built" || variable == "Built" || variable == "4")
        {
            if(variable == "4")
            {
                variable = "built";
            }
            string newBuilt;
            cout << endl << "What would you like to change the built too? " << endl << endl << "=> ";
            std::getline(cin, newBuilt);
            std::getline(cin,newBuilt);
            _serviceComp.editComputerString(nameOf,variable,newBuilt);
        }
        else
        {
            clearScreen();
            cout << "Invalid edit!" << endl << endl;
        }
    }
}

/**
 * @brief Removes a scientist from the list
 */
void ConsoleUI::removeSci ()
{
    bool exist;
    unsigned int temp;
    string strTemp;
    string removePerson;
    string insert;
    int idOf;
    listSci();

    vector <Scientist> checkIfreal = _serviceSci.getScientists();
    do
    {

        exist = true;
        cout << "Which No. Scientist would you like to remove?? " << endl << endl << "=> ";
        cin >> strTemp;
        if (_serviceSci.validYear(strTemp))
        {
            temp = atoi(strTemp.c_str());
            if (temp > 0 && temp <= checkIfreal.size())
            {
                exist = true;
            }
            else
            {
                exist = false;
                clearScreen();
                cout << "Invalid number! " << endl;
            }

        }
        else
        {
           cout << "Invalid number! " << endl;
           removeSci();
        }

    } while (!exist);

    temp = temp - 1;
        cout << endl << "Remove: " << checkIfreal [temp].getName () << " " <<  checkIfreal [temp].getSex() << " " <<  checkIfreal [temp].getBirth() << " " << checkIfreal [temp].getDeath() << " ?" << endl;
        cout << "(Y/N) ";
        cin >> removePerson;

        while(removePerson != "Y" && removePerson != "y" && removePerson != "n" && removePerson != "N")
        {
            cout << "Invalid input!" << endl;
            cout << "Type either Y or N: ";
            cin >> removePerson;
        }
        if(removePerson == "y" || removePerson == "Y")
        {
            idOf = checkIfreal[temp].getId ();
            _serviceSci.removeScientist (idOf);
            cout << endl << "Scientist removed " << endl << endl;
        }
        else if (removePerson == "n" || removePerson == "N")
        {
            cout << "Scientist not removed " << endl;
        }
}
//komment below helgi
void ConsoleUI::removeEverySci()
{
    clearScreen();
    string choice;
    cout << "Are you absolutely sure?  (Y/N)" << endl;
    cin >> choice;
    clearScreen();

    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N")
    {
        cout << "Invalid input!" << endl;
        cout << "Type either Y or N: ";
        cin >> choice;
        clearScreen();
    }
    if (choice == "y" || choice == "Y")
    {
        _serviceSci.removeEveryscientist();
        clearScreen();
        cout << "Everybody has been removed! " << endl << endl << endl << endl;
    }
    else if (choice == "n" || choice == "N")
    {
        cout << "Nobody has been removed! " << endl << endl;

    }
}


void ConsoleUI::removeComp()
{
    bool exist;
    unsigned int temp;
    string removePerson;
    string insert;
    string strTemp;
    int idOf;
    listComp();
    vector <Computer> checkIfreal = _serviceComp.getComputers();
    do
    {
        exist = true;
        cout << "Which No. Computer would you like to remove?? " << endl << endl << "=> ";
        cin >> strTemp;
        if (_serviceSci.validYear(strTemp))
        {
            temp = atoi(strTemp.c_str());
            if (temp > 0 && temp <= checkIfreal.size())
            {
                exist = true;
            }
            else
            {
                exist = false;
                clearScreen();
                cout << "Invalid number! " << endl;
            }

        }
        else
        {
           cout << "Invalid number! " << endl;
           run();
        }

    } while (!exist);

    temp = temp - 1;
        cout << endl << "Remove: " << checkIfreal [temp].getName () << " " <<  checkIfreal [temp].getBuildYear() << " " <<  checkIfreal [temp].getCompType() << " ?" << endl;
        cout << "(Y/N) ";
        cin >> removePerson;

        while(removePerson != "Y" && removePerson != "y" && removePerson != "n" && removePerson != "N")
        {
            cout << "Invalid input!" << endl;
            cout << "Type either Y or N: ";
            cin >> removePerson;
        }
        if(removePerson == "y" || removePerson == "Y")
        {
            idOf = checkIfreal[temp].getId ();
            _serviceComp.removeComputer(idOf);
            cout << endl << "Computer removed " << endl << endl;
        }
        else if (removePerson == "n" || removePerson == "N")
        {
            cout << "Computer not removed " << endl;
        }
}

/**
 * @brief This is the function that's called when the user selects the sort command.
 * It sorts the list of scientists by either Name, Sex, Birth or Death. Depending
 * the the command the user selects.
 */


void ConsoleUI::sortSci()
{
    clearScreen();
    string command;
    while(!_serviceSci.validCommand(command))
    {
        cout << "What would you like to sort it by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Sex" << endl;
        cout << "3. Birth" << endl;
        cout << "4. Death" << endl << endl << "=> ";

        cin >> command;

        if(command == "name" || command == "Name" || command == "1")
        {
            vector<Scientist> Scientist = _serviceSci.sortByName();
            displayListOfScientists(Scientist);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            vector<Scientist> Scientist = _serviceSci.sortBySex();
            displayListOfScientists(Scientist);
        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            vector<Scientist> Scientist = _serviceSci.sortByBirth();
            displayListOfScientists(Scientist);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            vector<Scientist> Scientist = _serviceSci.sortByDeath();
            displayListOfScientists(Scientist);
        }
        else
        {
            clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}
void ConsoleUI::sortComp()
{
    clearScreen();
    string command;
    while(!_serviceComp.validCommand(command))
    {
        cout << "What would you like to sort it by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Type" << endl;
        cout << "4. Built" << endl << endl << "=> ";

        cin >> command;

        if(command == "name" || command == "Name" || command == "1")
        {
            vector<Computer> Computer = _serviceComp.sortByName();
            displayListOfComputers(Computer);
        }
        else if(command == "year" || command == "Year" || command == "2")
        {
            vector<Computer> Computer = _serviceComp.sortByBuildYear();
            displayListOfComputers(Computer);
        }
        else if(command == "type" || command == "Type" || command == "3")
        {
            vector<Computer> Computer = _serviceComp.sortByCompType();
            displayListOfComputers(Computer);
        }
        else if(command == "built" || command == "Built" || command == "4")
        {
            vector<Computer> Computer = _serviceComp.sortBywasBuilt();
            displayListOfComputers(Computer);
        }
        else
        {
            clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}

/**
 * @brief This function works exactly the same as the function the sortSci() function but
 * reverses the sorting. It can sort by either Name, Sex, Birth and Death.
 */
void ConsoleUI::reversedSortSci()
{
    clearScreen();
    string command;
    while(!_serviceSci.validCommand(command))
    {
        cout << "What would you like to reverse sort it by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Sex" << endl;
        cout << "3. Birth" << endl;
        cout << "4. Death" << endl << endl << "=> ";
        cin >> command;

        if(command == "name" || command == "Name" || command == "1")
        {
            vector<Scientist> Scientist = _serviceSci.sortByNameReverse();
            displayListOfScientists(Scientist);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            vector<Scientist> Scientist = _serviceSci.sortBySexReverse();
            displayListOfScientists(Scientist);
        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            vector<Scientist> Scientist = _serviceSci.sortByBirthReverse();
            displayListOfScientists(Scientist);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            vector<Scientist> Scientist = _serviceSci.sortByDeathReverse();
            displayListOfScientists(Scientist);
        }
        else
        {
            clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}


void ConsoleUI::reversedSortComp()
{
    clearScreen();
    string command;
    while(!_serviceComp.validCommand(command))
    {
        cout << "What would you like to sort it by?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Year" << endl;
        cout << "3. Type" << endl;
        cout << "4. Built" << endl << endl << "=> ";

        cin >> command;

        if(command == "name" || command == "Name" || command == "1")
        {
            vector<Computer> Computer = _serviceComp.sortByNameReverse();
            displayListOfComputers(Computer);
        }
        else if(command == "year" || command == "Year" || command == "2")
        {
            vector<Computer> Computer = _serviceComp.sortByBuildYearReverse();
            displayListOfComputers(Computer);
        }
        else if(command == "type" || command == "Type" || command == "3")
        {
            vector<Computer> Computer = _serviceComp.sortByCompTypeReverse();
            displayListOfComputers(Computer);
        }
        else if(command == "built" || command == "Built" || command == "4")
        {
            vector<Computer> Computer = _serviceComp.sortBywasBuiltReverse();
            displayListOfComputers(Computer);
        }
        else
        {
            clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}

/**
 * @brief This function search the list of scientists and you can choose to sort by either
 * Name, Sex, Birth and Death.
 */
void ConsoleUI::searchScientistList ()
{
    clearScreen();
    string command;
    while(!_serviceSci.validCommand(command))
    {
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
            vector<Scientist> names = _serviceSci.searchName(nameOf);
            validateSearch(names);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            clearScreen();
            string sexOf;
            cout << "Which sex would you like to search for? " << endl << endl << "=> ";
            cin >> sexOf;
            sexOf = _serviceSci.mOrF(sexOf);
            vector<Scientist> sex = _serviceSci.searchSex (sexOf);
            validateSearch(sex);

        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            clearScreen();
            int birthOf;
            string operatorOf;
            cout << "Which year of birth would you like to search for? " << endl << endl << "=> ";
            cin >> birthOf;
            clearScreen();
            cout << "Would you like to choose greater, less or equal ";
            cin >> operatorOf;
            vector<Scientist> birth = _serviceSci.searchBirth (operatorOf,birthOf);
            validateSearch(birth);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            clearScreen();
            int deathOf;
            string operatorOf;
            cout << "Which year of death would you like to serach for? " << endl << endl << "=> ";
            cin >> deathOf;
            cout << "Would you like to choose greate, less or equal ";
            cin >> operatorOf;
            vector<Scientist> death =_serviceSci.searchDeath(operatorOf,deathOf);
            validateSearch(death);
        }
        else
        {
            clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    }
}
void ConsoleUI::searchComputerList()
{
    clearScreen();
    string command;
    while(!_serviceSci.validCommand(command))
    {
        cout << "By what would you like to search for? " << endl;
        cout << "1. Name" << endl;
        cout << "2. Build year" << endl;
        cout << "3. Computer type" << endl;
        cout << "4. If it was built" << endl << endl;
        cout << "=> ";
        cin >> command;


        if(command == "name" || command == "Name" || command == "1")
        {
            clearScreen();
            string nameOf;
            cout << "Which name would you like to search for? " << endl << endl << "=> ";
            std::getline(cin, nameOf);
            std::getline(cin, nameOf);
            vector<Computer> name = _serviceComp.searchName(nameOf);
            validateSearch(name);
        }
        else if(command == "build year" || command == "Build year" || command == "Year" || command == "year" || command == "2")
        {
            clearScreen();
            int yearOf;
            string operatorOf;
            cout << "What build year would you like to search for? " << endl << endl << "=> ";
            cin >> yearOf;
            clearScreen();
            cout << "Would you like to choose greater, less or equal ";
            cin >> operatorOf;
            vector<Computer> year = _serviceComp.searchYear(operatorOf,yearOf);
            validateSearch(year);

        }
        else if(command == "type" || command == "Type" || command == "Computer type" || command == "computer type" || command == "3")
        {
            clearScreen();
            string typeOf;
            cout << "Which type would you like to search for? " << endl << endl << "=> ";
            cin >> typeOf;
            clearScreen();
            vector<Computer> types = _serviceComp.searchType(typeOf);
            validateSearch(types);
        }
        else if(command == "was built" || command == "Was built" || command == "built" || command == "Built" || command == "4")
        {
            clearScreen();
            string builtOf;
            string operatorOf;
            cout << "Which would you like to search for (Y/N)? " << endl << endl << "=> ";
            cin >> builtOf;
            vector<Computer> built =_serviceComp.searchwasBuilt(builtOf, operatorOf);
            validateSearch(built);
        }
        else
        {
            clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    }
}

/**
 * @brief This function displays the list of scientists and is called when the user
 * calls for the list option the menu.
 * @param vector Scientists.
 */
void ConsoleUI::displayListOfScientists (vector<Scientist> Scientist)
{
    clearScreen();
    cout << "No." << "\t";
    cout << "Name" << "\t\t";
    cout << setw(_serviceSci.lengthOfLongestName(Scientist)-17) << left;
    cout << "Sex" << " \t\t";
    cout << "Birth" << "\t\t";
    cout << "Death" << "\t\t";
    cout << "Citation" << "\t\t" << endl;

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


        cout << i + 1<< ". | ";
        cout << setw(_serviceSci.lengthOfLongestName(Scientist)) << left;
        cout << Scientist [i].getName () << "\t | \t";
        cout << Scientist [i].getSex () << "\t | \t";
        cout << Scientist [i].getBirth () << "\t | \t";
        cout << Scientist [i].getDeath () << "\t | \t";
        cout << Scientist [i].getCitation () << "\t\t" << endl;
    }
    cout << endl;
}

void ConsoleUI::displayListOfComputers(vector<Computer> Computer)
{
    clearScreen();
    cout << "No." << "\t";
    cout << setw(_serviceComp.lengthOfLongestName(Computer)) << left;
    cout << "Name" << "\t\t";
    cout << "Year" << " \t\t";
    cout << setw(_serviceComp.lengthOfLongestType(Computer)) << left;
    cout << "Type" << "\t\t";
    cout << "Built" << "\t\t" << endl;

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
        cout << i + 1 << ". | " << "\t";
        cout << setw(_serviceComp.lengthOfLongestName(Computer)) << left;
        cout << Computer [i].getName () << "\t | \t";
        cout << Computer [i].getBuildYear () << "\t | \t";
        cout << setw(_serviceComp.lengthOfLongestType(Computer)) << left;
        cout << Computer [i].getCompType () << "\t | \t";
        cout << Computer [i].getWasBuilt () << "\t\t" << endl;
    }
    cout << endl;
}

/**
 * @brief plays a game with the user, guessing who owns the citation.
 */
void ConsoleUI::playGame(){

    clearScreen();

    vector<Scientist> Scientist = _serviceSci.getScientists();

    int r = rand() % (Scientist.size()) + 1;

    string guess;
    string quote = Scientist[r].getCitation();

    cout << "----------------------------------------------------------------" << endl;
    cout << "Let's play a little game, guess who owns the following citation!" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << quote << endl;
    cout << "Answer: ";
    getline (cin,guess);
    getline (cin,guess);
    cout << endl;

    if (guess == Scientist[r].getName())
    {
        cout << "You Guessed Correctly!!" << endl;
        score++;
        cout << "Your score is: " << score << endl;
        cout << endl;
    }
    else
    {
        cout << "Wrong answer!" << endl;
        cout << "The correct answer is: " << Scientist[r].getName() << endl;
        cout << endl;
    }
}

/**
 * @brief clears the screen to make the menu look clean and beautiful.
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
 * A function which returns true if the scientist is alive or false if the scientist
 * is dead.
 * @return: true/false.
 */
bool ConsoleUI::isPersonAlive()
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
 * Vector of Scientists.
 */
void ConsoleUI::validateSearch(vector<Scientist>search)
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
void ConsoleUI::validateSearch(vector<Computer>search)
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
bool ConsoleUI::askIfCitation()
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

bool ConsoleUI::askIfBuilt()
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

