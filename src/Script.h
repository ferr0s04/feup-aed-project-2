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

using namespace std;

class Script {
public:
    void run();
private:
    ifstream input;
    void help();
    void globalStats();
    void flights_per_city();
    void flightsAirport();
    void airportsCountry();
    void destinations();
    void topCapacity();
};


#endif //PROJ2_AED_SCRIPT_H
