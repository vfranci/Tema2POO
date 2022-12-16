#include "Movie.h"
#include "InvalidInputException.h"
#include <iostream>
using namespace std;

// Clasa Movie este derivata din Entertainment.

Movie::Movie(const string &name, int duration, int releaseYear) : Entertainment(name, duration), releaseYear(releaseYear) {
    if(releaseYear > 2022)
        throw InvalidInputException("Invalid Input!");
}

Movie::Movie(Movie &m) : Entertainment(m) {
    releaseYear = m.releaseYear;

}


int Movie::getReleaseYear() const {
    return releaseYear;
}

void Movie::setReleaseYear(int releaseYear) {
    Movie::releaseYear = releaseYear;
}

bool Movie::operator==(const Movie &rhs) const {
    return static_cast<const Entertainment &>(*this) == static_cast<const Entertainment &>(rhs) &&
           releaseYear == rhs.releaseYear;
}

bool Movie::operator!=(const Movie &rhs) const {
    return !(rhs == *this);
}


ostream& operator<<(ostream &os, Movie &m) {

    os << "Filmul `" << m.getName() << "` lansat in anul " << m.getReleaseYear() << endl;
    return os;
}

void Movie::watchTime() const {
    cout<<"Timpul de vizionare pentru filmul `" << getName() << "` este de " << getDuration() <<" de minute." << endl;
}

Movie::~Movie() {}

