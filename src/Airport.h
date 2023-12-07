#ifndef PROJ2_AED_AIRPORT_H
#define PROJ2_AED_AIRPORT_H

#include <string>
#include <vector>

using namespace std;

class Airport {
public:
    Airport(const string& code, const string& name, const string& city, const string& country, const double& latitude, const double& longitude);
private:
    const string code;
    const string name;
    const string city;
    const string country;
    const double latitude;
    const double longitude;
    static vector<Airport> airports;
};


#endif //PROJ2_AED_AIRPORT_H
