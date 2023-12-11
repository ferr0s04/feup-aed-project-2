#ifndef PROJ2_AED_SCRIPT_H
#define PROJ2_AED_SCRIPT_H
#include <fstream>
#include <iostream>

using namespace std;

class Script {
public:
    void run();
private:
    ifstream input;
    void help();
};


#endif //PROJ2_AED_SCRIPT_H
