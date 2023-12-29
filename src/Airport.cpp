#include "Airport.h"

Airport::Airport(const string &code, const string &name, const string &city, const string &country,
                 const double &latitude, const double &longitude)
                 : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}

void Airport::setAirports(vector<Airport> airports_data) {
    airports = move(airports_data);
}

vector<Airport> Airport::getAirports() {
    return airports;
}

string Airport::getcode() {
    return code;
}

string Airport::getname() {
    return name;
}

string Airport::getcountry() {
    return country;
}

string Airport::getcity() {
    return city;
}

double Airport::getlatitude() {
    return latitude;
}

double Airport::getlongitude() {
    return longitude;
}

vector<Airport> Airport::airports;
