#ifndef PROJ2_AED_DATAHANDLER_H
#define PROJ2_AED_DATAHANDLER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "Graph.h"
using namespace std;


class DataHandler {
public:
    DataHandler(const string& airlines_file, const string& airports_file, const string& flights_file);
    bool AirlinesParse(const string& airlines_file);
    bool AirportsParse(const string& airports_file);
    bool FlightsParse(const string& flights_file);
    vector<Airline> getParsedAirlines();
    vector<Airport> getParsedAirports();
    vector<Flight> getParsedFlights();
private:
    Graph<Airport> network;
    vector<Airline> parsedAirlines;
    vector<Airport> parsedAirports;
    vector<Flight> parsedFlights;
    void readCSV(const string& filename, vector<string>& data);
};


#endif //PROJ2_AED_DATAHANDLER_H
