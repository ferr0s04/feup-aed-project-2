#include "DataHandler.h"


DataHandler::DataHandler(const string &airlines_file, const string &airports_file, const string &flights_file) {
    AirlinesParse(airlines_file);
    AirportsParse(airports_file);
    FlightsParse(flights_file);
}

bool DataHandler::AirlinesParse(const string &airlines_file) {
    vector<string> data;
    readCSV(airlines_file, data);
    for (const std::string& line : data) {
        istringstream ss(line);
        string Code, Name, Callsign, Country;

        if (getline(ss, Code, ',') &&
            getline(ss, Name, ',') &&
            getline(ss, Callsign, ',') &&
            getline(ss, Country)) {
            Airline airline(Code, Name, Callsign, Country);
            parsedAirlines.push_back(airline);
        } else {
            cerr << "Failed to get airlines from file" << endl;
        }
    }
    return true;
}

bool DataHandler::AirportsParse(const string &airports_file) {
    vector<string> data;
    readCSV(airports_file, data);
    for (const std::string& line : data) {
        istringstream ss(line);
        string Code, Name, City, Country, Latitude, Longitude;

        if (getline(ss, Code, ',') &&
            getline(ss, Name, ',') &&
            getline(ss, City, ',') &&
            getline(ss, Country, ',') &&
            getline(ss, Latitude, ',') &&
            getline(ss, Longitude)) {
            double latitude = stod(Latitude);
            double longitude = stod(Longitude);
            Airport airport(Code, Name, City, Country, latitude, longitude);
            parsedAirports.push_back(airport);
            //TODO check if it's already there
            network.addVertex(airport);
        } else {
            cerr << "Failed to get airports from file" << endl;
        }
    }
    return true;
}

bool DataHandler::FlightsParse(const string &flights_file) {
    vector<string> data;
    readCSV(flights_file, data);
    for (const std::string& line : data) {
        istringstream ss(line);
        string Source, Target, Airline;

        if (getline(ss, Source, ',') &&
            getline(ss, Target, ',') &&
            getline(ss, Airline)) {
            Flight flight(Source, Target, Airline);
            parsedFlights.push_back(flight);
            Airport airport = Airport("", "", "", "", 0, 0);
            for (Airport source_airport : airport.getAirports()) {
                if (source_airport.getCode() == Source){
                    for (Airport target_airport : airport.getAirports()){
                        if(target_airport.getCode() == Target)
                            network.addEdge(source_airport, target_airport, 0);
                    }
                }
            }
        } else {
            cerr << "Failed to get flights from file" << endl;
        }
    }
    return true;
}

void DataHandler::readCSV(const string& filename, vector<string>& data) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line);
        while (getline(file, line)) {
            data.push_back(line);
        }
        file.close();
    } else {
        cerr << "Failed to open CSV file: " << filename << endl;
    }
}

vector<Airline> DataHandler::getParsedAirlines() {
    return parsedAirlines;
}

vector<Airport> DataHandler::getParsedAirports() {
    return parsedAirports;
}

vector<Flight> DataHandler::getParsedFlights() {
    return parsedFlights;
}
