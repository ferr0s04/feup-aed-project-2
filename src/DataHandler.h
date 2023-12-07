#ifndef PROJ2_AED_DATAHANDLER_H
#define PROJ2_AED_DATAHANDLER_H

#include <string>
#include <vector>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
using namespace std;


class DataHandler {
public:
    DataHandler(const string& airlines_file, const string& airports_file, const string& flights_file);
    static bool AirlinesParse(const string& airlines_file);
    static bool AirportsParse(const string& airports_file);
    static bool FlightsParse(const string& flights_file);
private:
    static vector<Airline> parsedAirlines;
    static vector<Airport> parsedAirports;
    static vector<Flight> parsedFlights;
};


#endif //PROJ2_AED_DATAHANDLER_H
