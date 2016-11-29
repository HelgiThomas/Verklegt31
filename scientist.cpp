#include "scientist.h"

using namespace std;

Scientist::Scientist()
{

}

Scientist::Scientist(string name, string sex, int birth)
{
    _name = name;
    _sex = sex;
    _birth = birth;
}

Scientist::Scientist(string name,string sex, int birth, int death)
{
    _name = name;
    _sex = sex;
    _birth = birth;
    _death = death;

}

string Scientist::getName () const
{
    return _name;
}

string Scientist::getSex () const
{
    return _sex;
}

int Scientist::getBirth () const
{
    return _birth;
}

int Scientist:: getDeath () const
{
    return _death;
}
