#include "data/linkaccess.h"

using namespace std;

LinkAccess::LinkAccess()
{

}
/**
 * @brief This function adds the selected scientist and the selected computer to the SQL database relation and sets status = 1
 * @param int scientistId, int ComputerId
 */
void LinkAccess::link(int scientistId, int computerId)
{
    int number = 1;

    connect();
    if(checkEntry(scientistId, computerId))
     {
        QSqlQuery query;
        QString qSci = QString::number(scientistId);
        QString qComp = QString::number(computerId);
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO SciComp (SciID, CompID, Status) VALUES (:sci, :comp , :status)");
        query.bindValue(":sci", qSci);
        query.bindValue(":comp", qComp);
        query.bindValue(":status", number);

        query.exec();
     }





    closeConn();
}
/**
 * @brief This function puts all Scientists ID that are in the relations in the SQL Database in a vector
 * @return vector of Scientist ID numbers
 */
vector<int>LinkAccess::ScientistId ()
{
    connect();
    vector<int> scientistsID;

    QSqlQuery query;

    string query_string = "SELECT * FROM SciComp ";
    QString qCommand (query_string.c_str());
    query.exec(qCommand);

    int SciID = query.record().indexOf("SciID");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
        QString qSciID = query.value(SciID).toString();
        QString qStatus = query.value(idStatus).toString();

        int id = qSciID.toInt();
        int status = qStatus.toInt();
        if (status == 1)
        {
            scientistsID.push_back(id);
        }
    }

    closeConn();

    return scientistsID;
}
/**
 * @brief This function puts all Computers ID that are in the relations in the SQL Database in a vector
 * @return vector of Computer ID numbers
 */
vector<int> LinkAccess::ComputerId ()
{

    connect();
    vector<int> computersID;

    QSqlQuery query;

    string query_string = "SELECT * FROM SciComp";
    QString qCommand (query_string.c_str());
    query.exec(qCommand);

    int CompID = query.record().indexOf("CompID");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {

        QString qCompID = query.value(CompID).toString();
        QString qStatus = query.value(idStatus).toString();

        int id = qCompID.toInt();
        int status = qStatus.toInt();

        if (status == 1)
        {
            computersID.push_back(id);
        }
    }

    closeConn();
    return computersID;
}

/**
 * @brief This function puts all Relation ID that are in the relations in the SQL Database in a vector
 * @return vector of Relation ID numbers
 */
vector<int> LinkAccess::RelationId()
{
    connect();
    vector<int> relationID;

    QSqlQuery query;

    string query_string = "SELECT * FROM SciComp";
    QString qCommand (query_string.c_str());
    query.exec(qCommand);

    int idID = query.record().indexOf("ID");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {

        QString qID = query.value(idID).toString();
        QString qStatus = query.value(idStatus).toString();

        int relationId = qID.toInt();
        int status = qStatus.toInt();

        if (status == 1)
        {
            relationID.push_back(relationId);
        }
    }
    closeConn();

    return relationID;

}

/**
 * @brief edits the selected ID and puts the new scientist ID and new computer Id in that relation
 * @param int nrID, int SciID, int CompID
 */
void LinkAccess::editRelation (int changeID, int newSciID,int newCompID)
{
    editSci(changeID,newSciID);
    editComp(changeID,newCompID);
}

/**
 * @brief edits the selected ID and puts the new scientist ID and new computer Id in that relation
 * @param int nrID, int SciID, int CompID
 */
void LinkAccess::editSci (int changeID, int newSciID)
{
    connect();
    QSqlQuery query;

    QString qID = QString::number(changeID+1);
    QString qSciID = QString::number(newSciID);


    query.prepare("UPDATE SciComp SET SciID = :newSciID WHERE ID = :changeID");
    query.bindValue(":newSciID", qSciID);
    query.bindValue(":changeID", qID);

    query.exec();

    closeConn();
}

/**
 * @brief edits the selected ID and puts the new scientist ID and new computer Id in that relation
 * @param int nrID, int SciID, int CompID
 */
void LinkAccess::editComp (int changeID, int newCompID)
{
    connect();
    QSqlQuery query;

    QString qID = QString::number(changeID);
    QString qcompID = QString::number(newCompID);

    query.prepare("UPDATE SciComp SET CompID = :newCompID WHERE ID = :changeID");
    query.bindValue(":newCompID", qcompID);
    query.bindValue(":changeID", qID);

    query.exec();

    closeConn();
}

/**
 * @brief This function puts the status = 0 for the selcted re++lation
 * @param int nr ID
 */
void LinkAccess::removeRelation (int nrID)
{

    vector<int> allID = RelationId();

    int IDremove = allID[nrID-1];
    connect();

    QSqlQuery query;

    QString qID = QString::number(IDremove);
    query.prepare("UPDATE SciComp SET Status = 0 WHERE ID = (:IDremove)");
    query.bindValue(":IDremove", qID);

    query.exec();

    closeConn();
}

bool LinkAccess::checkEntry(int scientistId, int computerId)
 {
     QSqlQuery query("SELECT * FROM SciComp");

     QString sciId = QString::number(scientistId);
     QString compId = QString::number(computerId);

     while (query.next())
     {
         int idSci = query.record().indexOf("SciID");
         int idComp = query.record().indexOf("CompID");

         QString qSci = query.value(idSci).toString();
         QString qComp = query.value(idComp).toString();

         if (sciId == qSci && compId == qComp)
         {
             return false;
         }
     }
     return true;
 }


int LinkAccess::getLinkId(int sciId, int compId)
{
    int linkId;

    connect();
    QSqlQuery query;

    QString newSciID = QString::number(sciId);
    QString newCompID = QString::number(compId);
    query.prepare("SELECT ID FROM SciComp WHERE CompID = :compid AND SciID = :sciid ");
    query.bindValue(":compid", newSciID);
    query.bindValue(":sciid", newCompID);


    query.exec();

    int idId = query.record().indexOf("ID");
    QString qId = query.value(idId).toString();
    int linkid = qId.toInt();

    closeConn();

    return linkid;
}

/**
 * @brief This function adds the selected scientist and the selected computer to the SQL database relation
 * @param int scientistId, int ComputerId
 */
void LinkAccess::connect()
{
    if (!m_db.isOpen())
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("DB_vika2.sqlite");

        m_db.open();
    }
    else
    {
        m_db.open();
    }
}

/**
 * @brief ComputerAccess::closeConn, close the SQL database connection
 */
void LinkAccess::closeConn()
{
    QString conn;
    conn = m_db.connectionName();
    m_db.close();
    m_db = QSqlDatabase();
    m_db.removeDatabase(conn);
}

