#include <vector>
#include <string>
#include <iostream>
#include "Diretorio.h"
#include <math.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

//https://docs.google.com/presentation/d/1rgl-fr2U4BchA0jvzAIKGDd4TIHs0oG1sDiRyRWvA0I/edit#slide=id.p
//https://drive.google.com/file/d/15-gaXgaz3pTXRowB2l1i1ULAArs073-4/view
//https://drive.google.com/file/d/1Cu_VzGIe3ah8cGCmGsMuAkhbAupFDRS0/view
//https://drive.google.com/file/d/1UWuFtfD2f-UcBhmdXVqaPjjuM8ItLloo/view
//https://www.geeksforgeeks.org/extendible-hashing-dynamic-approach-to-dbms/
//https://docs.google.com/document/d/1gmufpr5l0PCeUNyvU7InmNvR9C4wgoGNcAhZBYL0zSY/edit#

bool temStringRepetida(string item, vector<string> vetor)
{
    for (int x = 0; x < vetor.size(); x++)
    {
        if (vetor[x] == item)
            return true;
    }
    return false;
}

string retornaPseudoChaveAleatoria(int numeroBits){
    unsigned int seed = (std::chrono::system_clock::now().time_since_epoch().count())/130;
    string pseudoChave;
    for(int i=0;i<numeroBits;i++){
        seed = (std::chrono::system_clock::now().time_since_epoch().count())/72;
        srand (seed+i);
        pseudoChave = pseudoChave + to_string(rand()%2);
    }
    return pseudoChave;
}

vector<string> fazVectorPCA(int quantidadePseudoChaves, int numeroBits)
{
    vector<string> vectorPca;
    string pseudoChave;
    for(int i=0 ; i<quantidadePseudoChaves ; i++){
        pseudoChave = retornaPseudoChaveAleatoria(numeroBits);
        if(temStringRepetida(pseudoChave,vectorPca)){
            i--;
        }
        else{
            vectorPca.push_back(pseudoChave);
        }
    }
    return vectorPca;
}

int main()
{
    int tamanhoBalde,numeroBits,quantidadeDePseudoChaves;
    cout << "Digite o tamanho do balde : "<<endl; //
    cin >> tamanhoBalde;
    cout << "Digite o numero de bits a ser usado para as pseudo-chaves : "<<endl;
    cin >> numeroBits;
    cout << "Digite a quantidade de pseudo-chaves que quer gerar"<<endl;
    cout<<"(escolher um numero menor ou igual a "<<pow(2,numeroBits)<<" )  :"<<endl;
    cin >> quantidadeDePseudoChaves;

    Diretorio dir(tamanhoBalde);
    vector<string> pseudoChaves = fazVectorPCA(quantidadeDePseudoChaves,numeroBits);
    for(int i=0 ; i<pseudoChaves.size() ; i++)
        cout << pseudoChaves[i]<< " ";
    cout<<endl;
    for(int i=0 ; i<pseudoChaves.size() ; i++)
        dir.inserePseudoChave(pseudoChaves[i]);
    dir.imprime();



    
    return 0;
}

//  g++ -o hash -O3 *.cpp
// 1) Implementar um tipo abstrato de dados Balde que permita armazenar pseudo-chaves. Utilize o tipo string para representá-las.

// 2) Implementar um tipo abstrato de dados Diretório para armazenar o conjunto de baldes. Esse tipo de dados 
//deve possuir operações para inserir, buscar, dividir baldes e duplicar diretório.

// 3)A função principal deve solicitar ao usuário o tamanho M a ser usado para
// os baldes e o número de bits B a ser usado para as pseudo-chaves.

// 4)Devem ser realizados dois testes:
// a)Inserções de N pseudo-chaves aleatórias
// b)Inserções de N pseudo-chaves iniciadas com um mesmo padrão de bits

// 5) Analise os resultados dos testes com relação ao fator de carga da tabela e à ocupação de memória. Escolha N de
// forma a permitir uma análise adequada. Compare os resultados obtidos com os dois testes e preencha o relatório da atividade.
