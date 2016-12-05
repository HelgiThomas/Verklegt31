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
bool DataAccess::checkEntry(Scientist scientist)
{
    /*
    vector <Scientist> temp;
    temp = readFromFile();
    for (unsigned int i = 0 ; i < temp.size()-1; i++)
    {
        if (scientist.getName() == temp[i].getName() && scientist.getSex() == temp[i].getSex() &&
                scientist.getBirth() == temp[i].getBirth() && scientist.getDeath() == temp[i].getDeath())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
    */
}


void DataAccess::removeScientistlist (string name)
{

}

/**
 * @brief This functions erases everything that is in the file and adds the first entry.
 * @param string name.
 */
void DataAccess::firstEntry (Scientist scientist)
{
    /*
    ifstream inputfile("ComputerScientist.txt");
    ofstream outputfile("ComputerScientist.txt");

    // These two #ifdef sentences are used to solve a problem with running the program
    // on different platforms, apple and windows.
    // If the user is running on a windows computer the following code is executed.
    #ifdef _WIN32
        if(!(inputfile.std::ifstream::peek() == EOF))
        {
            outputfile << endl;
        }
    #endif
    // If the user is running on a apple computer the following code is executed.
    #ifdef __APPLE__
        if(inputfile.tellg() > 0)
        {
            outputfile << endl;
        }
     #endif

    outputfile << scientist.getName() << endl;
    outputfile << scientist.getSex() << endl;
    outputfile << scientist.getBirth() << endl;
    outputfile << scientist.getDeath() << endl;
    outputfile << scientist.getCitation();
    outputfile.close();
    */
}

void DataAccess::secondEntry (Scientist scientist)

{

}

/**
 * @brief This is a helper function that writes people in the file.
 * @param string name.
 */
void DataAccess::fileWork (Scientist scientist)
{

}
