#include "data/dataaccess.h"

using namespace std;

/*
 * This is the default constructor.
 */
DataAccess::DataAccess()
{

}

/*
 * This function writes/reads into the file ComputerScientists.txt when a new scientist
 * is added.
 * @param: Scientist variable.
 */
void DataAccess::readToFile(Scientist scientist)
{

    if (checkEntry (scientist))
    {
        cout << "An entry like that already exists!" << endl;
    }
    else
    {
        fileWork(scientist);
    }

}

/*
 * A function that opens the file ComputerScientist.txt and returns a vector
 * containing all the scientists which are in the database.
 * @return: Scientist vector of people in the file.
 */
vector<Scientist> DataAccess::readFromFile()
{
    ifstream thefile;
    vector<Scientist> sci;
    thefile.open("ComputerScientist.txt");

    if (thefile.is_open())
    {
        while (!(thefile.eof()))
        {
            Scientist pl;
            string name;
            string sex;
            string citation;
            int birth;
            int death;


            std::getline(thefile, name);
            thefile >> sex >> birth >> death;
            std::getline(thefile, citation);
            std::getline(thefile, citation);


            pl.setName(name);
            pl.setSex(sex);
            pl.setBirth(birth);
            pl.setDeath(death);
            pl.setCitation(citation);

            sci.push_back(pl);


        }
    }
    else
    {
        cout << "Error opening file!" << endl;
    }

    thefile.close ();
    return sci;
}

/*
 * A bool function to check whether the scientist entry already exists.
 * @param: Scientist variable.
 * @return: true/false.
 */
bool DataAccess::checkEntry(Scientist scientist)
{
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
}
<<<<<<< HEAD

/*
 *
=======
/*
 * This function removes selected scientist from list.
 * @param: string name.
>>>>>>> e387eb70126c4cbaae05dd931433e720977abd2d
 */
void DataAccess::removeScientistlist (string name)
{
    vector <Scientist> remove;
    vector <Scientist> temp;
    remove = readFromFile();

    for (unsigned int i = 0; i < remove.size();i++)
    {
        //removes entered name from vector
        if (!(name == remove[i].getName()))
        {
            temp.push_back(remove[i]);
        }
    }
    // If there is only one entry in the file
    if (temp.size() == 0)
    {
        ifstream inputfile("ComputerScientist.txt");
        ofstream outputfile("ComputerScientist.txt");
    }
    else
    {
        for (unsigned int i = 0; i < temp.size();i++)
        {
            if (_temp == 0)
            {
               firstEntry (temp[i]);
            }
            else if (_temp > 0)
            {
               secondEntry (temp[i]);
            }
             _temp++;

          }
        _temp = 0;
    }


}
<<<<<<< HEAD

/*
 *
=======
/*
 * This functions erases everything that is in the file and adds the first entry.
 * @param: string name.
>>>>>>> e387eb70126c4cbaae05dd931433e720977abd2d
 */
void DataAccess::firstEntry (Scientist scientist)
{
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
}
<<<<<<< HEAD

/*
 *
=======
/*
 * This functions adds the rest of the entries to the file
 * @param: string name.
>>>>>>> e387eb70126c4cbaae05dd931433e720977abd2d
 */
void DataAccess::secondEntry (Scientist scientist)
{
    ifstream inputfile("ComputerScientist.txt", ios::app);
    ofstream outputfile("ComputerScientist.txt", ios::app);

    fileWork(scientist);
}
void DataAccess::fileWork (Scientist scientist)
{
    ifstream inputfile("ComputerScientist.txt", ios::app);
    ofstream outputfile ("ComputerScientist.txt", ios::app);

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
}
