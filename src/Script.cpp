#include "Script.h"

void Script::run() {
    string command;
    while(cin >> command) {
        if (command == "help" || command == "?") {
            help();
            cout << '\n';
            continue;
        }
        if (command == "q" || command == "quit") {
            break;
        }
        if (command == "airports-country") {
            airportsCountry();
            cout << '\n';
            continue;
        }
        if (command == "flights-airport") {
            flightsAirport();
            cout << '\n';
            continue;
        }
        if (command == "destinations") {
            destinations();
            cout << '\n';
            continue;
        }
        if (command == "global-stats"){
            globalStats();
            cout << '\n';
            continue;
        }
        if (command == "num-voo-cid") {
            flights_per_city();
            cout << '\n';
            continue;
        }
        else {
            cerr << "Invalid command. Type 'help' to show list of available commands." << endl;
            continue;
        }
    }
}

void Script::help() {
    ifstream file("../resources/help_menu.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Failed to get available commands" << endl;
    }
}

void Script::globalStats() {
    cout << "There are " << Airport::getAirports().size() << " airports." << endl;
    cout << "There are " << Flight::getFlights().size() << " flights." << endl;
    cout << "There are " << Airline::getAirlines().size() << " airlines." << endl;
}

void Script::flights_per_city() {
    string companhia;
    string cidade;
    string resposta;

    cout << "Companhia ou cidade?" << endl;
    cout << "Escreve 'companhia' para a primeira opcao ou 'cidade' para a segunda opcao" << endl;
    cin >> resposta;

    if (resposta == "companhia") {
        cout << "Qual o codigo da companhia?" << endl;
        cin >> companhia;

        int contadorcompanhia = 0;
        auto lista = Flight::getFlights();

        for (auto i : lista) {
            string alvo = i.getAirline();
            if (alvo == companhia) {
                contadorcompanhia++;
            }
        }

        cout << contadorcompanhia;
    }

    if (resposta == "cidade") {
        cout << "Qual a cidade?" << endl;
        cin >> cidade;

        int contadorcidade = 0;

        vector<Airport> cityAirports;
        for (Airport& a : Airport::getAirports()) {
            if (a.getCity() == cidade) {
                cityAirports.push_back(a);
            }
        }
        for (Flight& f : Flight::getFlights()) {
            for (Airport& a : cityAirports) {
                if (f.getSource() == a.getCode()) {
                    contadorcidade++;
                }
            }
        }
        cout << contadorcidade;
    }
}

void Script::flightsAirport() {
    vector<Flight> flights;
    vector<string> airlines;
    string code;
    cout << "Insert airport code:";
    cin >> code;
    cout << '\n';
    for (Flight f : Flight::getFlights()) {
        if (f.getSource() == code) {
            flights.push_back(f);
            auto it = find(airlines.begin(), airlines.end(), f.getAirline());
            if (it == airlines.end()) {
                airlines.push_back(f.getAirline());
            }
        }
    }
    cout << "Statistics for airport " << code << endl;
    cout << "Number of flights out: " << flights.size() << endl;
    cout << "Number of airlines: " << airlines.size() << endl;
}


bool compareAirportCode(const Airport& a, const Airport& b) {
    return a.getCode() < b.getCode();
}

void Script::airportsCountry() {
    string country;
    vector<Airport> airports;
    cout << "Country name:";
    cin >> country;
    cout << '\n';
    for (Airport& a : Airport::getAirports()) {
        if (a.getCountry() == country) {
            airports.push_back(a);
        }
    }
    sort(airports.begin(), airports.end(), compareAirportCode);
    for (Airport& a : airports) {
        cout << "Code: " << a.getCode() << " | Name: " << a.getName() << endl;
    }
}

void Script::destinations() {
    string code;
    cout << "Insert airport code:";
    cin >> code;
    cout << '\n';
    set<Airport> destAirports;
    set<string> destCities;
    set<string> destCountries;
    for (Flight& f : Flight::getFlights()) {
        if (f.getSource() == code) {
            for (Airport& a : Airport::getAirports()) {
                if (f.getTarget() == a.getCode()) {
                    destAirports.insert(a);
                    destCities.insert(a.getCity());
                    destCountries.insert(a.getCountry());
                }
            }
        }
    }
    cout << "Number of destination airports: " << destAirports.size() << endl;
    cout << "Number of destination cities: " << destCities.size() << endl;
    cout << "Number of destination countries: " << destCountries.size() << endl;
    cout << '\n';
    cout << "List of destination cities:" << endl;
    for (string city : destCities) {
        cout << city << endl;
    }
    cout << '\n';
    cout << "List of destination countries:" << endl;
    for (string country : destCountries) {
        cout << country << endl;
    }
}

