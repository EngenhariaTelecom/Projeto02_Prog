#include "funcoes.h"

int main(int argc, char **argv){

    // Abra o arquivo CSV para leitura
    ifstream arq("enderecos_ip.csv");

    // Verifique se o arquivo foi aberto com sucesso
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo de formulário." << endl;
        return 1;
    }

    string linha, name_col;
    getline(arq, name_col); // ler a primeira linha do arquivo, que é o nome das colunas do csv

    string ip, mascara, geoname_id;
    unordered_map<string,string> tab_ip; // cria uma tabela hash para armazenar os IPs e Códigos da geolocalização

    //laço para obter o ip e o código da geolocalização do arquivo endereços_ip.csv
    while (getline(arq, linha)){
        istringstream inp(linha);

        getline(inp, ip, '/'); // extrai o valor de ip da linha lida do arq até a primeira barra
        getline(inp, mascara, ','); // extrai o valor de mascara da linha lida do arq até a próxima vírgula
        getline(inp, geoname_id, ','); // extrai o valor de geoname_id da linha lida do arq até a próxima virgula

        tab_ip.emplace(ip, geoname_id);
    }

    arq.close(); // fecha o arquivo de GeoLite2-City-Blocks-IPv4



    return 0;
}