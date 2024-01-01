#include "Application.h"

Application::Application() {}

void Application::run() {
    cout << "Please hold on for further instructions while the program loads its data." << endl << "It should take around 1 minute and 45 seconds.";
    DataHandler CSV_Data("../resources/airlines.csv", "../resources/airports.csv", "../resources/flights.csv");
    Airline::setAirlines(CSV_Data.getParsedAirlines());
    Airport::setAirports(CSV_Data.getParsedAirports());
    Flight::setFlights(CSV_Data.getParsedFlights());
    Script script(CSV_Data.getNetwork());
    script.run();
}
