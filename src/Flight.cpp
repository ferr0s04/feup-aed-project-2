#include "Flight.h"

Flight::Flight(const string &source, const string &target, const string &airline)
    : source(source), target(target), airline(airline) {}

void Flight::setFlights(vector<Flight> flights_data) {
    flights = move(flights_data);
}

vector<Flight> Flight::getFlights() {
    return flights;
}

string Flight::getsource() {
    return source;
}

string Flight::gettarget() {
    return target;
}

string Flight::getairline() {
    return airline;
}

vector<Flight> Flight::flights;
