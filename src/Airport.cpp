#include "Airport.h"

Airport::Airport(const string &code, const string &name, const string &city, const string &country,
                 const double &latitude, const double &longitude)
                 : code(code), name(name), city(city), country(country), latitude(latitude), longitude(longitude) {}
