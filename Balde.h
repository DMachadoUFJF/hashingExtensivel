#ifndef BALDE_H
#define BALDE_H
#include <vector>
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

class Balde
{
private:
    vector<string> vectorPseudoChaves;
    string bitsIniciais;
    int profundidadeLocal , tamanhoBalde, numeroDePseudoChavesNoBalde; // profundidade local = numero de bits que todas as pseudochaves de um balde tem em comum

public:
    Balde(int tamanhoBalde);
    Balde(int tamanhoBalde, int profundidadeLocal);
    ~Balde();
    int getProfundidadeLocal();
    string getBitsIniciais();
    void setBitsIniciais(string bitsIniciais);
    bool baldeCheio();
    void inserePseudoChaveNoBalde(string pseudoChave);
    void aumentaProfundidadeLocal();
    string getPseudoChave(int indexPosicaoDoBalde);
    int getNumeroDePseudoChavesNoBalde();
    
    
};

#endif