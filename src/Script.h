#ifndef PROJ2_AED_SCRIPT_H
#define PROJ2_AED_SCRIPT_H
#include <fstream>
#include <iostream>
#include "Airport.h"
#include "Flight.h"

using namespace std;

class Script {
public:
    void run();
private:
    ifstream input;
    Airport airport = Airport("", "", "", "", 0, 0);
    Flight flight = Flight("", "", "");
    void help();
    void globalStats();
};


#endif //PROJ2_AED_SCRIPT_H
