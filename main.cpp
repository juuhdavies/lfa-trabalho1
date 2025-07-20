#include <iostream>
#include "afd.h"
#include <fstream>
#include <algorithm>

using namespace std;

void ler_linha(const string& linha, afd& automato){
    if(linha.find("alfabeto")){
        
    }
}


//não sei se vai ser necessário provavelmente da pra fazer tudo na main e ler_linha
void ler_afd(){
    
}

int main()
{
    afd automato;
    string nome_arquivo;
    
    
    //por hora deixar só um arquivo e dps de ler usar o método de mostrar afd pra conferir
    //Fazer um negócio lá de perguntar oq o usuário quer fazer ex: imprimir gramática, processar cadeia.
    cin >> nome_arquivo;
    
    ifstream file(nome_arquivo);
    if(!file.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
        return 0;
    }
}
