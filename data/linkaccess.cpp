#include "data/linkaccess.h"

using namespace std;

LinkAccess::LinkAccess()
{

}


bool LinkAccess::link(int scientistId, int computerId)
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
void LinkAccess::editRelation (int nrID, int SciID, int CompID)
{

}
void LinkAccess::removeRelation (int nrID)
{

}

void LinkAccess::connect()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("DB_vika2.sqlite");

    if (!m_db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }
}
