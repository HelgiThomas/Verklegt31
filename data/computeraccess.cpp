#include "data/computeraccess.h"

using namespace std;

ComputerAccess::ComputerAccess()
{

}

void readToFile(Computer computer)
{
    int number = 1;
    util.connect();

    if (checkEntry(computer))
    {

        // you should check if args are ok first...
        QSqlQuery query;
        QString qId = QString::number(computer.getId());
        QString qName = QString::fromStdString(computer.getName());
        QString qSex = QString::fromStdString(computer.getSex());
        QString qBirth = QString::number(computer.getBirth());
        QString qDeath = QString::number(computer.getDeath());
        QString qStatus = QString::number(number);

        query.prepare("INSERT INTO Computers (id, name, sex, birth, death, status) VALUES (:id, :name, :sex, :birth, :death, :status)");
        query.bindValue(":id", qId);
        query.bindValue(":name", qName);
        query.bindValue(":sex", qSex);
        query.bindValue(":birth", qBirth);
        query.bindValue(":death", qDeath);
        query.bindValue(":status", qStatus);

        query.exec();
    }
}


void removeComputerlist(string name)
{
    int number = 0;

    QSqlQuery query;

    QString qStatus = QString::number(number);
    QString qName = QString::fromStdString(name);
    query.prepare("UPDATE Computers SET Status = 0 WHERE Name = (:name)");
    query.bindValue(":name", qName);
    query.bindValue(":status", qStatus);

    query.exec();
}


void removeEveryComputer()
{

}


vector<Computer> readFromFile()
{
    vector<Computer> com;
    connect();

    QSqlQuery query("SELECT * FROM Computers");

    int idId = query.record().indexOf("id");
    int idName = query.record().indexOf("name");
    int idSex= query.record().indexOf("sex");
    int idBirth = query.record().indexOf("birth");
    int idDeath = query.record().indexOf("death");
    int idStatus = query.record().indexOf("Status");
    while (query.next())
    {
       Computer pl;

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

    return com;
}


void editComputer(int id, string command)
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

bool checkEntry(Computer computer)
{
    QSqlQuery query("SELECT * FROM Computers");

    QString Id = QString::number(computer.getId());
    QString Name = QString::fromStdString(computer.getName());
    QString Sex = QString::fromStdString(computer.getSex());
    QString Birth = QString::number(computer.getBirth());
    QString Death = QString::number(computer.getDeath());

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
