#include "afd.h"
#include <algorithm>
#include <iostream>

using namespace std;

afd::afd() {
    this->estado_inicial = "q0";
}

//adicionar simbolo no alfabeto
void afd::add_simbolo(char s){
    this->alfabeto.push_back(s);
}

void afd::add_estado(const string& estado){
    this->estados.push_back(estado);
}

void afd::add_estado_final(const string& estado){
    this->estados_finais.push_back(estado);
}


void afd::add_transicao(const transicao& t){
    this->transicoes.push_back(t);
}

void afd::add_transicao(char s, string& origem, string& destino){
    add_transicao(transicao(s, origem, destino));
}


bool afd::eh_estado_final(const string& estado) const{
    return find(estados_finais.begin(), estados_finais.end(), estado) != estados_finais.end();
}

string afd::prox_estado(const string& estado_atual, char s) const{
    for(const auto& t : transicoes){
        if(t.estado_origem == estado_atual && t.simbolo == s){
            return t.estado_destino;
        }
    }
    
    return "";
}

//pode tirar dps mas usar para ver se o afd foi lido corretamente
void afd::mostrar(){
    
    cout << "Alfabeto: ";
    for(char c : alfabeto){
        cout << c << " ";
    }
    cout << endl;
    
    cout << "Estados: ";
    for(const auto& e : estados){
        cout << e << " ";
    }
    
    cout << endl << "Estado Inicial: " << estado_inicial << endl;
    
    cout << "Estados Finais: ";
    for(const auto& e : estados_finais){
        cout << e << " ";
    }
    cout << endl;
    
    cout << "Transicoes: ";
    for(const auto& t : transicoes){
        t.mostrar();
    }
    
}
