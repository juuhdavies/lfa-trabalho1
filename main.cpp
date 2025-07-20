#include <cstring>
#include <iostream>
#include "afd.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

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

int main()
{
    afd automato;
    string nome_arquivo;


    //por hora deixar só um arquivo e dps de ler usar o método de mostrar afd pra conferir
    //Fazer um negócio lá de perguntar oq o usuário quer fazer ex: imprimir gramática, processar cadeia.
    cin >> nome_arquivo;
    automato = ler_afd(nome_arquivo);

    automato.mostrar();


}
