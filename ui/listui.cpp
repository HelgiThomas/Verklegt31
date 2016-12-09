#include "listui.h"

#include <iomanip>

ListUI::ListUI()
{

}

/**
 * @brief This function is called when the list command is selected by the user.
 * It lists out all the scientists in the order they were put into the program.
 */
void ListUI::listSci()
{
    vector<Scientist> Scientist = _serviceSci.getScientists();
    _util.displayListOfScientists(Scientist);
    cout << endl;
}

/**
 * @brief This function is called when the list command is selected by the user.
 * It lists out all the computers in the order they were put into the program.
 */
void ListUI::listComp()
{
    vector<Computer> Computer = _serviceComp.getComputers();
    _util.displayListOfComputers(Computer);
    cout << endl;
}

void ListUI::listAllRelations()
{
    vector<int>ScientistID = _serviceSci.allScientistID();
    vector<int>ComputerID = _serviceComp.allComputerID();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector<Scientist> lengthScientist;
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
    _util.clearScreen();
    cout << setw(4) << right << "No."<< " | ";
    cout << setw(32) << right << "ScientistID"<< "  | ";
    cout << setw(32) << right << "ComputerID" << endl;

    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(32) << right << lengthScientist[i].getName() << " | ";
        cout << setw(32) << right << lengthComputer[i].getName() << endl;
    }
    cout << endl;
}

void ListUI::listCompRelation(string Comp)
{
    vector<int>ScientistID = _serviceSci.allScientistID();
    vector<int>ComputerID = _serviceComp.allComputerID();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector<Scientist> lengthScientist;
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

    vector<Scientist> s;
    for (unsigned int i = 0; i < Computers.size(); i++)
    {
        if (lengthComputer[i].getName() == Comp)
        {
            s.push_back(lengthScientist[i]);
        }
    }

    _util.clearScreen();
    cout << setw(4) << right << "No."<< " | ";
    cout << setw(32) << right << "ScientistID"<< "  | ";
    cout << setw(32) << right << "ComputerID" << "  | " << endl;

    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < s.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(32) << right << Comp << " | ";
        cout << setw(32) << right << s[i].getName() << endl;
    }
    cout << endl;
}

void ListUI::listSciRelation(string Sci)
{
    vector<int>ScientistID = _serviceSci.allScientistID();
    vector<int>ComputerID = _serviceComp.allComputerID();

    vector<Computer> Computers = _serviceComp.getComputers();
    vector<Scientist> Scientists = _serviceSci.getScientists();
    vector<Computer> lengthComputer;
    vector<Scientist> lengthScientist;
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
                if (Sci == Scientists[k].getName())
                {
                    lengthScientist.push_back(Scientists[k]);
                }
            }
        }
    }

    vector<Computer> c;
    for (unsigned int i = 0; i < Scientists.size(); i++)
    {
        if (lengthScientist[i].getName() == Sci)
        {
            c.push_back(lengthComputer[i]);
        }
    }

    _util.clearScreen();
    cout << setw(4) << right << "No."<< " | ";
    cout << setw(32) << right << "ScientistID"<< "  | ";
    cout << setw(32) << right << "ComputerID" << endl;

    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(32) << right << Sci << " | ";
        cout << setw(32) << right << c[i].getName() << endl;
    }
    cout << endl;
}
