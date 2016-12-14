#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>

using namespace std;

/**
 * @brief The Computer class, creates a computer model.
 */
class Computer
{
public:
    /**
     * @brief Computer, Default constructors for the class Computer.
     * @param int id, string name, int buildYear, string compType, string wasBuilt
     */
    Computer();
    Computer(int id, string name, int buildYear, string compType, string wasBuilt, string Description);

    /**
     * @brief getId/Name/BuildYear/CompType/WasBuilt/Desctipion, Get functions for the class to
     * return the private variables of the class.
     * @return id, name, buildYear, compType, wasBuilt, description.
     */
    int getId() const;
    string getName() const;
    int getBuildYear() const;
    string getCompType() const;
    string getWasBuilt() const;
    string getDescription() const;

    /**
     * @brief setId/NAme/BuildYear/WasBuilt/Description, set functions for the class to return the private variables of the class.
     * @param int id, string name, int buildYear, string compType, string wasBuilt, string description
     */
    void setId(int id);
    void setName(string name);
    void setBuildYear (int buildYear);
    void setCompType(string compType);
    void setWasBuilt(string wasBuilt);
    void setDescription(string description);

private:
    int _id;
    string _name;
    int _buildYear;
    string _compType;
    string _wasBuilt;
    string _description;
};

#endif // COMPUTER_H
