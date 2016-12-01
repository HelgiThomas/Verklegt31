#include "data/dataaccess.h"

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
        outputfile << scientist.getDeath() << endl;
        outputfile << scientist.getCitation();
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
            string name;
            string sex;
            string citation;
            int birth;
            int death;


            std::getline(thefile, name);
            thefile >> sex >> birth >> death;
            std::getline(thefile, citation);
            std::getline(thefile, citation);

            pl.setName(name);
            pl.setSex(sex);
            pl.setBirth(birth);
            pl.setDeath(death);
            pl.setCitation(citation);

            sci.push_back(pl);

            #ifdef _WIN32
                thefile.ignore();
            #endif
        }
    }
    else
    {
        cout << "Error opening file!" << endl;
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
