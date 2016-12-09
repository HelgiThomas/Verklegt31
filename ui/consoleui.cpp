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
}

/**
 * @brief This is the first menu function, which the user chooses a command
 * to select between the various functions we've got in our program.
 */
void ConsoleUI::run()
{
    _util.clearScreen();
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
            consoleAdd();
        }
        else if (command == "Remove" || command == "remove" || command == "2")
        {
            consoleRemove();
        }
        else if (command == "list" || command == "List" || command == "3")
        {
            consoleList();
        }
        else if (command == "edit" || command == "Edit" || command == "4")
        {
            consoleEdit();
        }
        else if (command == "sort" || command == "Sort" || command == "5")
        {
            consoleSort();
        }
        else if (command == "reversed" || command == "Reversed" || command == "reversed sort" || command == "Reversed sort"|| command == "6")
        {
            consoleRevSort();
        }
        else if (command == "search" || command == "Search" || command == "7")
        {
            consoleSearch();
        }
        else if(command == "game" || command == "Game" || command == "8")
        {
            consoleGame();
        }
        else if (command == "quit" || command == "Quit" || command == "9")
        {
            exit(1);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    } while (1 < 2);
}

/**
 * @brief ConsoleUI::consoleAdd, interface for adding into the program.
 */
void ConsoleUI::consoleAdd()
{
    _util.clearScreen ();
    string choice;
    cout << "What would you like to add? " << endl;
    cout << "1. Scientist" << endl;
    cout << "2. Computer" << endl;
    cout << "3. Relation" << endl;
    cout << "4. Back" << endl << endl << "=> ";
    cin >> choice;
    if (choice == "scientist" || choice == "Scientist" || choice == "1")
    {
        _add.addSci();
    }
    else if(choice == "computer" || choice == "Computer" || choice == "2")
    {
        _add.addComp();
    }
    else if(choice == "relation" || choice == "Relation" || choice == "3")
    {
        _add.addRelation();
    }
    else if(choice == "back" || choice == "Back" || choice == "4")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleRemove, interface for removing something from the program.
 */
void ConsoleUI::consoleRemove()
{
    _util.clearScreen();
    string choice;
    cout << "What would you like to remove? " << endl;
    cout << "1. Scientist" << endl;
    cout << "2. Computer" << endl;
    cout << "3. Relation" << endl;
    cout << "4. Back" << endl << endl << "=> ";
    cin >> choice;
    if (choice == "scientist" || choice == "Scientist" || choice == "1")
    {
        _util.clearScreen();
        string removeChoice;
        cout << "Do you want to remove?" << endl;
        cout << "1. One scientist" << endl;
        cout << "2. All scientists" << endl;
        cout << "3. Back" << endl << endl << "=>";
        cin >> removeChoice;
        if(removeChoice == "one" || removeChoice == "One" || removeChoice == "1")
        {
            _remove.removeSci();
        }
        else if(removeChoice == "all" || removeChoice == "All" || removeChoice == "2")
        {
            _remove.removeEverySci();
        }
        else if(removeChoice == "back" || removeChoice == "Back" || removeChoice == "3")
        {
            consoleRemove();
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    }
    else if(choice == "computer" || choice == "Computer" || choice == "2")
    {
        _util.clearScreen();
        string removeChoice;
        cout << "Do you want to remove?" << endl;
        cout << "1. One computer" << endl;
        cout << "2. All computers" << endl;
        cout << "3. Back" << endl << endl << "=>";
        cin >> removeChoice;
        if(removeChoice == "one" || removeChoice == "One" || removeChoice == "1")
        {
            _remove.removeComp();
        }
        else if(removeChoice == "all" || removeChoice == "All" || removeChoice == "2")
        {
            _remove.removeEveryComp();
        }
        else if(removeChoice == "back" || removeChoice == "Back" || removeChoice == "3")
        {
            consoleRemove();
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid command!" << endl << endl;
        }

    }
    else if(choice == "relation" || choice == "Relation" || choice == "3")
    {
        _remove.removeRelation();
    }
    else if(choice == "back" || choice == "Back" || choice == "4")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }

}

/**
 * @brief ConsoleUI::consoleList, interface for listing the program.
 */
void ConsoleUI::consoleList()
{
    _util.clearScreen();
    string choice;
    cout << "What would you like to list? " << endl;
    cout << "1. Scientists" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Relations" << endl;
    cout << "4. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "scientists" || choice == "Scientists" || choice == "1")
    {
        _list.listSci();
    }
    else if(choice == "computers" || choice == "Computers" || choice == "2")
    {
        _list.listComp();
    }
    else if(choice == "relations" || choice == "Relations" || choice == "3")
    {
        listRelation();
    }
    else if(choice == "back" || choice == "Back" || choice == "4")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief This function is called when the list command is selected by the user.
 * It lists out all the relations between scientists and computers
 * in the order they were put into the program.
 */
void ConsoleUI::listRelation()
{
    _util.clearScreen();
    string choice;
    cout << "What would you like to list? " << endl;
    cout << "1. All relations" << endl;
    cout << "2. Single scientist relation" << endl;
    cout << "3. Single computer relation" << endl;
    cout << "4. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "all" || choice == "All" || choice == "1")
    {
        _list.listAllRelations();
    }
    else if(choice == "scientist" || choice == "Scientists" || choice == "2")
    {
        vector<Scientist> Scientists = _serviceSci.getScientists();
        _util.displayListOfScientists(Scientists);
        string Sci;
        cout << "Which scientist do you want to see (Write in the correct name)? ";
        cin >> Sci;

        _list.listSciRelation(Sci);
    }
    else if(choice == "computer" || choice == "Computer" || choice == "3")
    {
        vector<Computer> Computers = _serviceComp.getComputers();
        _util.displayListOfComputers(Computers);
        string Comp;
        cout << "Which computer do you want to see (Write in the correct name)? ";
        cin >> Comp;

        _list.listCompRelation(Comp);
    }
    else if(choice == "back" || choice == "Back" || choice == "4")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleEdit, interface for editing the program.
 */
void ConsoleUI::consoleEdit()
{
    _util.clearScreen ();
    string choice;
    cout << "What would you like to edit? " << endl;
    cout << "1. Scientist" << endl;
    cout << "2. Computer" << endl;
    cout << "3. Relation" << endl;
    cout << "4. Back" << endl << endl << "=> ";
    cin >> choice;
    if (choice == "scientist" || choice == "Scientist" || choice == "1")
    {
        _edit.editSci();
    }
    else if(choice == "computer" || choice == "Computer" || choice == "2")
    {
        _edit.editComp();
    }
    else if(choice == "relation" || choice == "Relation" || choice == "3")
    {
        _edit.editRelation();
    }
    else if(choice == "back" || choice == "Back" || choice == "4")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleSort, interface for sorting the program.
 */
void ConsoleUI::consoleSort()
{
    _util.clearScreen();
    string choice;
    cout << "What would you like to sort? " << endl;
    cout << "1. Scientists" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "scientists" || choice == "Scientists" || choice == "1")
    {
        _sort.sortSci();
    }
    else if(choice == "computers" || choice == "Computers" || choice == "2")
    {
        _sort.sortComp();
    }
    else if(choice == "back" || choice == "Back" || choice == "3")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleRevSort, interface for reversed sorting the program.
 */
void ConsoleUI::consoleRevSort()
{
    _util.clearScreen();
    string choice;
    cout << "What would you like to reverse sort? " << endl;
    cout << "1. Scientists" << endl;
    cout << "2. Computers" << endl;
    cout << "3. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "scientists" || choice == "Scientists" || choice == "1")
    {
        _sort.reversedSortSci();
    }
    else if(choice == "computers" || choice == "Computers" || choice == "2")
    {
        _sort.reversedSortComp();
    }
    else if(choice == "back" || choice == "Back" || choice == "3")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleSearch, interface for searching in the program.
 */
void ConsoleUI::consoleSearch()
{
    _util.clearScreen();
    string choice;
    cout << "What do you want to search for? " << endl;
    cout << "1. Scientist" << endl;
    cout << "2. Computer" << endl;
    cout << "3. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "scientist" || choice == "Scientist" || choice == "1")
    {
        _search.searchScientistList();
    }
    else if(choice == "computer" || choice == "Computer" || choice == "2")
    {
        _search.searchComputerList();
    }
    else if(choice == "back" || choice == "Back" || choice == "3")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}

/**
 * @brief ConsoleUI::consoleGame, interface for the game in the program.
 */
void ConsoleUI::consoleGame()
{
    _util.clearScreen();
    string choice;
    cout << "Which game do you want to play? " << endl;
    cout << "1. Citation Game" << endl;
    cout << "2. Computer-Scientist Relation" << endl;
    cout << "3. Back" << endl << endl << "=> ";
    cin >> choice;
    if(choice == "citation" || choice == "Citation" || choice == "1")
    {
        _game.playCitation();
    }
    else if(choice == "relation" || choice == "Relation" || choice == "2")
    {
        _game.playRelation();
    }
    else if(choice == "back" || choice == "Back" || choice == "3")
    {
        _util.clearScreen();
        run();
    }
    else
    {
        _util.clearScreen();
        cout << "Invalid command!" << endl << endl;
    }
}
