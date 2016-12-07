#ifndef UTILITY_H
#define UTILITY_H


#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QDebug>
#include <string>

class Utility
{
public:
    Utility();

    /**
     * @brief connect, connects to the sql database.
     */
    QSqlDatabase getConnection();
};

#endif // UTILITY_H
