#ifndef PROJETO02_PROG_FUNCOES_H
#define PROJETO02_PROG_FUNCOES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

struct GeoLoc {
    string pais, cidade;
};

queue<string> separa(const string & algo, char sep);


#endif //PROJETO02_PROG_FUNCOES_H
