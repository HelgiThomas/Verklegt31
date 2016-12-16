#include "generalservice.h"

using namespace std;

/**
 * @brief This is the default constructor.
 */
GeneralService::GeneralService()
{

}

/**
 * @brief This function connects the scientist ID and computer ID.
 * @param int sciId
 * @param int compId
 */
void GeneralService::link(int sciId, int compId)
{
    _link.link(sciId, compId);
}

/**
 * @brief This function checks if the relation is valid or not.
 * @param int sci
 * @param vector num
 * @return true/false
 */
bool GeneralService::validRelation(int sci, vector<int> num)
{
    bool valid = true;
    for(unsigned int i = 0; i < num.size(); i++)
    {
        if(sci == num[i])
        {
            valid = false;
            break;
        }
    }
    return valid;
}

/**
 * @brief This function calls a function that removes a relation.
 * @param int nrId
 */
void GeneralService::removeRelation(int nrId)
{
    _link.removeRelation(nrId);
}

/**
 * @brief This function calls a function that edits relations.
 * @param int changeID
 * @param int newSciID
 * @param int newCompID
 */
void GeneralService::editRelation(int changeID,int newSciID,int newCompID)
{
    _link.editRelation(changeID, newSciID,newCompID);
}

/**
 * @brief This function calls a function that gets all the realtion IDs.
 * @return int relationID
 */
vector <int> GeneralService::allRelationID()
{
    return _link.RelationId();
}

/**
 * @brief GeneralService::getLinkId, returns the Id of the relation
 * @param sciName
 * @param compName
 * @return
 */
int GeneralService::getLinkId(int sciId, int compId)
{
    return _link.getLinkId(sciId, compId);
}
