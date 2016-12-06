#ifndef COMPUTER_H
#define COMPUTER_H
#include <iostream>

using namespace std;

class Computer
{
public:
    /**
     * @brief Default constructors for the class Computer.
     */
    Computer();
    Computer(string name, int buildYear, string compType, string wasBuilt);

    /**
     * @brief Get functions for the class to return the private variables of the class.
     * @return name, buildYear, compType, wasBuilt.
     */
    string getName () const;
    int getBuildYear () const;
    string getCompType () const;
    string getWasBuilt() const;
    string getDescription() const;

    /**
     * @brief Set functions for the class to return the private variables of the class.
     * @param name, buildYear, compType, wasBuilt.
     */
    void setName (string name);
    void setBuildYear (int buildYear);
    void setCompType(string compType);
    void setWasBuilt(string wasBuilt);
    void setDescription(string description);

private:
    string _name;
    int _buildYear;
    string _compType;
    string _wasBuilt;
    string _description;
};

#endif // COMPUTER_H
