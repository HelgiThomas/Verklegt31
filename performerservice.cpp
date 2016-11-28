#include "performerservice.h"

PerformerService::PerformerService()
{

}
vector <Performer> PerformerService::getPerformers()
{
    vector <Performer> performers;
    Performer p ("Duran Duran", 56);
    Performer p2 ("Madonna", 55);

    performers.push_back(p);
    performers.push_back(p2);

    return performers;
}
