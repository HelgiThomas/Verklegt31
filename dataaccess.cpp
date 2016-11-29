#include "dataaccess.h"
#include <fstream>
#include <iostream>

using namespace std;

DataAccess::DataAccess()
{

}

void DataAccess::readToFile(vector<Scientist> scientist)
{

    for (int i = 0; i < scientist.size(); i++)
    {

    }
}

vector<Scientist> DataAccess::readFromFile()
{
    ifstream thefile;
    vector<Scientist> line;

    if (thefile.fail()){
        cout << "File can't be opened!" << endl;
        return 0;
    }

    while(!thefile.eof()){
        getline(thefile, line);

        line.
    }

    thefile.close();
}
