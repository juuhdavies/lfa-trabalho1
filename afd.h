#ifndef AFD_H
#define AFD_H

class afd
{
private:
    vector<char> alfabeto;
    vector<string> estados;
    vector<string> estados_finais;
    vector<transicao> transicoes;
    string estado_inicial;
public:
    
    //Construtor
    afd();
    
    //usar quando for ler os estados do arquivo para armazenar
    void add_simbolo(char s);
    void add_estado(const string& estado);
    void add_estado_final(const string& estado);
    void add_transicao(char s, string& origem, string& destino);
    
    bool eh_estado_final(const string& estado) const;
    string prox_estado(const string& estado_atual, char s) const;
    
    void mostrar();
    
};

#endif // AFD_H
