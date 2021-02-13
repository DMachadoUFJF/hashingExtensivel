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
    int profundidadeLocal , tamanhoBalde; // profundidade local = numero de bits que todas as pseudochaves de um balde tem em comum

public:
    Balde(int tamanhoBalde);
    Balde(int tamanhoBalde, int profundidadeLocal);
    ~Balde();
    int getTamanhoBalde();
    int getProfundidadeLocal();
    void inserePseudoChave(string pseudoChave); 
    int removePseudoChave(string pseudoChave);
    bool baldeCheio();
    bool baldeVazio();
    bool buscaPseudoChave(string pseudoChave);
    void imprimePseudoChaves();
       
        //void search(int key);
        // int update(int key, string value);
        // void search(int key);
        // int increaseDepth(void);
        // int decreaseDepth(void);
        // std::map<int, string> copy(void);
        // void clear(void);
        // void display(void);
};


// 1) Implementar um tipo abstrato de dados Balde que permita armazenar pseudo-chaves. Utilize o tipo string para representá-las.