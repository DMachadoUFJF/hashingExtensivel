#include <vector>
#include <bits/stdc++.h>
#include "Balde.h"
using namespace std;

class Diretorio {
    private:
        int profundidadeGlobal , tamanhoBalde;
        vector<Balde*> vectorBaldes;
    public:
        //Diretorio(int profundidadeGlobal, int tamanhoBalde);
        Diretorio(int tamanhoBalde);
        Diretorio(int tamanhoBalde, int profundidadeGlobal);
        ~Diretorio();
        int retornaIndexCorrespondenteBitsBinarios(string pseudoChave);
        void inserePseudoChave(string pseudoChave);
        void buscaPseudoChave();
        void divideBalde();
        void duplicaDiretorio();
        int getProfundidadeGlobal();
        int getTamanhoBalde();

        void imprime();

};

// profundidade de um diretorio eh
//o numero de bits da pseudochaveq que são
//usadas para identificar um balde


// 2) Implementar um tipo abstrato de dados Diretório para armazenar o conjunto de baldes. Esse tipo de dados 
//deve possuir operações para inserir, buscar, dividir baldes e duplicar diretório.

//1 diretorio com 2 opcoes (0 e 1) e um balde