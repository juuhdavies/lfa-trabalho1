#include "transicao.h"
#include <iostream>

using namespace std;

transicao::transicao(char s, const string& orig, const string& dest) {
    this->simbolo = s;
    this->estado_origem = orig;
    this->estado_destino = dest;
}


void transicao::mostrar() const{
    cout << "(" << estado_origem << "," << estado_destino << ")" << endl;
}
