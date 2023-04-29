#include "funcoes.h"

int main(){

    // Abra o arquivo CSV para leitura
    ifstream arq("GeoLite2-City-Blocks-IPv4.csv");

    // Verifique se o arquivo foi aberto com sucesso
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo de formulário." << endl;
        return 1;
    }

    string linha, name_col;
    getline(arq, name_col); // ler a primeira linha do arquivo, que é o nome das colunas do csv

    unordered_map<string,string> tab_ip;
    string ip, mascara, geoname_id;

    //laço para obter o ip, e o código da geolocalização
    while (getline(arq, linha)){
        char separador;
        istringstream inp(linha);
        inp >> ip;
        inp >> separador;
        inp >> mascara;
        inp >> separador;
        inp >> geoname_id;

        tab_ip.emplace(ip, geoname_id);
    }

    arq.close(); // fecha o arquivo de GeoLite2-City-Blocks-IPv4


    return 0;
}