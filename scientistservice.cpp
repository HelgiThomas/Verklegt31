#include "scientistservice.h"
#include <vector>

using namespace std;

PerformerService::PerformerService()
{

}
vector <Performer> PerformerService::getPerformers()
{


    return theList;
}
void PerformerService::addPerformers (const Performer newPerformer)
{
   theList.push_back(newPerformer);
}
