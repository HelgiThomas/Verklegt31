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

    query.prepare("INSERT INTO SciComp (SciID, CompID) VALUES (:sci, :comp)");
    query.bindValue(":sci", qSci);
    query.bindValue(":comp", qComp);

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
    while (query.next())
    {

       QString qSciID = query.value(SciID).toString();

       int id = qSciID.toInt();

        scientistsID.push_back(id);
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
        while (query.next())
        {

           QString qComoID = query.value(CompID).toString();

           int id = qComoID.toInt();

            computersID.push_back(id);
         }

        return computersID;
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
