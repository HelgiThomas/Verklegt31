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
    cout << setw(4) << right << "No."<< "  | ";
    cout << setw(16) << right << "ScientistID"<< "  | ";
    cout << setw(16) << right << "ComputerID" << endl;

    cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(4) << right << lengthScientist[i].getName() << "  | ";
        cout << setw(4) << right << " | ";
        cout << setw(4) << right << lengthComputer[i].getName() << endl;
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
    _util.clearScreen();
    cout << setw(4) << right << "No."<< "  | ";
    cout << setw(16) << right << "ScientistID"<< "  | ";
    cout << setw(16) << right << "ComputerID" << "  | " << endl;

    cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(4) << right << lengthScientist[i].getName() << "  | ";
        cout << setw(4) << right << " | ";
        cout << setw(4) << right << lengthComputer[i].getName() << endl;
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
                lengthScientist.push_back(Scientists[k]);
            }
        }
    }
    _util.clearScreen();
    cout << setw(4) << right << "No."<< "  | ";
    cout << setw(16) << right << "ScientistID"<< "  | ";
    cout << setw(16) << right << "ComputerID" << endl;

    cout << endl << "-----------------------------------------------------------------------------------------------------" << endl;
    for (unsigned int i = 0 ; i < lengthScientist.size(); i++)
    {
        cout << setw(4) << right << i + 1 << " | ";
        cout << setw(4) << right << lengthScientist[i].getName() << "  | ";
        cout << setw(4) << right << " | ";
        cout << setw(4) << right << lengthComputer[i].getName() << endl;
    }
    cout << endl;
}
