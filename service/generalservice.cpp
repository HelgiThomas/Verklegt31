#include "generalservice.h"

using namespace std;

GeneralService::GeneralService()
{

}

void GeneralService::link(int sciId, int compId)
{
    _link.link(sciId, compId);
}

bool GeneralService::validRelation(int sci, vector<int> num)
{
    bool valid = true;
    for(int i = 0; i < num.size(); i++)
    {
        if(sci == num[i])
        {
            valid = false;
            break;
        }
    }
    return valid;
}
