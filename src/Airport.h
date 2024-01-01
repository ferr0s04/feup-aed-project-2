#ifndef PROJ2_AED_AIRPORT_H
#define PROJ2_AED_AIRPORT_H

#include <string>
#include <vector>

using namespace std;

class Airport {
public:

    /**
     * Constructor for Airport class
     * @param code airport code
     * @param name airport name
     * @param city city where the airport is located
     * @param country country where the airport is located
     * @param latitude airport coordinates
     * @param longitude airport coordinates
     */
    Airport(const string& code, const string& name, const string& city, const string& country, const double& latitude, const double& longitude);

    /**
     * Function to set the airports vector (used by DataHandler class)
     * @param airports_data Airport vector to copy airports from
     */
    static void setAirports(vector<Airport> airports_data);

    /**
     * Function to get airports vector
     * @return airports vector
     */
    static vector<Airport> getAirports();

    /**
     * Function to get airport code
     * @return airport code
     */
    string getCode() const;

    /**
     * Function to get airport name
     * @return airport name
     */
    string getName() const;

    /**
     * Function to get the city where the airport is located
     * @return airport city
     */
    string getCity() const;

    /**
     * Function to get the country where the airport is located
     * @return airport country
     */
    string getCountry() const;

    /**
     * Function to get airport latitude coordinate
     * @return airport latitude coordinate
     */
    double getLatitude() const;

    /**
     * Function to get airport longitude coordinate
     * @return airport longitude coordinate
     */
    double getLongitude() const;

    /**
     * Function to add an airport to the airports vector
     */
    void addToAirports();

    /**
     * < operator for Airport class
     * @param other
     * @return
     */
    bool operator<(const Airport& other) const;

    /**
     * == operator for Airport class
     * @param other
     * @return
     */
    Airport& operator=(const Airport& other);
    bool operator==(const Airport &other)  {
        return other.getCode() == this->getCode();
    }
private:
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
    static vector<Airport> airports;
};


#endif //PROJ2_AED_AIRPORT_H
