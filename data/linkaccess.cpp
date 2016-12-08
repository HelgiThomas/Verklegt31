#include "data/linkaccess.h"

using namespace std;

LinkAccess::LinkAccess()
{

}


void LinkAccess::link(int scientistId, int computerId)
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

vector<int> readFromDatabase()
{
    vector<int> link;

    connect();

    QSqlQuery query("SELECT * FROM SciCom");

    int sciID = query.record().indexof("sciID");
    int comID = query.record().indexof("comID");
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
