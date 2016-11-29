#include "scientistservice.h"
#incldue "dataaccess.h"

#include <vector>

using namespace std;

ScientistService::ScientistService()
{

}

vector <Scientist> ScientistService::getScientist()
{
    listOfScientist = access.readFromFile();
    return listOfScientist;
}

void ScientistService::addScientist(const Scientist newScientist)
{
    access.readToFile(newScientist);
}

