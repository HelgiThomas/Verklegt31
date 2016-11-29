#include "scientistservice.h"

#include <vector>

using namespace std;

ScientistService::ScientistService()
{

}
vector <Scientist> ScientistService::getScientists()
{


    return theList;
}
void ScientistService::addScientists (const Scientist newScientist)
{
   theList.push_back(newScientist);
}
