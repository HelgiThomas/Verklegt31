#include "ui/consoleui.h"
#include "model/scientist.h"

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
            cout << "3. Back" << endl << endl << "=> ";
            cin >> choice;
            if (choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                addSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                addComp();
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
        else if (command == "Remove" || command == "remove" || command == "2")
        {
            clearScreen();
            string choice;
            cout << "What would you like to remove? " << endl;
            cout << "1. Person" << endl;
            cout << "2. Everyone" << endl;
            cout << "3. Back" << endl << endl << "=> ";
            cin >> choice;
            if (choice == "person" || choice == "Person" || choice == "1")
            {
                removeSci();
            }
            else if (choice == "everyone" || choice == "Everyone" || choice == "2")
            {
                 removeEverySci();
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
        else if (command == "list" || command == "List" || command == "3")
        {
            clearScreen();
            string choice;
            cout << "What would you like to list? " << endl;
            cout << "1. Scientist" << endl;
            cout << "2. Computer" << endl;
            cout << "3. Back" << endl << endl << "=> ";
            cin >> choice;
            if(choice == "scientist" || choice == "Scientist" || choice == "1")
            {
                listSci();
            }
            else if(choice == "computer" || choice == "Computer" || choice == "2")
            {
                listComp();
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
        else if (command == "edit" || command == "Edit" || command == "4")
        {

        }
        else if (command == "sort" || command == "Sort" || command == "5")
        {
            sortSci();
        }
        else if (command == "reversed" || command == "Reversed" || command == "reversed sort" || command == "Reversed sort"|| command == "6")
        {
            reversedSortSci();
        }
        else if (command == "search" || command == "Search" || command == "7")
        {
            searchList();
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
    vector <Scientist> Scientist = _serviceSci.getScientist();
    displayListOfScientists(Scientist);
    cout << endl;
}

void ConsoleUI::listComp()
{
    vector <Computer> Computer = _serviceComp.getComputer();
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

    //name = _serviceComp.makeFirstLetterBig(name);

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
 * @brief Removes a scientist from the list
 */
void ConsoleUI::removeSci ()
{
    bool exist = false;
    int temp;
    string removePerson;
    string insert;
    string nameOf;

    cout << "Which scientist would you like to remove? " << endl << endl << "=> ";;

    std::getline(cin, insert);
    std::getline(cin,insert);

    nameOf = _serviceSci.makeFirstLetterBig(insert);

    vector <Scientist> checkIfreal = _serviceSci.getScientist();
    for (unsigned int i = 0; i < checkIfreal.size(); i++)
    {
        if ((nameOf == checkIfreal[i].getName()))
        {
            exist = true;
            temp = i;
        }
    }

    if (exist == false)
    {
        cout << "There is no such scientist in the list! " << endl << endl;
    }

    else
    {
        cout << endl << "Reomve: " << checkIfreal [temp].getName () << " " <<  checkIfreal [temp].getSex() << " " <<  checkIfreal [temp].getBirth() << " " << checkIfreal [temp].getDeath() << " ?" << endl;
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
            _serviceSci.removeScientist (nameOf);
            cout << endl << "Scientist removed " << endl << endl;
        }
        else if (removePerson == "n" || removePerson == "N")
        {
            cout << "Scientist not removed " << endl;
        }
    }
}
//komment below helgi
void ConsoleUI::removeEverySci()
{
    clearScreen();
    string choice;
    cout << "Are you absolutely sure?  (Y/N)" << endl;
    cin >> choice;


    if (choice == "y" || choice == "Yes" || choice == "yes" || choice == "Yes")
    {
        _serviceSci.removeEveryscientist();
        clearScreen();
        cout << "Everybody has been removed " << endl << endl << endl << endl;
    }
    else
    {

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

/**
 * @brief This function search the list of scientists and you can choose to sort by either
 * Name, Sex, Birth and Death.
 */
void ConsoleUI::searchList ()
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
            vector<Scientist> names = _serviceSci.searchSex (sexOf);
            validateSearch(names);

        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            clearScreen();
            int birthOf;
            cout << "Which year of birth would you like to search for? " << endl << endl << "=> ";
            cin >> birthOf;
            vector<Scientist> names = _serviceSci.searchBirth (birthOf);
            validateSearch(names);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            clearScreen();
            int deathOf;
            cout << "Which date of death would you like to serach for? " << endl << endl << "=> ";
            cin >> deathOf;
            vector<Scientist> names =_serviceSci.searchDeath (deathOf);
            validateSearch(names);
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
    cout << setw(_serviceSci.lengthOfLongestName(Scientist)) << left;
    cout << "Name" << "\t\t";
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
    cout << setw(_serviceComp.lengthOfLongestName(Computer)) << left;
    cout << "Name" << "\t\t";
    cout << "Year" << " \t\t";
    cout << "Type" << "\t\t";
    cout << "Built" << "\t\t" << endl;

    for(int i = 0; i < (_serviceComp.lengthOfLongestName(Computer) + 50); i++)
    {
        cout << "-";
    }

    /*for(int i = 0; i < (_serviceComp.lengthOfLongestCitation(Computer) + 20); i++)
    {
        cout << "-";
    }*/
    cout << endl;

    for (unsigned int i = 0 ; i < Computer.size();i++)
    {

        cout << setw(_serviceComp.lengthOfLongestName(Computer)) << left;
        cout << Computer [i].getName () << "\t | \t";
        cout << Computer [i].getBuildYear () << "\t | \t";
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

    vector<Scientist> Scientist = _serviceSci.getScientist();

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

/**
 * @brief A function to validate if the list of scientists contains any names to display.
 * Vector of Scientists.
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
    cout << "Was the computer built? (Y/N)";

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
