#include "model/scientist.h"

using namespace std;

/*
 * This is the default constructor.
 */
Scientist::Scientist()
{

}

/*
 * This function is a constructor that sets the information about
 * each scientist.
 * @param: string name, sets the name.
 * @param: string sex, sets the sex.
 * @param: int birth, sets the birth year.
 * @param: int death, sets the death year.
 */
Scientist::Scientist(string name,string sex, int birth, int death , string citation)
{
    _name = name;
    _sex = sex;
    _birth = birth;
    _death = death;
    _citation = citation;

}

/*
 * This function returns the name.
 * @return: string name.
 */
string Scientist::getName () const
{
    return _name;
}

/*
 * This function returns the sex.
 * @return: string sex.
 */
string Scientist::getSex () const
{
    return _sex;
}

/*
 * This function returns the birth year.
 * @return: int birth.
 */
int Scientist::getBirth () const
{
    return _birth;
}

/*
 * This function returns the death year.
 * @return: int death.
 */
int Scientist:: getDeath () const
{
    return _death;
}
string Scientist:: getCitation() const
{
    return _citation;
}
void Scientist::setName (string name)
{
    _name = name;
}

void Scientist::setSex (string sex)
{
    _sex = sex;
}

void Scientist::setCitation(string citation)
{
    _citation = citation;
}

void Scientist::setBirth (int birth)
{
    _birth = birth;
}

void Scientist::setDeath (int death)
{
    _death = death;
}
