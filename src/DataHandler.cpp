#include "DataHandler.h"


DataHandler::DataHandler(const string &airlines_file, const string &airports_file, const string &flights_file) {
    AirlinesParse(airlines_file);
    AirportsParse(airports_file);
    FlightsParse(flights_file);
}

bool DataHandler::AirlinesParse(const string &airlines_file) {
    return true;
}

bool DataHandler::AirportsParse(const string &airports_file) {
    return true;
}

bool DataHandler::FlightsParse(const string &flights_file) {
    return true;
}
