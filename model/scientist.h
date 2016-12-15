#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

/**
 * @brief The Scientist class, to create the abstract data type Scientist.
 */
class Scientist
{
public:
    /**
     * @brief Scientist, Default constructors for the class Scientist.
     */
    Scientist();
    Scientist(int id, string name, string sex, int birth, int death, string citation, string image);

    /**
     * @brief Get functions for the class to return the private variables of the class.
     * @return int id, string name, string sex, string citation, int birth and int death.
     */
    int getId() const;
    string getName () const;
    string getSex () const;
    string getCitation () const;
    int getBirth () const;
    int getDeath () const;
    string getImage() const;

    /**
     * @brief Set functions for the class to return the private variables of the class.
     * @param int id, string name, string sex, string citation, int birth, int death.
     */
    void setId(int id);
    void setName (string name);
    void setSex (string sex);
    void setCitation(string citation);
    void setBirth (int birth);
    void setDeath (int death);
    void setImage(string image);

private:
    int _id;
    string _name;
    string _sex;
    string _citation;
    string _image;
    int _birth;
    int _death;
};

#endif // PERFORMER_H
