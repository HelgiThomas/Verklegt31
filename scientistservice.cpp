#include "scientistservice.h"

#include <vector>

using namespace std;

ScientistService::ScientistService()
{

}

vector <Scientist> ScientistService::getScientist()
{
    return theList;
}

void ScientistService::addScientist(const Scientist newScientist)
{
   theList.push_back(newScientist);
}
