#include "model/computer.h"

using namespace std;

/**
 * @brief This is the default constructor.
 */
Computer::Computer()
{
   _name = "";
   _buildYear = 0;
   _compType = "";
   _wasBuilt = "";
}

/**
 * @brief This function is a constructor that sets the information about
 * each computer.
 * @param string name, sets the name.
 * @param int buildYear, sets the year computer was built (if it was built, else 0).
 * @param string compType, sets the computer type.
 * @param string wasBuilt, sets either "Yes" or "No" whether the computer was built or not.
 */
Computer::Computer(string name, int buildYear, string compType, string wasBuilt)
{
    _name = name;
    _buildYear = buildYear;
    _compType = compType;
    _wasBuilt = wasBuilt;
}

/**
 * @brief This function returns the name.
 * @return string name.
 */
string Computer::getName () const
{
    return _name;
}

/**
 * @brief This function returns the year the computer was built.
 * @return int buildYear.
 */
int Computer::getBuildYear () const
{
    return _buildYear;
}

/**
 * @brief This function returns the computer type.
 * @return string compType.
 */
string Computer::getCompType()const
{
    return _compType;
}

/**
 * @brief This function returns whether the computer was built or not (a "Yes" or a "No").
 * @return string wasBuilt.
 */
string Computer:: getWasBuilt()const
{
    return _wasBuilt;
}


/**
 * @brief This function sets the name.
 * @param string name.
 */
void Computer::setName (string name)
{
    _name = name;
}

/**
 * @brief This function sets the year the computer was built.
 * @param int buildYear.
 */
void Computer::setBuildYear(int buildYear)
{
    _buildYear = buildYear;
}

/**
 * @brief This function sets the computer type.
 * @param string compType.
 */
void Computer::setCompType(string compType)
{
    _compType = compType;
}

/**
 * @brief This function sets whether the computer was built or not(a "Yes" or a "No").
 * @param string wasBuilt.
 */
void Computer::setWasBuilt(string wasBuilt)
{
    _wasBuilt = wasBuilt;
}
