
#ifndef TEMA2POO_MOVIE_H
#define TEMA2POO_MOVIE_H

#include "Entertainment.h"
#include <string>

class Movie : public Entertainment{

    int releaseYear;

public:

    Movie(const string &name, int duration, int releaseYear);

    Movie(Movie &m);

    Movie(const string &name, int duration, Movie &m);

    int getReleaseYear() const;

    void setReleaseYear(int releaseYear);

    friend std::ostream& operator<<(std::ostream &os, Movie &m);

    virtual void watchTime() const override;

    ~Movie();

    bool operator==(const Movie &rhs) const;

    bool operator!=(const Movie &rhs) const;


};

#endif //TEMA2POO_MOVIE_H
