#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <string>

using namespace std;

/**
 * @brief The Scientist class to create the abstract data type Scientist.
 */
class Scientist
{
public:
    /**
     * @brief Default constructors for the class Scientist.
     */
    Scientist();
    Scientist(int id, string name, string sex, int birth, int death, string citation);

    /**
     * @brief Get functions for the class to return the private variables of the class.
     * @return name, sex, citation, birth and death.
     */
    int getId() const;
    string getName () const;
    string getSex () const;
    string getCitation () const;
    int getBirth () const;
    int getDeath () const;

    /**
     * @brief Set functions for the class to return the private variables of the class.
     * @param name, sex, citation, birth, death.
     */
    void setId(int id);
    void setName (string name);
    void setSex (string sex);
    void setCitation(string citation);
    void setBirth (int birth);
    void setDeath (int death);

private:
    int _id;
    string _name;
    string _sex;
    string _citation;
    int _birth;
    int _death;
};

#endif // PERFORMER_H
