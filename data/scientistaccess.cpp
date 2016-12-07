#include "data/scientistaccess.h"

using namespace std;

ScientistAccess::ScientistAccess()
{
    _temp = 0;
}

void ScientistAccess::readToDatabase(Scientist scientist)
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
    m_db.close();
}

void ScientistAccess::removelist(string name)
{
    int number = 0;

    connect();

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::fromStdString(name);
    query.prepare("UPDATE Scientists SET Status = 0 WHERE Name = (:name)");
    query.bindValue(":name", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}

void ScientistAccess::removeAll()
{
    connect();

    QSqlQuery query;
    query.prepare("TRUNCATE TABLE Scientists");
    query.exec();
}

vector<Scientist> ScientistAccess::readFromDatabase()
{
    vector <Scientist> sci;

    connect();

    QSqlQuery query("SELECT * FROM Scientists");

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
       Scientist pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);

           sci.push_back(pl);
       }
    }
    m_db.close();

    return sci;
}

void ScientistAccess::connect()
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

void ScientistAccess::edit(int Id, string command)
{
    connect();

    QSqlQuery query;

    if (command == "name")
    {
        query.prepare("UPDATE name FROM Scientists SET name = (:change) WHERE id = (:Id)");
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
 vector<Scientist> ScientistAccess::sortQuery(string var, string command)
{
    vector<Scientist> sci;

    connect();

    QSqlDatabase query();
    QString qVar = QString::fromStdString(var);
    QString qCom = QString::fromStdString(command);

    //Vantar koda til ad gera query!
    sci = scientistQuery(query);

    return sci;
}

bool ScientistAccess::checkEntry(Scientist scientist)
{
    QSqlQuery query("SELECT * FROM Scientists");

    QString Id = QString::number(scientist.getId());
    QString Name = QString::fromStdString(scientist.getName());
    QString Sex = QString::fromStdString(scientist.getSex());
    QString Birth = QString::number(scientist.getBirth());
    QString Death = QString::number(scientist.getDeath());

    while (query.next())
    {

        int idId = query.record().indexOf("id");
        int idName = query.record().indexOf("name");
        int idSex= query.record().indexOf("sex");
        int idBirth = query.record().indexOf("birth");
        int idDeath = query.record().indexOf("death");
        int idStatus = query.record().indexOf("Status");

        QString qId = query.value(idId).toString();
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
