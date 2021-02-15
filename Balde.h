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
    int profundidadeLocal , tamanhoBalde; // profundidade local = numero de bits que todas as pseudochaves de um balde tem em comum

public:
    Balde(int tamanhoBalde);
    Balde(int tamanhoBalde, int profundidadeLocal);
    ~Balde();
    int getTamanhoBalde();
    int getProfundidadeLocal();
    string getBitsIniciais();
    void setBitsIniciais(string str);
    void inserePseudoChaveNoBalde(string pseudoChave); 
    int removePseudoChave(string pseudoChave);
    bool baldeCheio();
    bool baldeVazio();
    bool buscaPseudoChave(string pseudoChave);
    void imprimePseudoChaves();
    string getPseudoChave(int indexPosicaoDoBalde);
    void clearBalde();
    void aumentaProfundidadeLocal();
       
};


// 1) Implementar um tipo abstrato de dados Balde que permita armazenar pseudo-chaves. Utilize o tipo string para representá-las.