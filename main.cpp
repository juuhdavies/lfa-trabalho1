#include <iostream>
#include "afd.h"
#include <fstream>
#include <string>
#include <istream>
#include <algorithm>

using namespace std;

void ler_linha(const string& linha, afd& automato){
    
    //busca alfabeto na linha, string::npos é usada para inficar que a busca não encontrou oq estava procurando
    if(linha.find("alfabeto") != string::npos){

    }
}



void ler_afd(const string& nome_arquivo, afd& automato){
    ifstream file(nome_arquivo);
    if(!file.is_open()){
        cerr << "Erro ao abrir arquivo" << endl;
        exit(1);
    }

    string linha;
    while(getline(file, linha)){
        ler_linha(linha, automato);
    }


}

int main()
{
    afd automato;
    string nome_arquivo;


    //por hora deixar só um arquivo e dps de ler usar o método de mostrar afd pra conferir
    //Fazer um negócio lá de perguntar oq o usuário quer fazer ex: imprimir gramática, processar cadeia.
    cin >> nome_arquivo;


}
