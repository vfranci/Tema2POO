#include "Entertainment.h"
#include <iostream>

// Proiectul prezinta o implementare a unei liste de redare (asemanatoare celor de pe platformele de streaming)
// ce contine filme si seriale si cu care un user poate interactiona.
// Am creat astfel o clasa abstracta Entertainment, clasa de baza pentru filmele si serialele noastre.
// Am implementat getteri, setteri, constructor, constructor de copiere si am supraincarcat operatorii corespunzatori.


Entertainment::Entertainment(const string &name, int duration) : name(name), duration(duration){}

Entertainment::Entertainment(const Entertainment &ent) {

    name = ent.name;
    duration = ent.duration;
}

const string &Entertainment::getName() const {
    return name;
}

void Entertainment::setName(const string &name) {
    this->name = name;
}

int Entertainment::getDuration() const {
    return duration;
}

void Entertainment::setDuration(int duration) {
    this->duration = duration;
}

bool Entertainment::operator==(const Entertainment &rhs) const {
    return name == rhs.name &&
           duration == rhs.duration;
}

bool Entertainment::operator!=(const Entertainment &rhs) const {
    return !(rhs == *this);
}

istream& operator>>(istream &is, Entertainment &e){
    string buf;
    is >> buf;
    e.setName(buf);
    is >> e.duration;
    return is;
}

Entertainment::~Entertainment() { }