#include "data/computeraccess.h"

#include <sstream>

using namespace std;

ComputerAccess::ComputerAccess()
{
    _temp = 0;
}

/**
 * @brief This function reads all the Computrs from SQL database that have status = 1 and adds them to a vector.
 * @return vector of Computers
 */
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
    closeConn();

    return com;
}

/**
 * @brief This function reads the new Computer to the SQL database and adds them to a vector.
 * @param vector of Computers
 */
void ComputerAccess::readToDatabase(Computer computer)
{
    int number = 1;

    connect();

    if (checkEntry(computer))
    {
        cout << computer.getBuildYear();
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
    closeConn();
}

/**
 * @brief This function sets status = 0 for the selected Computer from the SQL database
 * @param int nameOf
 */
void ComputerAccess::removelist(int nameOf)
{
    int number = 0;
    cout << nameOf;
    connect();

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::number(nameOf);
    query.prepare("UPDATE Computers SET Status = 0 WHERE ID = (:nameOf)");
    query.bindValue(":nameOf", qName);
    query.bindValue(":status", qStatus);

    query.exec();

    closeConn();
}

/**
 * @brief This function sets the status = 0 for all Computers in the SQL database
 */
void ComputerAccess::removeAll()
{
    connect();

    QSqlQuery query;
    query.prepare("UPDATE Computers SET Status = 0");
    query.exec();

    closeConn();
}

/**
 * @brief This function lets the User edit the string elements in the selected entry of Computer in the SQL Datbase
 * @param int nameOf, string variable, string newElement
 */
void ComputerAccess::editString(string nameOf, string variable, string newElement)
{
    connect();
    QSqlQuery query;

    QString qNameOf = QString::fromStdString(nameOf);
    QString qNewElement = QString::fromStdString(newElement);

    if (variable == "Name" || variable == "name")
    {
        query.prepare("UPDATE Computers SET Name = :newElement WHERE Name = :name");
        query.bindValue(":newElement", qNewElement);
        query.bindValue(":name", qNameOf);
    }
    else if (variable == "Type" || variable == "type")
    {
        query.prepare("UPDATE Computers SET type = :newElement WHERE Name = :name");
        query.bindValue(":newElement", qNewElement);
        query.bindValue(":name", qNameOf);
    }
    else if (variable == "Built" || variable == "built")
    {
        query.prepare("UPDATE Computers SET wasBuilt = :newElement WHERE Name = :name");
        query.bindValue(":newElement", qNewElement);
        query.bindValue(":name", qNameOf);
    }

    query.exec();

    closeConn();
}

/**
 * @brief This function lets the User edit the int elements in the selected entry of Computer in the SQL Datbase
 * @param int nameOf, string variable, int newElement
 */
void ComputerAccess::editInt(string nameOf, string variable, int newElement)
{
    connect();

    QSqlQuery query;
    string newElementStr;
    newElementStr = to_string(newElement);

    QString qNameOf = QString::fromStdString(nameOf);
    QString qNewElement = QString::number(newElement);

    if (variable == "Year" || variable == "year")
    {
        query.prepare("UPDATE Computers SET year = :newElement WHERE Name = :name");
        query.bindValue(":name", qNameOf);
        query.bindValue(":newElement", qNewElement);
    }
    query.exec();

    closeConn();
}

/**
 * @brief This function sorts the Computersin an vector according the the selected variable and selected command ("ASC" or "DESC")
 * @param string var, string command
 * @return vector of Computers
 */
vector<Computer> ComputerAccess::sortQuery(string var, string command)
{
    connect();
    vector<Computer> comp;

    QSqlQuery query;

    string query_string = "SELECT * FROM Computers ORDER BY " + var + " " + command;
    QString qCommand (query_string.c_str());
    query.exec(qCommand);

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

            comp.push_back(pl);
        }
    }
    closeConn();

    return comp;
}

/**
 * @brief This function searches the Computers in the SQL Database after the selcted variable (String) and the newCommand ("new name, new sex...") and puts them in a vector
 * @param string variable, string command
 * @return vector of Computers
 */
vector<Computer> ComputerAccess::searchQueryString(string variable,string command)
{
    connect();


    QSqlQuery query;
    vector<Computer> comp;


    if (variable == "Name" || variable == "name")
    {
        string query_string = "SELECT * FROM Computers WHERE Name LIKE '" + command + "%'";
        QString qCommand (query_string.c_str());
        query.exec(qCommand);
    }
    else if (variable == "Type" || variable == "type")
    {
        string query_string = "SELECT * FROM Computers WHERE Type LIKE '" + command + "%'";
        QString qCommand (query_string.c_str());
        query.exec(qCommand);
    }
    else if (variable == "wasbuilt" || variable == "wasBuilt" || variable == "WasBuilt" || variable == "Wasbuilt")
    {
        cout << variable << " " << command;
        string query_string = "SELECT * FROM Computers WHERE wasBuilt LIKE '" + command + "%'";
        QString qCommand (query_string.c_str());
        query.exec(qCommand);
    }

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

            comp.push_back(pl);
        }
    }
    closeConn();

    return comp;
}

/**
 * @brief This function searches the Computers in the SQL Database after the selcted variable (Int) and the newCommand ("new year...") and puts them in a vector
 * @param string variable, string operatorOf, string command
 * @return vector of Computers
 */
vector<Computer> ComputerAccess::searchQueryInt(string variable, string operatorOf, int command)
{
    connect();
    string commandStr;
    commandStr = to_string(command);
    QSqlQuery query;
    vector <Computer> comp;

    if (variable == "Year" || variable == "year")
    {
        if (operatorOf == "greater" || operatorOf == "Greater")
        {
            string query_string = "SELECT * FROM Computers WHERE Year > "+ commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "less" || operatorOf == "Less")
        {
            string query_string = "SELECT * FROM Computers WHERE Year < " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
        else if (operatorOf == "equal" || operatorOf == "Equal")
        {
            string query_string = "SELECT * FROM Computers WHERE Year = " + commandStr;
            QString qCommand (query_string.c_str());
            query.exec(qCommand);
        }
    }

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

            comp.push_back(pl);
        }
    }
   closeConn();;

    return comp;
}

/**
 * @brief This function checks if the new Computer is already in the list
 * @return true or false
 */
bool ComputerAccess::checkEntry(Computer computer)
{
    QSqlQuery query("SELECT * FROM Computers");

    QString Name = QString::fromStdString(computer.getName());
    QString Type = QString::fromStdString(computer.getCompType());
    QString Built = QString::fromStdString(computer.getWasBuilt());

    while (query.next())
    {
        int idName = query.record().indexOf("name");
        int idType = query.record().indexOf("type");
        int idBuilt = query.record().indexOf("wasbuilt");
        int idStatus = query.record().indexOf("Status");

        QString qName = query.value(idName).toString();
        QString qType = query.value(idType).toString();
        QString qBuilt = query.value(idBuilt).toString();
        QString qStatus = query.value(idStatus).toString();

        if (Name == qName && Type == qType && Built == qBuilt)
        {
            cout << "This person already exist! ";
            return false;
        }
    }
    return true;
}

/**
 * @brief This function connects QT to the SQL database
 */
void ComputerAccess::connect()
{
    if (!m_db.isOpen())
    {
        m_db = QSqlDatabase::addDatabase("QSQLITE");
        m_db.setDatabaseName("DB_vika2.sqlite");

        m_db.open();
    }
}

/**
 * @brief ComputerAccess::closeConn, close the SQL database connection
 */
void ComputerAccess::closeConn()
{
    QString conn;
    conn = m_db.connectionName();
    m_db.close();
    m_db = QSqlDatabase();
    m_db.removeDatabase(conn);
}
