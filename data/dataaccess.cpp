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
    connect();

    // you should check if args are ok first...
    QSqlQuery query;
    QString qName = QString::fromStdString(scientist.getName());
    QString qSex = QString::fromStdString(scientist.getSex());
    QString qBirth = QString::number(scientist.getBirth());
    QString qDeath = QString::number(scientist.getDeath());

    query.prepare("INSERT INTO Scientists (name, sex, birth, death) VALUES (:name, :sex, :birth, :death)");
    query.bindValue(":name", qName);
    query.bindValue(":sex", qSex);
    query.bindValue(":birth", qBirth);
    query.bindValue(":death", qDeath);

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
    while (query.next())
    {
       Scientist pl;

       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();

       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();

       pl.setName(name);
       pl.setSex(sex);
       pl.setBirth(birth);
       pl.setDeath(death);

       sci.push_back(pl);

    }

    return sci;


}

void DataAccess::connect()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("..\\Verklegt31\\DB_vika2.sqlite");

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
/*
bool DataAccess::checkEntry(Scientist scientist)
{
/*
    QSqlQuery query;
    query.prepare("SELECT name FROM people WHERE name = (:name)");
    query.bindValue(":name", name);

    if (query.exec())
    {
       if (query.next())
       {
          // it exists
       }
*/


void DataAccess::removeScientistlist (string name)
{
    /*
    if (personExists(name))
    {
       QSqlQuery query;
       query.prepare("DELETE FROM people WHERE name = (:name)");
       query.bindValue(":name", name);
       success = query.exec();

       if(!success)
       {
           qDebug() << "removePerson error: "
                    << query.lastError();
       }
    }
    */
}


void DataAccess::removeEveryscienst ()
{
    QSqlQuery query;
    query.prepare("DELETE FROM Scientists");
    query.exec();
}

