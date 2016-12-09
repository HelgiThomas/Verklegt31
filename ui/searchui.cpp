#include "searchui.h"

SearchUI::SearchUI()
{

}
/**
 * @brief This function searches the list of scientists and you can choose to search by either
 * name, sex, birth or death.
 */
void SearchUI::searchScientistList ()
{
    _util.clearScreen();
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
            _util.clearScreen();
            string nameOf;
            cout << "Which name would you like to search for? " << endl << endl << "=> ";
            std::getline(cin, nameOf);
            std::getline(cin, nameOf);
            vector<Scientist> names = _serviceSci.searchName(nameOf);
            _util.validateSearch(names);
        }
        else if(command == "sex" || command == "Sex" || command == "2")
        {
            _util.clearScreen();
            string sexOf;
            cout << "Which sex would you like to search for? " << endl << endl << "=> ";
            cin >> sexOf;
            sexOf = _serviceSci.mOrF(sexOf);
            vector<Scientist> sex = _serviceSci.searchSex (sexOf);
            _util.validateSearch(sex);

        }
        else if(command == "birth" || command == "Birth" || command == "3")
        {
            _util.clearScreen();
            int birthOf;
            string operatorOf;
            cout << "Which year of birth would you like to search for? " << endl << endl << "=> ";
            cin >> birthOf;
            _util.clearScreen();
            cout << "Would you like to choose greater, less or equal ";
            cin >> operatorOf;
            vector<Scientist> birth = _serviceSci.searchBirth (operatorOf,birthOf);
            _util.validateSearch(birth);
        }
        else if(command == "death" || command == "Death" || command == "4")
        {
            _util.clearScreen();
            int deathOf;
            string operatorOf;
            cout << "Which year of death would you like to serach for? " << endl << endl << "=> ";
            cin >> deathOf;
            cout << "Would you like to choose greate, less or equal ";
            cin >> operatorOf;
            vector<Scientist> death =_serviceSci.searchDeath(operatorOf,deathOf);
            _util.validateSearch(death);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    }
}

/**
 * @brief This function searches the list of computers and you can choose to search by either
 * name, build year, type or if it was built.
 */
void SearchUI::searchComputerList()
{
    _util.clearScreen();
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
            _util.clearScreen();
            string nameOf;
            cout << "Which name would you like to search for? " << endl << endl << "=> ";
            std::getline(cin, nameOf);
            std::getline(cin, nameOf);
            vector<Computer> name = _serviceComp.searchName(nameOf);
            _util.validateSearch(name);
        }
        else if(command == "build year" || command == "Build year" || command == "Year" || command == "year" || command == "2")
        {
            _util.clearScreen();
            int yearOf;
            string operatorOf;
            cout << "What build year would you like to search for? " << endl << endl << "=> ";
            cin >> yearOf;
            _util.clearScreen();
            cout << "Would you like to choose greater, less or equal ";
            cin >> operatorOf;
            vector<Computer> year = _serviceComp.searchYear(operatorOf,yearOf);
            _util.validateSearch(year);

        }
        else if(command == "type" || command == "Type" || command == "Computer type" || command == "computer type" || command == "3")
        {
            _util.clearScreen();
            string typeOf;
            cout << "Which type would you like to search for? " << endl << endl << "=> ";
            cin >> typeOf;
            _util.clearScreen();
            vector<Computer> types = _serviceComp.searchType(typeOf);
            _util.validateSearch(types);
        }
        else if(command == "was built" || command == "Was built" || command == "built" || command == "Built" || command == "4")
        {
            _util.clearScreen();
            string builtOf;
            string operatorOf;
            cout << "Which would you like to search for (Y/N)? " << endl << endl << "=> ";
            cin >> builtOf;
            vector<Computer> built =_serviceComp.searchwasBuilt(builtOf, operatorOf);
            _util.validateSearch(built);
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid command!" << endl << endl;
        }
    }
}
