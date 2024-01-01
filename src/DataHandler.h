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

    /**
    * Constructor for DataHandler class
    * @param airlines_file path for airlines.csv
    * @param airports_file path for airports.csv
    * @param flights_file path for flights.csv
    */
    DataHandler(const string& airlines_file, const string& airports_file, const string& flights_file);

    /**
    * Function for parsing airline data
    * @param airlines_file path for airlines.csv
    * @return true if the parsing was complete
    */
    bool AirlinesParse(const string& airlines_file);

    /**
    * Function for parsing airport data
    * @param airports_file path for airports.csv
    * @return true if the parsing was complete
    */
    bool AirportsParse(const string& airports_file);

    /**
    * Function for parsing flight data
    * @param flights_file path for flights.csv
    * @return true if the parsing was complete
    */
    bool FlightsParse(const string& flights_file);

    /**
    * Function to get parsed/processed airlines
    * @return vector with all parsed airlines
    */
    vector<Airline> getParsedAirlines();

    /**
    * Function to get parsed/processed airports
    * @return vector with all parsed airports
    */
    vector<Airport> getParsedAirports();

    /**
    * Function to get parsed/processed flights
    * @return vector with all parsed flights
    */
    vector<Flight> getParsedFlights();

    /**
    * Function to get the network graph
    * @return graph that represents the airports/flights network
    */
    Graph getNetwork();
private:
    Graph network;
    vector<Airline> parsedAirlines;
    vector<Airport> parsedAirports;
    vector<Flight> parsedFlights;

    /**
    * Function for reading CSV files and save its data into a vector of strings
    * @param filename path for CSV file
    * @param data vector where the data will be saved
    */
    void readCSV(const string& filename, vector<string>& data);
};


#endif //PROJ2_AED_DATAHANDLER_H
