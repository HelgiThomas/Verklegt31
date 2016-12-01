#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class Scientist
{
public:
    Scientist();
    Scientist(string name, string sex, int birth, int death, string citation);
    string getName () const;
    string getSex () const;
    string getCitation () const;
    int getBirth () const;
    int getDeath () const;

    void setName (string name);
    void setSex (string sex);
    void setCitation(string citation);
    void setBirth (int birth);
    void setDeath (int death);

private:
    string _name;
    string _sex;
    string _citation;
    int _birth;
    int _death;
};

#endif // PERFORMER_H
