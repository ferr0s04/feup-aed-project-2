#ifndef PROJ2_AED_SCRIPT_H
#define PROJ2_AED_SCRIPT_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include "Graph.h"

using namespace std;

class Script {
public:
    void run();
    Script(Graph n);
private:
    ifstream input;
    Graph network;
    void help();
    void globalStats();
    void flights_per_city();
    void flightsAirport();
    void airportsCountry();
    void destinations();
    void topCapacity();
    void countriesFromAirportOrCityCount();
    set<string> countriesFromAirport(const string& airport_code);
    void countriesFromCityCount();
    void essencial();
    void xvindoAeroporto();
};


#endif //PROJ2_AED_SCRIPT_H
