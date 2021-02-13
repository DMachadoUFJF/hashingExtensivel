#include <vector>
#include <string>
#include <iostream>
#include "Balde.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

class Diretorio {
    private:
        int profundidadeGlobal , tamanhoBalde;
        vector<Balde*> vectorBaldes;
    public:
        Diretorio(int tamanhoBalde);
        Diretorio(int tamanhoBalde, int profundidadeGlobal);
        ~Diretorio();
        int retornaIndexInteiroCorrespondenteBitsBinarios(string pseudoChave);
        void inserePseudoChave(string pseudoChave);
        void divideBalde(int indexBalde, string pseudoChaveRestante);


        void duplicaDiretorio();
        void buscaPseudoChave();
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