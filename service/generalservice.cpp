#include "generalservice.h"

using namespace std;

GeneralService::GeneralService()
{

}

void GeneralService::link(int sciId, int compId)
{
    _link.link(sciId, compId);
}
