#include "Airline.h"

Airline::Airline(const string &code, const string &name, const string &callsign, const string &country)
: code(code), name(name), callsign(callsign), country(country) {}

string Airline::getAirlineCode() const {
    return code;
}

string Airline::getAirlineName() const {
    return name;
}

string Airline::getAirlineCallsign() const {
    return callsign;
}

string Airline::getAirlineCountry() const {
    return country;
}

void Airline::setAirlines(vector<Airline> airlines_data) {
    airlines = move(airlines_data);
}

vector<Airline> Airline::getAirlines() {
    return airlines;
}

vector<Airline> Airline::airlines;
