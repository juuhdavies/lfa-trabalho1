#ifndef TRANSICAO_H
#define TRANSICAO_H

#include <vector>
#include <string>

using namespace std;

class transicao
{
public:
    char simbolo;
    string estado_origem;
    string estado_destino;

    transicao(char s, const string& orig, const string& dest);
    void mostrar() const;
};

#endif // TRANSICAO_H
