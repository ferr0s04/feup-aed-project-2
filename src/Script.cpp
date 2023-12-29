#include "Script.h"

void Script::run() {
    string command;
    while(cin >> command) {
        if (command == "help" || command == "?") {
            help();
            continue;
        }
        if (command == "q" || command == "quit") {
            break;
        }
        if (command == "global-stats"){
            globalStats();
        }
        if (command == "num-voo-cid") {
            flights_per_city();
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
    cout << "There are " << airport.getAirports().size() << " airports.";
    cout << "\n";
    cout << "There are " << flight.getFlights().size() << " flights.";
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
            string alvo = i.getairline();
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
        auto listavoo = Flight::getFlights();
        auto listaportos = Airport::getAirports();

        for (auto i : listavoo) {
            string companhiatemp = i.getsource();
            string alvo;

            for (auto j : listaportos) {
                string testecode = j.getcode();
                if (testecode == companhiatemp) {
                    alvo = j.getcity();
                    break;
                }
            }
            if (alvo == cidade) {
                contadorcidade++;
            }
        }

        cout << contadorcidade;
    }
}

