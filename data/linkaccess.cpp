#include "data/linkaccess.h"


using namespace std;

LinkAccess::LinkAccess()
{

}


bool link(int scientistId, int computerId)
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
