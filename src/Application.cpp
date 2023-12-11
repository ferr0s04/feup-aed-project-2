#include "Application.h"

Application::Application() {}

void Application::run() {
    DataHandler CSV_Data("resources/airlines.csv", "resources/airports.csv", "resources/flights.csv");
    Airline::setAirlines(CSV_Data.getParsedAirlines());
    Airport::setAirports(CSV_Data.getParsedAirports());
    Flight::setFlights(CSV_Data.getParsedFlights());
}
