#include "dataaccess.h"
#include <stdlib.h>


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

    thefile.open("Scientist.txt");

    vector<Scientist> sci;

    if (thefile.is_open())
    {
        string line;
        while(getline(thefile, line))
        {
            vector<string> inTheLine = splitLine(line);

            if (inTheLine.size() >= 3)
            {
                string name = inTheLine.at(0);
                string sex = inTheLine.at(1);
                int birth = convertStringToInt(inTheLine.at(3));

                if (inTheLine.size() == 3)
                {
                    sci.push_back(Scientist(name, sex, birth));
                }
                else
                {
                    int death = convertStringToInt(inTheLine.at(4));
                    sci.push_back(Scientist(name, sex, birth, death));
                }
            }
        }
    }

    thefile.close();

    return sci;
}

vector<string> DataAccess::splitLine(string line)
{
    vector<string> output;

    string cur = "";

    for (unsigned int i = 0; i < line.length(); i++)
    {
        char pos = line[i];
        const char del = ',';

        if (pos == del)
        {
            if (cur.length())
            {
                output.push_back(cur);
                cur = "";
            }
        }
        else
        {
            if (pos != '\n')
            {
                cur = cur + pos;
            }
        }
    }

    if (cur.length())
    {
        output.push_back(cur);
    }

    return output;
}

int DataAccess::convertStringToInt(string s)
{
    return atoi(s.c_str());
}
