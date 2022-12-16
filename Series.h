
#ifndef TEMA2POO_SERIES_H
#define TEMA2POO_SERIES_H

#include <iostream>
#include <string>
#include "Entertainment.h"

using namespace std;

class Series : public Entertainment{

    int nrOfEpisodes;

public:
    Series(const string &name, int duration, int nrOfEpisodes);

    Series(Series &s);

    int getNrOfEpisodes() const;

    void setNrOfEpisodes(int nrOfEpisodes) ;

    virtual void watchTime() const override;

    friend std::ostream& operator<<(std::ostream &os, Series &s) ;

};
#endif //TEMA2POO_SERIES_H
