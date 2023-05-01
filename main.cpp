#include "funcoes.h"

int main(int argc, char **argv){

    // Abra o arquivo CSV para leitura
    ifstream arq("enderecos_ip.csv");

    // Verifique se o arquivo foi aberto com sucesso
    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
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

    arq.close(); // fecha o arquivo de enderecos_ip.csv


    // Abra o segundo arquivo CSV para leitura
    ifstream arq_local("geolocal.csv");

    // Verifique se o arquivo foi aberto com sucesso
    if (!arq_local.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    // criando uma tabela para armazenar o país e cidade referente a um certo código de localização
    unordered_map<string, GeoLoc> tab_localizacao;
    GeoLoc local;
    string cod_local;

    getline(arq_local, name_col); // ler a primeira linha do arquivo, que é o nome das colunas do csv

    //laço para obter o país e a cidade da localização de um certo ip
    while (getline(arq_local, linha)){

        istringstream inp(linha);
        getline(inp, cod_local, ','); // obtem o código da localização e armazena na string cod_local

        // procura pela posição da 5ª virgula da linha, que antecede o nome do país
        auto pos_virg_pais = procura_pos(linha, 5);
        size_t pos_apos_pais = linha.find(",", pos_virg_pais+1); // obtem a posição da 6ª virgula para conseguir extrair a informação do país

        local.pais = linha.substr(pos_virg_pais, pos_apos_pais); // extrai o país e armazena na variavel local.pais

        // procura pela posição da 10ª virgula da linha, que antecede o nome da cidade
        auto pos_virg_cidade = procura_pos(linha, 10);
        size_t pos_apos_cidade = linha.find(",", pos_virg_pais+1); // obtem a posição da 11ª virgula para conseguir extrair a info da cidade

        local.cidade = linha.substr(pos_virg_cidade, pos_apos_cidade); // extrai a cidade e armazena na variavel local.cidade

        tab_localizacao.emplace(cod_local, local);

    }

    arq_local.close(); // fecha o arquivo de geolocal.csv


    return 0;
}