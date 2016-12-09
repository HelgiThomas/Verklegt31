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

    return scientistsID;
}
/**
 * @brief This function puts all Computer ID that are in the relations in the SQL Database in a vector
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
        return computersID;
}
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

    return relationID;

}

/**
 * @brief edits the selected ID and putss the new science ID and new computer Id in that relation
 * @param int nrID, int SciID, int CompID
 */
void LinkAccess::editRelation (int nrID, int sciID, int compID)
{
    cout << nrID << " " << sciID << " " << compID;
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



}
/**
 * @brief This function adds the selected scientist and the selected computer to the SQL database relation
 * @param int scientistId, int ComputerId
 */
void LinkAccess::connect()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("DB_vika2.sqlite");

    if (!m_db.open())
    {

    }
    else
    {

    }
}
