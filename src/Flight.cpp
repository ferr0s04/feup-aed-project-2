#include "Flight.h"

Flight::Flight(const string &source, const string &target, const string &airline)
        : source(source), target(target), airline(airline) {}

void Flight::setFlights(vector<Flight> flights_data) {
    flights = move(flights_data);
}

vector<Flight> Flight::getFlights() {
    return flights;
}

string Flight::getSource() {
    return source;
}

string Flight::getAirline() {
    return airline;
}

string Flight::getTarget() {
    return target;
}

vector<Flight> Flight::flights;
