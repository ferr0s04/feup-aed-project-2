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
    static void setAirlines(vector<Airline> airlines_data);
    static vector<Airline> getAirlines();
    Airline& operator=(const Airline& other){
        if (this != &other) {
            // Copy the values from the other object
            // into the current object
            const_cast<string&>(code) = other.code;
            const_cast<string&>(name) = other.name;
            const_cast<string&>(callsign) = other.callsign;
            const_cast<string&>(country) = other.country;
        }
        return *this;
    }
private:
    const string code;
    const string name;
    const string callsign;
    const string country;
    static vector<Airline> airlines;
};


#endif //PROJ2_AED_AIRLINE_H
