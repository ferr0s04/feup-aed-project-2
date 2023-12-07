#ifndef PROJ2_AED_AIRLINE_H
#define PROJ2_AED_AIRLINE_H

#include <string>
#include <vector>
using namespace std;

class Airline {
public:
    Airline(const string& code, const string& name, const string& callsign, const string& country);
    string getAirlineCode() const;
    string getAirlineName() const;
    string getAirlineCallsign() const;
    string getAirlineCountry() const;
private:
    const string code;
    const string name;
    const string callsign;
    const string country;
    static vector<Airline> airlines;
};


#endif //PROJ2_AED_AIRLINE_H
