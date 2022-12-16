

#ifndef TEMA2POO_ENTERTAINMENT_H
#define TEMA2POO_ENTERTAINMENT_H

#include <string>
using namespace std;

class Entertainment {
    string name;
    int duration;

public:

    Entertainment(const string &name, int duration);

    Entertainment(const Entertainment &ent);

    const string &getName() const;

    void setName(const string &name);

    int getDuration() const;

    void setDuration(int duration);

    bool operator==(const Entertainment &rhs) const;

    bool operator!=(const Entertainment &rhs) const;

    friend istream& operator>>(istream &is, Entertainment &e);

    // Metoda virtuala pura:

    virtual void watchTime() const = 0;

    virtual ~Entertainment();

};


#endif //TEMA2POO_ENTERTAINMENT_H
