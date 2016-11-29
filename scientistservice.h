#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H


#include <vector>
#include "performer.h"
using namespace std;

class PerformerService
{
public:
    PerformerService();

    vector <Performer> getPerformers();
    void addPerformers (const Performer newPerformer);

private:
    vector <Performer> theList;
};

#endif // PERFORMERSERVICE_H
