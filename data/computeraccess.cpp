#include "data/computeraccess.h"

#include <sstream>

using namespace std;

ComputerAccess::ComputerAccess()
{
    _temp = 0;
}

void ComputerAccess::readToDatabase(Computer computer)
{
    int number = 1;

    connect();

    if (checkEntry(computer))
    {        
        // you should check if args are ok first...
        QSqlQuery query(m_db);
        QString qId = QString::number(computer.getId());
        QString qName = QString::fromStdString(computer.getName());
        QString qType = QString::fromStdString(computer.getCompType());
        QString qBuilt = QString::fromStdString(computer.getWasBuilt());
        QString qDescription = QString::fromStdString(computer.getDescription());
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO Computers (id, name, type, build, description, status) VALUES (:id, :name, :type, :built, :description, :status)");
        query.bindValue(":id", qId);
        query.bindValue(":name", qName);
        query.bindValue(":type", qType);
        query.bindValue(":built", qBuilt);
        query.bindValue(":description", qDescription);
        query.bindValue(":status", qStatus);

        query.exec();
    }
}


void ComputerAccess::removelist(string name)
{
    int number = 0;

    connect();

    QSqlQuery query(m_db);

    QString qStatus = QString::number(number);
    QString qName = QString::fromStdString(name);
    query.prepare("UPDATE Computers SET Status = 0 WHERE Name = (:name)");
    query.bindValue(":name", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}


void ComputerAccess::removeAll()
{
    connect();

    QSqlQuery query;
    query.prepare("TRUNCATE TABLE Computers");
    query.exec();
}


vector<Computer> ComputerAccess::readFromDatabase()
{
    vector<Computer> com;

    connect();

    QSqlQuery query("SELECT * FROM Computers");

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("built");
    int idDescription = query.record().indexOf("description");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
       Computer pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qType = query.value(idType).toString();
       QString qBuilt = query.value(idBuilt).toString();
       QString qDescription = query.value(idDescription).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string type =  qType.toStdString();
       std::string built = qBuilt.toStdString();
       std::string description = qDescription.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setCompType(type);
           pl.setWasBuilt(built);
           pl.setDescription(description);

           com.push_back(pl);
       }
    }

    return com;
}


void ComputerAccess::connect()
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


void ComputerAccess::edit(int id, string command)
{
    if (command == "name")
    {

    }
    else if (command == "sex")
    {

    }
    else if (command == "birth")
    {

    }
    else if (command == "death")
    {

    }
}

bool ComputerAccess::checkEntry(Computer computer)
{
    QSqlQuery query("SELECT * FROM Computers");

    QString Id = QString::number(computer.getId());
    QString Name = QString::fromStdString(computer.getName());
    QString Type = QString::fromStdString(computer.getCompType());
    QString Built = QString::fromStdString(computer.getWasBuilt());
    QString Description = QString::fromStdString(computer.getDescription());

    while (query.next())
    {

        int idId = query.record().indexOf("id");
        int idName = query.record().indexOf("name");
        int idType = query.record().indexOf("type");
        int idBuilt = query.record().indexOf("built");
        int idDescription = query.record().indexOf("description");
        int idStatus = query.record().indexOf("Status");

        QString qId = query.value(idId).toString();
        QString qName = query.value(idName).toString();
        QString qType = query.value(idType).toString();
        QString qBuilt = query.value(idBuilt).toString();
        QString qDescription = query.value(idDescription).toString();
        QString qStatus = query.value(idStatus).toString();

       if (Name == qName && Type == qType && Built == qBuilt && Description == qDescription)
       {
          cout << "This person already exist! ";
          return false;
       }
    }
    return true;
}
