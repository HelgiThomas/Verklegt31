#include "data/scientistaccess.h"

#include <QString>
#include <cstdlib>
#include <sstream>

using namespace std;

ScientistAccess::ScientistAccess()
{
    _temp = 0;
}
/**
 * @brief This function reads all the Scientists from SQL database that have status = 1 and adds them to a vector.
 * @return vector of Scientists
 */
vector<Scientist> ScientistAccess::readFromDatabase()
{
    vector<Scientist> sci;

    connect();

    QSqlQuery query("SELECT * FROM Scientists");

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idCitation = query.record().indexOf("citation");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
       Scientist pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qCitation = query.value(idCitation).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       std::string citation = qCitation.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);
           pl.setCitation(citation);

           sci.push_back(pl);
       }
    }
    m_db.close();

    return sci;
}
/**
 * @brief This function reads the new Scientist to the SQL database and adds them to a vector.
 * @param vector of Scientist
 */
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
        QString qCitation = QString::fromStdString(scientist.getCitation());
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO Scientists (name, sex, birth, death, citation, status) VALUES (:name, :sex, :birth, :death, :citation, :status)");
        query.bindValue(":name", qName);
        query.bindValue(":sex", qSex);
        query.bindValue(":birth", qBirth);
        query.bindValue(":death", qDeath);
        query.bindValue(":citation", qCitation);
        query.bindValue(":status", qStatus);

        query.exec();
    }
    m_db.close();
}
/**
 * @brief This function sets the status = 0 for selected Scientist in the SQL database
 * @param int nameOf
 */
void ScientistAccess::removelist(int nameOf)
{
    int number = 0;

    connect();

    updateRelation(nameOf);

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::number(nameOf);
    query.prepare("UPDATE Scientists SET Status = 0 WHERE ID = (:nameOf)");
    query.bindValue(":nameOf", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}
void ScientistAccess::updateRelation(int nameOf)
{
    int number = 0;
    connect();

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::number(nameOf);

    query.prepare("UPDATE SciComp SET Status = 0 WHERE SciID = (:nameOf)");
    query.bindValue(":nameOf", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}
void ScientistAccess::updateRelationall()
{
    connect();

    QSqlQuery query;
    query.prepare("UPDATE SciComp SET Status = 0");
    query.exec();
}


/**
 * @brief This function sets status = 0 for all the Scientist in the SQL database
 */
void ScientistAccess::removeAll()
{
    connect();

    updateRelationall();

    QSqlQuery query;
    query.prepare("UPDATE Scientists SET Status = 0");
    query.exec();
}
/**
 * @brief This function lets the User edit the string elements selected entry of Scientist in the SQL Datbase
 * @param int nameOf, string variable, string newElement
 */
void ScientistAccess::editString(string nameOf, string variable, string newElement)
{
    connect();
    QSqlQuery query;

    QString qNameOf = QString::fromStdString(nameOf);
    QString qNewElement = QString::fromStdString(newElement);

    if (variable == "Name" || variable == "name" || variable == "1")
    {
        query.prepare("UPDATE Scientists SET Name = :newElement WHERE Name = :name");
        query.bindValue(":newElement", qNewElement);
        query.bindValue(":name", qNameOf);
    }
    else if (variable == "Sex" || variable == "sex" || variable == "2")
    {
        query.prepare("UPDATE Scientists SET Sex = :newElement WHERE Name = :name");
        query.bindValue(":newElement", qNewElement);
        query.bindValue(":name", qNameOf);
    }

    query.exec();
}
/**
 * @brief This function lets the User edit the int elements in the selected entry of Scientists in the SQL Datbase
 * @param int nameOf, string variable, int newElement
 */
void ScientistAccess::editInt(string nameOf, string variable, int newElement)
{
    connect();

    QSqlQuery query;
    string newElementStr;
    newElementStr = to_string(newElement);

    QString qNameOf = QString::fromStdString(nameOf);
    QString qNewElement = QString::number(newElement);

    if (variable == "Birth" || variable == "birth" || variable == "3")
    {
        query.prepare("UPDATE Scientists SET Birth = :newElement WHERE Name = :name");
        query.bindValue(":name", qNameOf);
        query.bindValue(":newElement", qNewElement);
    }
    else if (variable == "Death" || variable == "death" || variable == "4")
    {
        query.prepare("UPDATE Scientists SET Death = :newElement WHERE Name = :name");
        query.bindValue(":name", qNameOf);
        query.bindValue(":newElement", qNewElement);
    }

    query.exec();
}
/**
 * @brief This function connects QT to the SQL database
 */
void ScientistAccess::connect()
{
    if (!m_db.isOpen())
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("DB_vika2.sqlite");

        m_db.open();
    }
    else
    {
        m_db.open();
    }
}
/**
 * @brief This function sorts the Scientists in an vector according the the selected variable and selected command ("ASC" or "DESC")
 * @param string var, string command
 * @return vector of Scientists
 */
vector<Scientist> ScientistAccess::sortQuery(string var, string command)
{
    connect();

    QSqlQuery query;
    vector<Scientist> sci;

    string query_string = "SELECT * FROM Scientists ORDER BY " + var + " " + command;
    QString qCommand (query_string.c_str());
    query.exec(qCommand);

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idCitation = query.record().indexOf("citation");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
       Scientist pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qCitation = query.value(idCitation).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       std::string citation = qCitation.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);
           pl.setCitation(citation);

           sci.push_back(pl);
       }
    }
    m_db.close();

    return sci;
}
/**
 * @brief This function searches the Computers in the SQL Database after the selcted variable (String) and the newCommand ("new name, new type...") and puts them in a vector
 * @param string variable, string command
 * @return vector of Scientists
 */
vector<Scientist> ScientistAccess::searchQueryString(string variable,string command)
{
    connect();


    QSqlQuery query;
    vector<Scientist> sci;


    if (variable == "Name" || variable == "name")
    {
        string query_string = "SELECT * FROM Scientists WHERE Name LIKE '" + command + "%'";
        QString qCommand (query_string.c_str());
        query.exec(qCommand);
    }
    else if (variable == "Sex" || variable == "sex")
    {
        string query_string = "SELECT * FROM Scientists WHERE Sex LIKE '" + command + "%'";
        QString qCommand (query_string.c_str());
        query.exec(qCommand);
    }

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idCitation = query.record().indexOf("citation");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
       Scientist pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qCitation = query.value(idCitation).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       std::string citation = qCitation.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);
           pl.setCitation(citation);

           sci.push_back(pl);
       }
    }
    m_db.close();

    return sci;
}
/**
 * @brief This function searches the Scientists in the SQL Database after the selcted variable (Int) and the newCommand ("new year, new death...") and puts them in a vector
 * @param string variable, string operatorOf, string command
 * @return vector of Scientists
 */
vector<Scientist> ScientistAccess::searchQueryInt(string variable, string operatorOf, int command)
{
    connect();
    string commandStr;
    commandStr = to_string(command);
    QSqlQuery query;
    vector<Scientist> sci;

    if (variable == "Birth" || variable == "birth")
    {
        if (operatorOf == "greater" || operatorOf == "Greater")
        {
            string query_string = "SELECT * FROM Scientists WHERE Birth > "+ commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "less" || operatorOf == "Less")
        {
            string query_string = "SELECT * FROM Scientists WHERE Birth < " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "equal" || operatorOf == "Equal")
        {
            string query_string = "SELECT * FROM Scientists WHERE Birth = " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
    }
    else if (variable == "Death" || variable == "death")
    {
        if (operatorOf == "greater" || operatorOf == "Greater")
        {
            string query_string = "SELECT * FROM Scientists WHERE Death > "+ commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "less" || operatorOf == "Less")
        {
            string query_string = "SELECT * FROM Scientists WHERE Death < " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "equal" || operatorOf == "Equal")
        {
            string query_string = "SELECT * FROM Scientists WHERE Death = " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
    }

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idCitation = query.record().indexOf("citation");
    int idStatus = query.record().indexOf("status");

    while (query.next())
    {
       Scientist pl;

       QString qId = query.value(idId).toString();
       QString qName = query.value(idName).toString();
       QString qSex = query.value(idSex).toString();
       QString qBirth = query.value(idBirth).toString();
       QString qDeath = query.value(idDeath).toString();
       QString qCitation = query.value(idCitation).toString();
       QString qStatus = query.value(idStatus).toString();

       int id = qId.toInt();
       std::string name = qName.toStdString();
       std::string sex =  qSex.toStdString();
       int birth = qBirth.toInt();
       int death = qDeath.toInt();
       std::string citation = qCitation.toStdString();
       int status = qStatus.toInt();
       if (status == 1)
       {
           pl.setId(id);
           pl.setName(name);
           pl.setSex(sex);
           pl.setBirth(birth);
           pl.setDeath(death);
           pl.setCitation(citation);

           sci.push_back(pl);
       }
    }
    m_db.close();



    return sci;
}
/**
 * @brief This function checks if the new Scientist is already in the list
 * @return true or false
 */
bool ScientistAccess::checkEntry(Scientist scientist)
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
