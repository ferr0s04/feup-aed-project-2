#ifndef PROJ2_AED_SCRIPT_H
#define PROJ2_AED_SCRIPT_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include "Graph.h"

using namespace std;

class Script {
public:

    /**
     * Function to execute terminal I/O and program functionalities.
     */
    void run();

    /**
     * Constructor for Script class.
     * @param n graph used by the program for some functionalities
     */
    Script(Graph n);
private:
    ifstream input;
    Graph network;

    /**
     * Function for showing the list of available commands.
     */
    void help();

    /**
     * Function for showing total number of airports, airlines and flights.
     */
    void globalStats();

    /**
     * Function for showing number of available flights of a airline or from a city.
     */
    void flights_per_city();

    /**
     * Function for showing number of flights out of an airport and corresponding number of airlines.
     */
    void flightsAirport();

    /**
     * Function for showing the list of airports of a given country.
     */
    void airportsCountry();

    /**
     * Function for showing number of available cities, airports and countries for a given airport.
     * The list of cities and countries is also shown
     */
    void destinations();

    /**
     * Function for showing the top-k airports with most total traffic capacity. Length k is user-defined.
     */
    void topCapacity();

    /**
     * Function that chooses between a list of countries available from a city or from a country.
     */
    void countriesFromAirportOrCityCount();

    /**
     * Function to calculate the number of available countries from an airport.
     * @param airport_code code of the airport
     * @return set with available countries
     */
    set<string> countriesFromAirport(const string& airport_code);

    /**
     * Function to calculate the number of available countries from a city.
     */
    void countriesFromCityCount();

    /**
     * Function that indicates which airports are essential.
     */
    void essencial();

    /**
     * Function that indicates the number of possible flights given an airport with x stops.
     */
    void xvindoAeroporto();

    /**
     * Auxiliary function for 'xvindoAeroporto'
     * @param v airport vertex
     * @param stops number of lay-overs
     * @param tempList set of cities
     */
    void dfsCities(Vertex *v, int stops, set<string> &tempList);

    /**
     * Auxiliary function for 'xvindoAeroporto'
     * @param v airport vertex
     * @param stops number of lay-overs
     * @param tempList set of countries
     */
    void dfsCountries(Vertex *v, int stops, set<string> &tempList);

    /**
     * Auxiliary function for 'xvindoAeroporto'
     * @param v airport vertex
     * @param stops number of lay-overs
     * @param tempList set of airports
     */
    void dfsAirports(Vertex *v, int stops, set<string> &tempList);
};


#endif //PROJ2_AED_SCRIPT_H
