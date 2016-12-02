#include "model/scientist.h"

using namespace std;

/**
 * @brief This is the default constructor.
 */
Scientist::Scientist()
{
    _name = "";
    _sex = "";
    _birth = 0;
    _death = 0;
    _citation = "";
}

/**
 * @brief This function is a constructor that sets the information about
 * each scientist.
 * @param string name, sets the name.
 * @param string sex, sets the sex.
 * @param int birth, sets the birth year.
 * @param int death, sets the death year.
 */
Scientist::Scientist(string name,string sex, int birth, int death , string citation)
{
    _name = name;
    _sex = sex;
    _birth = birth;
    _death = death;
    _citation = citation;
}

/**
 * @brief This function returns the name.
 * @return string name.
 */
string Scientist::getName () const
{
    return _name;
}

/**
 * @brief This function returns the sex.
 * @return string sex.
 */
string Scientist::getSex () const
{
    return _sex;
}

/**
 * @brief This function returns the birth year.
 * @return int birth.
 */
int Scientist::getBirth () const
{
    return _birth;
}

/**
 * @brief This function returns the death year.
 * @return int death.
 */
int Scientist:: getDeath () const
{
    return _death;
}

/**
 * @brief This function returns the citation.
 * @return string citation.
 */
string Scientist:: getCitation() const
{
    return _citation;
}

/**
 * @brief This function sets the name.
 * @param string name.
 */
void Scientist::setName (string name)
{
    _name = name;
}

/**
 * @brief This function sets the sex.
 * @param string sex.
 */
void Scientist::setSex (string sex)
{
    _sex = sex;
}

/**
 * @brief This function sets the citation.
 * @param string citation.
 */
void Scientist::setCitation(string citation)
{
    _citation = citation;
}

/**
 * @brief This function sets the birth year.
 * @param int birth.
 */
void Scientist::setBirth (int birth)
{
    _birth = birth;
}

/**
 * @brief This function sets the death year.
 * @param int death.
 */
void Scientist::setDeath (int death)
{
    _death = death;
}
