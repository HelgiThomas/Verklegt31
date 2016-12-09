#include "sortui.h"

SortUI::SortUI()
{

}

/**
 * @brief This is the function that's called when the user selects the sort command.
 * It sorts the list of scientists by either Name, Sex, Birth or Death. Depending
 * the the command the user selects.
 */


void SortUI::sortSci()
{
    _util.clearScreen();
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
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            vector<Scientist> Scientist = _serviceSci.sortBySex();
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            vector<Scientist> Scientist = _serviceSci.sortByBirth();
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            vector<Scientist> Scientist = _serviceSci.sortByDeath();
            _util.displayListOfScientists(Scientist);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}
void SortUI::sortComp()
{
    _util.clearScreen();
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
            _util.displayListOfComputers(Computer);
        }
        else if(command == "year" || command == "Year" || command == "2")
        {
            vector<Computer> Computer = _serviceComp.sortByBuildYear();
            _util.displayListOfComputers(Computer);
        }
        else if(command == "type" || command == "Type" || command == "3")
        {
            vector<Computer> Computer = _serviceComp.sortByCompType();
            _util.displayListOfComputers(Computer);
        }
        else if(command == "built" || command == "Built" || command == "4")
        {
            vector<Computer> Computer = _serviceComp.sortBywasBuilt();
            _util.displayListOfComputers(Computer);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}

/**
 * @brief This function works exactly the same as the function the sortSci() function but
 * reverses the sorting. It can sort by either Name, Sex, Birth or Death.
 */
void SortUI::reversedSortSci()
{
    _util.clearScreen();
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
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            vector<Scientist> Scientist = _serviceSci.sortBySexReverse();
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            vector<Scientist> Scientist = _serviceSci.sortByBirthReverse();
            _util.displayListOfScientists(Scientist);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            vector<Scientist> Scientist = _serviceSci.sortByDeathReverse();
            _util.displayListOfScientists(Scientist);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}

/**
 * @brief This function works exactly the same as the function the sortComp() function but
 * reverses the sorting. It can sort by either Name, Year, Type or if it was built.
 */
void SortUI::reversedSortComp()
{
    _util.clearScreen();
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
            _util.displayListOfComputers(Computer);
        }
        else if(command == "year" || command == "Year" || command == "2")
        {
            vector<Computer> Computer = _serviceComp.sortByBuildYearReverse();
            _util.displayListOfComputers(Computer);
        }
        else if(command == "type" || command == "Type" || command == "3")
        {
            vector<Computer> Computer = _serviceComp.sortByCompTypeReverse();
            _util.displayListOfComputers(Computer);
        }
        else if(command == "built" || command == "Built" || command == "4")
        {
            vector<Computer> Computer = _serviceComp.sortBywasBuiltReverse();
            _util.displayListOfComputers(Computer);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid sort!" << endl << endl;
        }
    }
}
