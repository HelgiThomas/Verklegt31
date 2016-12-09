#ifndef GENERALSERVICE_H
#define GENERALSERVICE_H

#include "data/computeraccess.h"
#include "data/scientistaccess.h"
#include "data/linkaccess.h"

/**
 * @brief The GeneralService class, handles Business level operations for links.
 */
class GeneralService
{
public:
    /**
     * @brief GeneralService, default constructor.
     */
    GeneralService();

    /**
     * @brief link,
     * @param int sciId
     * @param int compId
     */
    void link(int sciId, int compId);
    
    /**
     * @brief validRelation
     * @param int sci
     * @param vector num
     * @return
     */
    bool validRelation(int sci, vector<int> num);

    /**
     * @brief removeRelation
     * @param int nrId
     */
    void removeRelation (int nrId);

    /**
     * @brief editRelation,
     * @param int nrID
     * @param int sciID
     * @param int compID
     */
    void editRelation(int nrID,int sciID,int compID);

    /**
     * @brief allRelationID,
     * @return
     */
    vector<int> allRelationID();

private:
    LinkAccess _link;
};

#endif // GENERALSERVICE_H
