#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>
using namespace std;

class Performer
{
public:
    Performer();
    Performer (string name, string sex, int birth, int death);
    string getName () const;
    string getSex () const;
    int getBirth () const;
    int getDeath () const;

private:
    string _name;
    string _sex;
    int _birth;
    int _death;
};

#endif // PERFORMER_H
