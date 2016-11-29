#include "scientistservice.h"
#include "dataaccess.h"

using namespace std;

ScientistService::ScientistService()
{

}

vector <Scientist> ScientistService::getScientist()
{
    DataAccess access;
    listOfScientist = access.readFromFile();
    return listOfScientist;
}

void ScientistService::addScientist(Scientist newScientist)
{
    DataAccess access;
    access.readToFile(newScientist);
}

/*
void ScientistService::addToVector(string word)
{
    listOfScientist.push_back(word.str());
}
*/

