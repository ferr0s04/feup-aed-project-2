#ifndef PROJ2_AED_FLIGHT_H
#define PROJ2_AED_FLIGHT_H

#include <string>
#include <vector>

using namespace std;

class Flight {
public:
    Flight(const string& source, const string& target, const string& airline);
private:
    const string source;
    const string target;
    const string airline;
    static vector<Flight> flights;
};


#endif //PROJ2_AED_FLIGHT_H
