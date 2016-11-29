#include "performerservice.h"
#include <vector>

using namespace std;

PerformerService::PerformerService()
{

}
vector <Performer> PerformerService::getPerformers()
{
    vector <Performer> performers;
    Performer p ("Duran","Male",1950,2000);
    Performer p2 ("Madonna", "Female",1500,1600);

    performers.push_back(p);
    performers.push_back(p2);

    return performers;
}
