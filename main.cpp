#include <cstring>
#include <iostream>
#include "afd.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>


using namespace std;

//ler o afd do .txt e armazenar
afd ler_afd(const string& nome_arquivo){

    afd automato;
    ifstream file(nome_arquivo);
    if(!file.is_open()){
        cerr << "Erro ao abrir arquivo" << endl;
        exit(1);
    }

    char buffer[256];

    //Ler alfabeto
    file.getline(buffer, sizeof(buffer));
    char alfabeto[256];
    sscanf(buffer, "alfabeto={ %255[^}] }", alfabeto);
    //para cada char lido no alfabeto se char for diferente de virgula o espaço armazenar
    for (char* p = alfabeto; *p; ++p) {
        if (*p != ',' && *p != ' ') {
            automato.add_simbolo(*p);
        }
    }

    //Ler Estados
    file.getline(buffer, sizeof(buffer));
    char estados[256];
    sscanf(buffer, "estados={ %255[^}] }", estados);
    //ler dos estados lidos da linha
    stringstream sE(estados);
    string estado;
    //como cada estado é uma string de 2 char, usar getline até a virgula
    while(getline(sE, estado, ',')){
        automato.add_estado(estado);
    }

    //Ler Estados Finais
    file.getline(buffer, sizeof(buffer));
    char finais[256];
    sscanf(buffer, "finais={ %255[^}] }", finais);
    stringstream sEF(finais);
    string estadoFinal;
    //como cada estado final é uma string de 2 char, usar getline até a virgula
    while (getline(sEF, estadoFinal, ',')){
        automato.add_estado_final(estadoFinal);
    }

    //Ler Transições
    while (file.getline(buffer, sizeof(buffer))) {
        if (strlen(buffer) == 0) continue;

        char origem[10], destino[10], simbolo;
        if (sscanf(buffer, "(%9[^,], %c)= %9s", origem, &simbolo, destino) == 3) {
            string orig = origem;
            string dest = destino;
            automato.add_transicao(simbolo, orig, dest);
        }
    }
    file.close();
    return automato;
}

void ger_gramar(const string& estado_inicial, const vector<string>& estados_finais, const vector<transicao>& transicoes){
    map<string, vector<string>> gramatica;

    for (const auto& t : transicoes) {
        string origem = t.estado_origem;
        string simbolo(1, t.simbolo);
        string destino = t.estado_destino;

        int numero_origem = stoi(origem.substr(1));
        char origem_letra = static_cast<char>(65+numero_origem-1);
        string varOrigem = (origem == estado_inicial) ? "S" : string(1, origem_letra);
        int numero_destino = stoi(destino.substr(1));
        char destino_letra = static_cast<char>(65+numero_destino-1);
        string varDestino = (destino == estado_inicial) ? "S" : string(1, destino_letra);

        gramatica[varOrigem].push_back(simbolo + varDestino);

        if (find(estados_finais.begin(), estados_finais.end(), destino) != estados_finais.end()) {
            gramatica[varOrigem].push_back(simbolo);
        }
    }

    for (const auto& estado : estados_finais) {
        string origem = estado;
        int numero_origem = stoi(origem.substr(1));
        char origem_letra = static_cast<char>(65+numero_origem-1);
        string var = (estado == estado_inicial) ? "S" : string(1, origem_letra);
        gramatica[var].push_back("@");
    }

    cout << "\nGramatica regular equivalente:\n";

    if (gramatica.count("S")) {
        const vector<string>& producoesS = gramatica["S"];
        cout << "S -> ";
        for (size_t i = 0; i < producoesS.size(); ++i) {
            cout << producoesS[i];
            if (i < producoesS.size() - 1)
                cout << " | ";
        }
        cout << endl;
    }

    for (auto it = gramatica.begin(); it != gramatica.end(); ++it) {
    const string& variavel = it->first;
    if (variavel == "S") continue;

    const vector<string>& producoes = it->second;

    cout << variavel << " -> ";
    for (size_t i = 0; i < producoes.size(); ++i) {
        cout << producoes[i];
        if (i < producoes.size() - 1)
            cout << " | ";
    }
    cout << endl;
    }
}

int main()
{
    afd automato;
    string nome_arquivo;


    //por hora deixar só um arquivo e dps de ler usar o método de mostrar afd pra conferir
    //Fazer um negócio lá de perguntar oq o usuário quer fazer ex: imprimir gramática, processar cadeia.
    cout << "Digite o nome do arquivo com a extensao: (nome.txt) " << endl;
    cin >> nome_arquivo;
    automato = ler_afd(nome_arquivo);

    automato.mostrar();

    ger_gramar(automato.estado_inicial, automato.estados_finais, automato.transicoes);

    automato.processa_cadeia();
    int op=0;
    while(op!=2){
            cout << "\nDeseja processar mais palavras?\n1 - Sim\n2 - Nao" << endl;
            cin >> op;
        switch(op){
        case 1:
            automato.processa_cadeia();
            break;
        case 2:
            break;
        default:
            cout << "Opcao Invalida. Insira novamente." << endl;
            break;
        }
    }
    return 0;
}
