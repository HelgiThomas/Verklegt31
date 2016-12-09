#ifndef GENERALSERVICE_H
#define GENERALSERVICE_H

#include "data/computeraccess.h"
#include "data/scientistaccess.h"
#include "data/linkaccess.h"

class GeneralService
{
public:
    GeneralService();

    void link(int sciId, int compId);
    
    bool validRelation(int sci, vector<int> num);

private:
    LinkAccess _link;
};

#endif // GENERALSERVICE_H
