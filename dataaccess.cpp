#include "dataaccess.h"

using namespace std;

DataAccess::DataAccess()
{

}

void DataAccess::readToFile(Scientist scientist)
{
    ofstream outputfile ("ComputerScientist.txt",ios::app);
    outputfile << scientist.getName() << endl;
    outputfile << scientist.getSex() << endl;
    outputfile << scientist.getBirth() << endl;
    outputfile << scientist.getDeath() << endl;
    outputfile.close();
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
                thefile >> pl._name >> pl._sex >> pl._birth >> pl._death;
                sci.push_back(pl);
            }
        }
    else
    {
        cout << "Error opening file!";
    }

    thefile.close ();
    return sci;

}
