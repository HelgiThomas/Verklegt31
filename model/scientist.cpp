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
Scientist::Scientist(string name,string sex, int birth, int death)
{
    _name = name;
    _sex = sex;
    _birth = birth;
    _death = death;

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
