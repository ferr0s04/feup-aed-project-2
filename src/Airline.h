#ifndef PROJ2_AED_AIRLINE_H
#define PROJ2_AED_AIRLINE_H

#include <string>
#include <vector>
using namespace std;

class Airline {
public:

    /**
     * Constructor for Airline class
     * @param code airline code
     * @param name airline name
     * @param callsign airline callsign
     * @param country airline country
     */
    Airline(const string& code, const string& name, const string& callsign, const string& country);

    /**
     * Function to get airline code
     * @return airline code
     */
    string getAirlineCode() const;

    /**
     * Function to get airline name
     * @return airline name
     */
    string getAirlineName() const;

    /**
     * Function to get airline callsign
     * @return airline callsign
     */
    string getAirlineCallsign() const;

    /**
     * Function to get airline country
     * @return airline country
     */
    string getAirlineCountry() const;

    /**
     * Function to set the airlines vector (used by DataHandler class)
     * @param airlines_data Airline vector to copy airlines from
     */
    static void setAirlines(vector<Airline> airlines_data);

    /**
     * Function to get airlines vector
     * @return airlines vector
     */
    static vector<Airline> getAirlines();

    /**
     * == operator for Airline class
     * @param other
     * @return
     */
    Airline& operator=(const Airline& other){
        if (this != &other) {
            // Copy the values from the other object
            // into the current object
            const_cast<string&>(code) = other.code;
            const_cast<string&>(name) = other.name;
            const_cast<string&>(callsign) = other.callsign;
            const_cast<string&>(country) = other.country;
        }
        return *this;
    }
private:
    const string code;
    const string name;
    const string callsign;
    const string country;
    static vector<Airline> airlines;
};


#endif //PROJ2_AED_AIRLINE_H
