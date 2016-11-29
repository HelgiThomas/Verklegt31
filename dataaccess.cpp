#include "dataaccess.h"

using namespace std;

DataAccess::DataAccess()
{

}

void DataAccess::readToFile(Scientist scientist)
{
    ofstream outputfile ("ComputerScientist.txt,ios::app");

    outputfile << scientist.getName() << ",";
    outputfile << scientist.getSex() << ",";
    outputfile << scientist.getBirth() << ",";
    outputfile << scientist.getDeath() << ",";
    cout << endl;
    outputfile.close();
}

vector<Scientist> DataAccess::readFromFile()
{
    ifstream thefile;

    thefile.open(filename.c_str());

    vector<Scientist> sci;

    if (thefile.is_open())
    {
        string line;
        while(getline(thefile, line))
        {
            vector<string> inTheLine = splitLine(line, ",");
        }
    }

}

vector<Scientist> DataAccess::splitLine(string line)
{
    vector<string> output;

    string cur = "";

    for (int i = 0; i < line.length(); i++)
    {
        char pos = line[i];

        if (pos == ",")
        {
            output.push_back(cur);
            cur = "";
        }
        else
        {
            if (pos != '\n')
            {
                cur = cur + pos;
            }
        }

        if (cur.length())
        {

        }
    }
}
