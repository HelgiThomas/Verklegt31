#include "dataaccess.h"

using namespace std;

DataAccess::DataAccess()
{

}

void DataAccess::readToFile(Scientist scientist)
{
    if (checkEntry (scientist))
    {
        cout << "An entry like that already exists!" << endl;
    }
    else
    {
        ifstream inputfile ("ComputerScientist.txt",ios::app);
        ofstream outputfile ("ComputerScientist.txt",ios::app);
        if(!(inputfile.std::istream::peek() == EOF))
        {
            outputfile << endl;
        }
        outputfile << scientist.getName() << endl;
        outputfile << scientist.getSex() << endl;
        outputfile << scientist.getBirth() << endl;
        outputfile << scientist.getDeath();
        outputfile.close();
      }

}

vector<Scientist> DataAccess::readFromFile()
{
    ifstream thefile;
    vector<Scientist> sci;
    thefile.open("ComputerScientist.txt");

    if (thefile.is_open())
    {
        while (!(thefile.eof()))
        {
            Scientist pl;

            std::getline(thefile, pl._name);
            thefile >> pl._sex >> pl._birth >> pl._death;
            sci.push_back(pl);

            #ifdef _WIN32
            thefile.ignore();
            #endif
        }
    }
    else
    {
        cout << "Error opening file!";
    }

    thefile.close ();
    return sci;
}

bool DataAccess::checkEntry(Scientist scientist)
{
    vector <Scientist> temp;
    temp = readFromFile();
    for (unsigned int i = 0 ; i < temp.size()-1; i++)
    {
        if (scientist.getName() == temp[i].getName() && scientist.getSex() == temp[i].getSex() &&
                scientist.getBirth() == temp[i].getBirth() && scientist.getDeath() == temp[i].getDeath())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}
