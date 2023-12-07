#include "Application.h"

Application::Application() {}

void Application::run() {
    DataHandler CSV_Data("airlines.csv", "airports.csv", "flights.csv");
}
