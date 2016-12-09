#include "removeui.h"

RemoveUI::RemoveUI()
{

}

/**
  * @brief This function is called when the remove command is selected.
  * It gives you the option to remove a relation from the list.
  * The relation will still exist in the database.
  */
void RemoveUI::removeRelation()
{
    _util.clearScreen();
    _list.listAllRelations();
    int nrID;

    cout << "Which relation would you like to remove? " << endl << endl << "=> ";
    cin >> nrID;

    _serviceGen.removeRelation(nrID);

}

/**
 * @brief This function is called when the remove command is selected.
 * It gives you the option to remove a scientist from the list.
 * The scientist will still exist in the database.
 */
void RemoveUI::removeSci ()
{
    bool exist;
    unsigned int temp;
    string strTemp;
    string removePerson;
    string insert;
    int idOf;
    _list.listSci();

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
                _util.clearScreen();
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

/**
 * @brief This function is called when the remove command is selected.
 * It gives you the option to remove all scientists from the list.
 * The scientists will still exist in the database.
 */
void RemoveUI::removeEverySci()
{
    _util.clearScreen();
    string choice;
    cout << "Are you absolutely sure?  (Y/N)" << endl;
    cin >> choice;
    _util.clearScreen();

    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N")
    {
        cout << "Invalid input!" << endl;
        cout << "Type either Y or N: ";
        cin >> choice;
        _util.clearScreen();
    }
    if (choice == "y" || choice == "Y")
    {
        _serviceSci.removeEveryscientist();
        _util.clearScreen();
        cout << "Everybody has been removed! " << endl << endl << endl << endl;
    }
    else if (choice == "n" || choice == "N")
    {
        cout << "Nobody has been removed! " << endl << endl;

    }
}

/**
 * @brief This function is called when the remove command is selected.
 * It gives you the option to remove all computers from the list.
 * The computers will still exist in the database.
 */
void RemoveUI::removeEveryComp()
{
    _util.clearScreen();
    string choice;
    cout << "Are you absolutely sure?  (Y/N)" << endl;
    cin >> choice;
    _util.clearScreen();

    while(choice != "Y" && choice != "y" && choice != "n" && choice != "N")
    {
        cout << "Invalid input!" << endl;
        cout << "Type either Y or N: ";
        cin >> choice;
        _util.clearScreen();
    }
    if (choice == "y" || choice == "Y")
    {
        _serviceComp.removeEverycomputer();
        _util.clearScreen();
        cout << "All computers have been removed! " << endl << endl << endl << endl;
    }
    else if (choice == "n" || choice == "N")
    {
        cout << "No computer has been removed! " << endl << endl;

    }
}

/**
 * @brief This function is called when the remove command is selected.
 * It gives you the option to remove a computer from the list.
 * The computer will still exist in the database.
 */
void RemoveUI::removeComp()
{
    bool exist;
    unsigned int temp;
    string removePerson;
    string insert;
    string strTemp;
    int idOf;
    _list.listComp();
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
                _util.clearScreen();
                cout << "Invalid number! " << endl;
            }

        }
        else
        {
            cout << "Invalid number! " << endl;
            //run();
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
