#ifndef PROJETO02_PROG_FUNCOES_H
#define PROJETO02_PROG_FUNCOES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

struct GeoLoc {
    string pais, cidade; // strings para armazenar a localização do ip
};

int procura_pos(string & linha, int posicao_procurada);


#endif //PROJETO02_PROG_FUNCOES_H
