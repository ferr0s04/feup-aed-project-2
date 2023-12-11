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
        else {
            cerr << "Invalid command. Type 'help' to show list of available commands." << endl;
            continue;
        }
    }
}

void Script::help() {
    ifstream file("resources/help_menu.txt");
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


