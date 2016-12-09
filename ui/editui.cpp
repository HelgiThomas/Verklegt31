#include "editui.h"

EditUI::EditUI()
{

}

/**
 * @brief This function is called when the edit command is selected by the user.
 * It gives you the option to edit any input the user put in about the scientist.
 */
void EditUI::editSci()
{
    string nameOf;
    string variable;

    vector<Scientist> Scientist = _serviceSci.getScientists();
    _util.displayListOfScientists(Scientist);

    cout << "Which scientist would you like to edit? (Write in the correct name) " << endl << endl << "=> ";

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
            int death;
            int newBirth;
            cout << endl << "What would you like to change the birth too? " << endl << endl << "=> ";
            cin >> newBirth;


            for (unsigned int i = 0; i < Scientist.size(); i++)
            {
                if(Scientist[i].getName() == nameOf)
                {
                    death = Scientist[i].getDeath();
                    while(newBirth > death)
                    {
                        cout << "Invalid birth!" << endl << endl;
                        cout << "It's not possible to be born after you die!" << endl;
                        cout <<  "What would you like to change the birth too? " << endl << endl << "=> ";
                        cin >> newBirth;

                    }
                }
                _serviceSci.editScientistInt(nameOf,variable,newBirth);
                _util.clearScreen();
            }
        }
        else if(variable == "death" || variable == "Death" || variable == "4")
        {
            int birth;
            int newDeath;
            cout << endl << "What would you like to change the death too? " << endl << endl << "=> ";
            cin >> newDeath;


            for (unsigned int i = 0; i < Scientist.size(); i++)
            {
                if(Scientist[i].getName() == nameOf)
                {
                    birth = Scientist[i].getBirth();
                    while(newDeath < birth && newDeath != 0)
                    {

                        cout << "Invalid death!" << endl << endl;
                        cout << "It's not possible to die before you are born!" << endl;
                        cout <<  "What would you like to change the death too? " << endl << endl << "=> ";
                        cin >> newDeath;

                    }
                }
                _serviceSci.editScientistInt(nameOf,variable,newDeath);
                _util.clearScreen();
            }
        }
        else
        {
            _util.clearScreen();
            cout << "Invalid edit!" << endl << endl;
        }
    }
}

/**
 * @brief This function is called when the edit command is selected by the user.
 * It gives you the option to edit any input the user put in about the computer.
 */
void EditUI::editComp()
{
    string nameOf;
    string variable;

    vector <Computer> Computer = _serviceComp.getComputers();
    _util.displayListOfComputers(Computer);

    cout << "Which computer would you like to edit? " << endl << endl << "=> ";
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
            _util.clearScreen();
            cout << "Invalid edit!" << endl << endl;
        }
    }
}

/**
 * @brief This function is called when the edit command is selected by the user.
 * It gives you the option to edit any input the user put in about the relation.
 */
void EditUI::editRelation()
{
    vector <Computer> temp = _serviceComp.getComputers();
    vector <Scientist> temp1 = _serviceSci.getScientists();
    _util.clearScreen();
    int nrID , sciID, compID;
    _list.listAllRelations();
    cout << endl << "No. which relation would you like to edit? " << endl << endl << "=> ";
    cin >> nrID;

    _util.clearScreen();
    _util.displayListOfScientists(temp1);
    cout << endl << "No. which Scientist would you like to be the new one " << endl << endl << "=> ";
    cin >> sciID;

    _util.clearScreen();
    _util.displayListOfComputers(temp);
    cout << endl << "No. which Scientist would you like to be the new one " << endl << endl << "=> ";
    cin >> compID;

    _serviceGen.editRelation (nrID, sciID, compID);
}
