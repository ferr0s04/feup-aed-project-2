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

string Airport::getCountry() const {
    return country;
}

double Airport::getLatitude() const {
    return latitude;
}

double Airport::getLongitude() const {
    return longitude;
}

string Airport::getCode() const {
    return code;
}

string Airport::getName() const {
    return name;
}

void Airport::addToAirports(){
    airports.push_back(*this);
}

bool Airport::operator<(const Airport& other) const {
    return code < other.code;
}

Airport& Airport::operator=(const Airport& other) {
    if (this != &other) {
        code = other.code;
        name = other.name;
        city = other.city;
        country = other.country;
        latitude = other.latitude;
        longitude = other.longitude;
    }
    return *this;
}

string Airport::getCity() const {
    return city;
}

vector<Airport> Airport::airports;
