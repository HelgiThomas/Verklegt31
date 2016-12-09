#include "addui.h"

AddUI::AddUI()
{

}

/**
 * @brief This function is called when the user chooses the add command.
 * It asks the user to put in the correct information to add a new scientist.
 * Also handles errors if the user puts the wrong information into a certain field.
 */
void AddUI::addSci()
{
    _util.clearScreen();
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
    if(!_util.isPersonAlive())
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
    if(_util.askIfCitation())
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

    _util.clearScreen();
}

/**
 * @brief This function is called when the user chooses the add command.
 * It asks the user to put in the correct information to add a new computer.
 * Also handles errors if the user puts the wrong information into a certain field.
 */
void AddUI::addComp()
{
    _util.clearScreen();
    string name;
    string strBuiltYear;
    string compType;
    string wasBuilt;
    int builtYear;

    cout << "Name: ";
    std::getline(cin, name);
    std::getline(cin, name);

    name = _serviceSci.makeFirstLetterBig(name);

    string choice;
    cout << "Computer type: " << endl;
    cout << "1. Electronic " << endl;
    cout << "2. Mechanic" << endl;
    cout << "3. Transistor machine" << endl;
    cout << "4. Other" << endl << endl << "=>";
    cin >> choice;
    if(choice == "1" || choice == "electronic" || choice == "Electronic")
    {
        compType = "Electronic";
    }
    else if(choice == "2" || choice == "Mechanic" || choice == "mechanic")
    {
        compType = "Mechanic";
    }
    else if(choice == "3" || choice == "Transistor" || choice == "transistor")
    {
        compType = "Transistor machine";
    }
    else if(choice == "4" || choice == "Other" || choice == "other")
    {
        cout << "Write the type: " << endl;
        cin >> compType;
    }
    while(!_serviceSci.validName(compType))
    {
        cout << "Invalid input!" << endl;
        cout << "Write the type: " << endl;
        cin >> compType;
    }
    compType = _serviceSci.makeFirstLetterBig(compType);

    if(_util.askIfBuilt())
    {
        wasBuilt = "Yes";
    }
    else
    {
        wasBuilt = "No";
    }
    if(wasBuilt == "Yes")
    {
        cout << "Build year: ";
        cin >> strBuiltYear;
        while(_serviceComp.validYear(strBuiltYear) == false)
        {
            cout << "Invalid input!" << endl;
            cout << "Build year: ";
            cin >> strBuiltYear;
        }
    }
    else if(wasBuilt == "No")
    {
        strBuiltYear = "0";
    }

    builtYear = atoi(strBuiltYear.c_str());
    int id = 0;
    Computer newComputer (id, name, builtYear, compType, wasBuilt);
    _serviceComp.addComputer(newComputer);
    cout << "Computer added." << endl << endl;
    string input;
    cout << "Press Enter to continue...";
    getline(cin, input);

    _util.clearScreen();
}

/**
 * @brief This function is called when the user chooses the add command.
 * It asks the user to put in the correct information to add a new relation between computer/s and scientist/s.
 * Also handles errors if the user puts the wrong information into a certain field.
 */
void AddUI::addRelation()
{
    _util.clearScreen();
    unsigned int sci;
    unsigned int com;
    string strSci;
    string strCom;
    vector<Scientist> s;
    vector<Computer> c;
    vector<int> sc;
    vector<int> co;
    int count = 0;


    cout << "List of Scientist:" << endl;
    vector<Scientist> Scientists = _serviceSci.getScientists();
    _util.displayListOfScientists(Scientists);

    string YoN1 = "y";
    while(YoN1 == "y" || YoN1 == "Y" || YoN1 == "yes" || YoN1 == "Yes")
    {
        cout << endl;
        cout << "Pick a scientist you would like to add a relation to (their ID): ";

        getline(cin, strSci);
        getline(cin, strSci);
        while(!_serviceSci.validNumber(strSci))
        {
            cout << "Invalid input!" << endl;
            cout << "Try again: ";
            getline(cin, strSci);
        }
        sci = atoi(strSci.c_str());
        if(count == 0)
        {
            while(sci > Scientists.size() || sci < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                getline(cin, strSci);
                sci = atoi(strSci.c_str());
            }
        }

        else
        {
            while(!_serviceGen.validRelation(sci, sc) || sci > Scientists.size() || sci < 1)
            {
                cout << "Invalid input!" << endl;
                cout << "Try again: ";
                getline(cin, strSci);
                sci = atoi(strSci.c_str());
            }
        }

        cout << endl;
        cout << "You picked " << Scientists[sci-1].getName() << endl;

        s.push_back(Scientists[sci-1]);
        sc.push_back(sci);
        if(sc.size() == Scientists.size())
        {
            break;
        }

        cout << "Would you like to add another scientist (Y/N)?" << endl;
        cin >> YoN1;
        count++;
    }

    count = 0;
    cout << "List of Computers:" << endl;
    vector<Computer> Computers = _serviceComp.getComputers();
    _util.displayListOfComputers(Computers);
    string YoN2 = "y";

    while(YoN2 == "y" || YoN2 == "Y" || YoN2 == "yes" || YoN2 == "Yes")
    {
        cout << endl;
        cout << "Pick a computer you want to relate to that/those scientist/s (their IDs): ";

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
        if(co.size() == Computers.size())
        {
            break;
        }
        cout << "Would you like to add another computer (Y/N)? ";
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

