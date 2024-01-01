#ifndef PROJ2_AED_FLIGHT_H
#define PROJ2_AED_FLIGHT_H

#include <string>
#include <vector>

using namespace std;

class Flight {
public:

    /**
     * Constructor for Flight class
     * @param source flight source airport
     * @param target flight target airport
     * @param airline airline to which the flight belongs
     */
    Flight(const string& source, const string& target, const string& airline);

    /**
     * Function to set the flights vector (used by DataHandler class)
     * @param flights_data Flight vector
     */
    static void setFlights(vector<Flight> flights_data);

    /**
     * Function to get flights vector
     * @return flights vector
     */
    static vector<Flight> getFlights();

    /**
     * Function to get flight source airport
     * @return flight source airport
     */
    string getSource();

    /**
     * Function to get flight target airport
     * @return flight target airport
     */
    string getTarget();

    /**
     * Function to get flight airline
     * @return flight airline
     */
    string getAirline();
private:
    const string source;
    const string target;
    const string airline;
    static vector<Flight> flights;
};


#endif //PROJ2_AED_FLIGHT_H
