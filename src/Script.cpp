#include "Script.h"

#include <utility>

Script::Script(Graph n) {
    network = n;
}

void Script::run() {
    string command;
    cout << "You can now start using the program. Write 'help' or '?' to get help" << endl;
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
        if (command == "top-capacity") {
            topCapacity();
            cout << '\n';
            continue;
        }
        if (command == "countries-count-from-airport/city"){
            countriesFromAirportOrCityCount();
            cout << "\n";
        }
        if (command == "essencial") {
            essencial();
            cout << "\n";
        }
        if (command == "xvindo") {
            xvindoAeroporto();
            cout << "\n";
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
    cout << "Resposta:";
    cin >> resposta;

    if (resposta == "companhia") {
        cout << "Qual o codigo da companhia?" << endl;
        cout << "Resposta:";
        cin >> companhia;

        int contadorcompanhia = 0;
        auto lista = Flight::getFlights();

        for (auto i : lista) {
            string alvo = i.getAirline();
            if (alvo == companhia) {
                contadorcompanhia++;
            }
        }

        cout << "Existem " << contadorcompanhia << "voos da " << companhia << endl;
    }

    if (resposta == "cidade") {
        cout << "Qual a cidade?" << endl;
        cout << "Resposta:";
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
        cout << "Existem " << contadorcidade << "voos da " << cidade << endl;
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

void Script::topCapacity() {
    int range;
    cout << "Please define list range:";
    cin >> range;
    map<string,int> flightsPerAirport;

    // Number of departure flights by airport
    for (Flight& f : Flight::getFlights()) {
        auto it = flightsPerAirport.find(f.getSource());
        if (it != flightsPerAirport.end()) {
            it->second ++;
        } else {
            flightsPerAirport[f.getSource()] ++;
        }
    }

    // Number of arrival flights by airport
    for (Flight& f : Flight::getFlights()) {
        auto it = flightsPerAirport.find(f.getTarget());
        if (it != flightsPerAirport.end()) {
            it->second ++;
        } else {
            flightsPerAirport[f.getTarget()] ++;
        }
    }

    // Sort by decreasing order of capacity
    std::vector<std::pair<std::string, int>> sortedAirports(flightsPerAirport.begin(), flightsPerAirport.end());
    std::sort(sortedAirports.begin(), sortedAirports.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    int position = 1;
    for (int i = 0; i < range && i < sortedAirports.size(); ++i) {
        const auto& e = sortedAirports[i];
        string name;
        for (Airport& a : Airport::getAirports()) {
            if (a.getCode() == e.first) {
                name = a.getName();
            }
        }
        cout << position << " | Airport: " << e.first << " | Name: " << name << " | Capacity: " << e.second << endl;
        position++;
    }
}

void Script::countriesFromAirportOrCityCount(){
    cout << "If you wish to know the number of countries that a given airport flies to press 'A'\n "
         << "If you wish to know the number of countries that a given city flies to press 'C' \n";
    char option;
    cin >> option;

    bool is_option_valid = (option == 'a' || option == 'A' || option == 'c' || option == 'C');
    if(!is_option_valid) {
        while (!is_option_valid){
            cout << "Not a valid key \nPress either 'A' or 'C' (case insensitive) \n";
            cin >> option;
            is_option_valid = (option == 'a' || option == 'A' || option == 'c' || option == 'C');
        }
    }

    if(option == 'a' || option == 'A'){
        string airport_code;
        cout << "Please insert an airport code \n";
        bool valid_code = false;
        while (!valid_code){
            cin >> airport_code;
            for (Airport airport : Airport("", "", "", "", 0, 0).getAirports()){
                if (airport.getCode() == airport_code)
                    valid_code = true;
            }
            if (!valid_code)
                cout << "Invalid code. Please try again";
        }
        cout << "From airport " << airport_code << " there are flights to " << countriesFromAirport(airport_code).size() << " countries";
    }

    else if (option == 'c' || option == 'C')
        countriesFromCityCount();
}

set<string> Script::countriesFromAirport(const string& airport_code){
    set<string> countries = set<string>();
    for (auto airport_vertex: network.getVertexSet()) {
        if (airport_code == airport_vertex->getInfo().getCode()) {
            auto destinations_airports = airport_vertex->getAdj();
            //std::cout << "the adj() size is " << airport_vertex -> getAdj().size() << std::endl; //----------------------------
            for(auto airport : destinations_airports)
                countries.insert(airport.getDest()->getInfo().getCountry());
            break;
        }
    }
    return countries;

}

void Script::countriesFromCityCount() {
    // TODO fix, this is not working
    string city;
    cout << "Please insert the city's name\n";
    cin >> city;
    Airport airport = Airport("", "", "", "", 0, 0);
    set<string> city_airport_codes;
    set<string> countries;
    for (Airport airprt : airport.getAirports()){
        if (airprt.getCity() == city){
            city_airport_codes.insert(airport.getCode());
        }
    }
    for (string airport_code : city_airport_codes){
        set<string> temp = countriesFromAirport(airport_code);
        countries.insert(temp.begin(), temp.end());
    }
    cout << "From " << city << " there are flights to " << countries.size() << " countries";
    //TODO - check if city is correct and check for aliases
}

void Script::essencial() {
    //TODO Não sei como calcular se é essencial ou nao
}

void Script::xvindoAeroporto() {
    //TODO verificar se tem aliases e meter caso de erro de escrita
    string Aeroportocode;
    string Opcao;
    int distancia;
    int quantidade = 0;
    auto listadevoos = network.getVertexSet();
    auto listaAeroporto = Airport::getAirports();
    set<string> listatemp;


    cout << "Indica o codigo do Aeroporto:" << endl;
    cout << "Resposta:";
    cin  >> Aeroportocode;

    cout << "Queres saber sobre Cidades , Paises ou Aeroportos?" << endl;
    cout << "Escreve 'cidade' ou 'pais' ou 'porto'." << endl;
    cout << "Resposta:";
    cin >> Opcao;

    cout << "Quantas paragens queres fazer ate ao destino?" << endl;
    cout << "Resposta:";
    cin >> distancia;

    if (Opcao == "cidade") {
        if (distancia == 0) {
            for (auto item: listaAeroporto) {
                if (item.getCode() == Aeroportocode) {
                    auto vitem = network.findVertex(item);
                    auto vedges = vitem->getAdj();
                    for (auto cont : vedges) {
                        auto temp = cont.getDest()->getInfo();
                        listatemp.insert(temp.getCity());
                    }
                    for (auto i : listatemp) {
                        quantidade++;
                    }
                    break;
                }
            }
        }
        else {
            //TODO Capacidade de calcular com base na distancia
        }
    }

    if (Opcao == "pais") {
        if (distancia == 0) {
            for (auto item: listaAeroporto) {
                if (item.getCode() == Aeroportocode) {
                    auto vitem = network.findVertex(item);
                    auto vedges = vitem->getAdj();
                    for (auto cont : vedges) {
                        auto temp = cont.getDest()->getInfo();
                        listatemp.insert(temp.getCountry());
                    }
                    for (auto i : listatemp) {
                        quantidade++;
                    }
                    break;
                }
            }
        }
        else {
            //TODO Capacidade de calcular com base na distancia
        }
    }

    if (Opcao == "porto") {
        if (distancia == 0) {
            for (auto item: listaAeroporto) {
                if (item.getCode() == Aeroportocode) {
                    auto vitem = network.findVertex(item);
                    auto vedges = vitem->getAdj();
                    for (auto cont : vedges) {
                        auto temp = cont.getDest()->getInfo();
                        listatemp.insert(temp.getCode());
                    }
                    for (auto i : listatemp) {
                        quantidade++;
                    }
                    break;
                }
            }
        }
        else {
            //TODO Capacidade de calcular com base na distancia
        }
    }

    cout << "Existem " << quantidade << " voos a distancia de " << distancia << " paragens do aeroporto " << Aeroportocode << endl;
}