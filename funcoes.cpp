#include "funcoes.h"

int procura_pos(string & linha, int posicao_procurada){
    int count = 0; // contador de vírgulas
    size_t pos = 0; // posição atual de busca
    while (count < posicao_procurada && pos != string::npos) {
        pos = linha.find(",", pos+1);
        count++;
    }
    return  pos;
}
