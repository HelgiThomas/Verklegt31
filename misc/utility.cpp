#include "utility.h"

Utility::Utility()
{

}

QSqlDatabase Utility::getConnection()
{
    QSqlDatabase db;

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DB_vika2.sqlite");

    if (!db.open())
    {
       qDebug() << "Error: connection with database fail";
    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    return db;
}
