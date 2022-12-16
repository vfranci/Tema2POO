#include "Series.h"

//Clasa Series este derivata din Entertainment

Series::Series(const string &name, int duration, int nrOfEpisodes) : Entertainment(name, duration),
                                                             nrOfEpisodes(nrOfEpisodes) {}

Series::Series(Series &s) : Entertainment(s) {
    nrOfEpisodes = s.nrOfEpisodes;
}


int Series::getNrOfEpisodes() const {
    return nrOfEpisodes;
}

void Series::setNrOfEpisodes(int nrOfEpisodes) {
    Series::nrOfEpisodes = nrOfEpisodes;
}

void Series::watchTime() const {
    int duration = getDuration();
    int nrOfEps = getNrOfEpisodes();
    cout << "Timpul total de vizionare pentru " << getName() << " este de "<< duration*nrOfEps << " minute." << endl;
}

ostream& operator<<(std::ostream &os, Series &s) {
    os << "Serialul `" << s.getName() << "` " << endl;
    return os;
}
