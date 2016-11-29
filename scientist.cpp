#include "performer.h"

using namespace std;

Performer::Performer()
{

}
Performer::Performer (string name,string sex, int birth, int death)
{
    _name = name;
    _sex = sex;
    _birth = birth;
    _death = death;

}

string Performer::getName () const
{
    return _name;
}
string Performer:: getSex () const
{
    return _sex;
}
int Performer::getBirth () const
{
    return _birth;
}
int Performer:: getDeath () const
{
    return _death;
}
