#include "data/computeraccess.h"

#include <sstream>

using namespace std;

ComputerAccess::ComputerAccess()
{
    _temp = 0;
}

vector<Computer> ComputerAccess::readFromDatabase()
{
    vector<Computer> com;

    connect();

    QSqlQuery query("SELECT * FROM Computers");

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idYear = query.record().indexOf("year");
    int idType = query.record().indexOf("type");
    int idBuilt = query.record().indexOf("wasbuilt");
    int idDescription = query.record().indexOf("description");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
       Computer pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qYear = query.value(idYear).toString();
       QString qType = query.value(idType).toString();
       QString qBuilt = query.value(idBuilt).toString();
       QString qDescription = query.value(idDescription).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       int year = qYear.toInt();
       std::string type =  qType.toStdString();
       std::string built = qBuilt.toStdString();
       std::string description = qDescription.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setBuildYear(year);
           pl.setCompType(type);
           pl.setWasBuilt(built);
           pl.setDescription(description);

           com.push_back(pl);
       }
    }
        m_db.close();
    return com;
}

void ComputerAccess::readToDatabase(Computer computer)
{
    int number = 1;

    connect();

    if (checkEntry(computer))
    {
        // you should check if args are ok first...
        QSqlQuery query;
        QString qName = QString::fromStdString(computer.getName());
        QString qYear = QString::number(computer.getBuildYear());
        QString qType = QString::fromStdString(computer.getCompType());
        QString qBuilt = QString::fromStdString(computer.getWasBuilt());
        QString qDescription = QString::fromStdString(computer.getDescription());
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO Computers (name, year, type, wasbuilt, description, status) VALUES (:name, :year, :type, :wasbuilt, :description, :status)");
        query.bindValue(":name", qName);
        query.bindValue(":year", qYear);
        query.bindValue(":type", qType);
        query.bindValue(":wasbuilt", qBuilt);
        query.bindValue(":description", qDescription);
        query.bindValue(":status", qStatus);

        query.exec();
    }
        m_db.close();
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


vector<Computer> ComputerAccess::sortQuery(string var, string command)
{
    vector<Computer> comp;

    connect();

    QSqlQuery query;
    QString qVar = QString::fromStdString(var);
    QString qCom = QString::fromStdString(command);

    query.prepare("SELECT * FROM Scientists ORDER BY ':var' ':com'");
    query.bindValue(":var", qVar);
    query.bindValue(":com", qCom);

    //comp = computerQuery(query);
}


vector<Computer> ComputerAccess::searchQueryString(string command)
{
    vector<Computer> sci;

    QSqlQuery query;

    //Koði til að gera query!

    //sci = computerQuery(query);

    return sci;


}

vector<Computer> ComputerAccess::searchQueryInt(int command)
{
    vector<Computer> sci;

    QSqlQuery query;

    //Koði til að gera query!

    //sci = computerQuery(query);

    return sci;
}

bool ComputerAccess::checkEntry(Computer computer)
{
    QSqlQuery query("SELECT * FROM Computers");

    QString Name = QString::fromStdString(computer.getName());
    QString Type = QString::fromStdString(computer.getCompType());
    QString Built = QString::fromStdString(computer.getWasBuilt());
    QString Description = QString::fromStdString(computer.getDescription());

    while (query.next())
    {
        int idName = query.record().indexOf("name");
        int idType = query.record().indexOf("type");
        int idBuilt = query.record().indexOf("built");
        int idDescription = query.record().indexOf("description");
        int idStatus = query.record().indexOf("Status");

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
