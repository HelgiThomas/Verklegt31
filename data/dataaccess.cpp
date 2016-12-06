#include "data/dataaccess.h"

using namespace std;

/**
 * @brief This is the default constructor.
 */
DataAccess::DataAccess()
{


}


void DataAccess::readToFile(Scientist scientist)
{
    int number = 1;
    connect();

    if (checkEntry(scientist))
    {

        // you should check if args are ok first...
        QSqlQuery query;
        QString qName = QString::fromStdString(scientist.getName());
        QString qSex = QString::fromStdString(scientist.getSex());
        QString qBirth = QString::number(scientist.getBirth());
        QString qDeath = QString::number(scientist.getDeath());
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO Scientists (name, sex, birth, death, status) VALUES (:name, :sex, :birth, :death, :status)");
        query.bindValue(":name", qName);
        query.bindValue(":sex", qSex);
        query.bindValue(":birth", qBirth);
        query.bindValue(":death", qDeath);
        query.bindValue(":status", qStatus);

        query.exec();
    }
}
void DataAccess::readToFileComputer(Computer computer)
{
    int number = 1;
       connect();

       QSqlQuery query;

       QString qName = QString::fromStdString(computer.getName());
       QString qYear = QString::number(computer.getBuildYear());
       QString qType = QString::fromStdString(computer.getCompType());
       QString qBuilt = QString::fromStdString(computer.getWasBuilt());
       QString qStatus = QString::number(number);

       query.prepare("INSERT INTO Computers (name, year, type, wasbuilt, status) VALUES (:name, :year, :type, :wasbuilt, :status)");
       query.bindValue(":name", qName);
       query.bindValue(":year", qYear);
       query.bindValue(":type", qType);
       query.bindValue(":wasbuilt", qBuilt);
       query.bindValue(":status", qStatus);

       query.exec();
}

vector<Scientist> DataAccess::readFromFile()
{

    vector <Scientist> sci;
    connect();

    QSqlQuery query("SELECT * FROM Scientists");

    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
       Scientist pl;

       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qStatus = query.value(idStatus).toString();

       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);

           sci.push_back(pl);
       }
    }

    return sci;
}
//comment helgi
vector<Computer> DataAccess::readFromFileComputer()
{
    vector <Computer> comp;
        connect();

        QSqlQuery query("SELECT * FROM Computers");

        int idName = query.record().indexOf("name");
        int idYear = query.record().indexOf("year");
        int idType = query.record().indexOf("type");
        int idBuilt = query.record().indexOf("wasbuilt");
        int idStatus = query.record().indexOf("status");

        while (query.next())
        {
           Computer pl;

           QString qName = query.value(idName).toString();
           QString qYear = query.value(idYear).toString();
           QString qType = query.value(idType).toString();
           QString qBuilt = query.value(idBuilt).toString();
           QString qStatus = query.value(idStatus).toString();

           std::string name = qName.toStdString();
           int year = qYear.toInt();
           std::string type = qType.toStdString();
           std::string built = qBuilt.toStdString();
           int status = qStatus.toInt();

           if (status == 1)
           {
               pl.setName(name);
               pl.setBuildYear(year);
               pl.setCompType(type);
               pl.setWasBuilt(built);

               comp.push_back(pl);
           }
        }

        return comp;
}

//commenta helgi
void DataAccess::connect()
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

/**
 * @brief A bool function to check whether the scientist entry already exists.
 * @param Scientist variable.
 * @return true/false.
 */
bool DataAccess::checkEntry(Scientist scientist)
{

    QSqlQuery query("SELECT * FROM Scientists");

    QString Name = QString::fromStdString(scientist.getName());
    QString Sex = QString::fromStdString(scientist.getSex());
    QString Birth = QString::number(scientist.getBirth());
    QString Death = QString::number(scientist.getDeath());

    while (query.next())
    {

        int idName = query.record().indexOf("name");
        int idSex= query.record().indexOf("sex");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        int idStatus = query.record().indexOf("Status");

        QString qName = query.value(idName).toString();
        QString qSex = query.value(idSex).toString();
        QString qBirth = query.value(idBirth).toString();
        QString qDeath = query.value(idDeath).toString();
        QString qStatus = query.value(idStatus).toString();

       if (Name == qName && Sex == qSex && Birth == qBirth && Death == qDeath)
       {
          cout << "This person already exist! ";
          return false;
       }
    }
    return true;
}
// commenta helgi
void DataAccess::removeScientistlist (string name)
{
    int number = 0;

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::fromStdString(name);
    query.prepare("UPDATE Scientists SET Status = 0 WHERE Name = (:name)");
    query.bindValue(":name", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}

//commenta helgi
void DataAccess::removeComputerlist (string nameOf)
{

}

// commenta helgi
void DataAccess:: editScientist (int id, string command)
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

//commenta helgi
void DataAccess::removeEveryscienst ()
{
    int number = 0;

    QSqlQuery query;

    QString qStatus = QString::number(number);
    query.prepare("UPDATE Scientists SET Status = 0");
    query.bindValue(":status", qStatus);

    query.exec();
}
void DataAccess::removeEveryComputer()
{

}

