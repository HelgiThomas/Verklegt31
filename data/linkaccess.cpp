#include "data/linkaccess.h"

#include <sstream>

using namespace std;

LinkAccess::LinkAccess()
{

}


bool LinkAccess::link(int scientistId, int computerId)
{
    int number = 1;

    connect();

    QSqlQuery query(m_db);
    QString qSci = QString::number(scientistId);
    QString qComp = QString::number(computerId);

    query.prepare("INSERT INTO SciComp (SciID, CompID) VALUES (:sci, :comp)");
    query.bindValue(":sci", qSci);
    query.bindValue(":comp", qComp);

    query.exec();
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
