#include <vector>
#include <string>
#include <iostream>
#include "Diretorio.h"
#include <math.h>
#include <time.h>
#include <chrono>
#include <algorithm>
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

string randMesmoInicio(int numeroBits)
{
    int x;
    string pseudoChave = "01";
    for (int i = 0; i < numeroBits-2; i++)
    {
        x = (rand() % 100)%2;
        pseudoChave.append(to_string(x));
    }
    return pseudoChave;
}

vector<string> fazVectorMesmoInicio(int quantidadePseudoChaves, int numeroBits)
{
    vector<string> vectorPca;
    
    for(int i=0 ; i<quantidadePseudoChaves ; i++){
        string pseudoChave;
        pseudoChave =randMesmoInicio(numeroBits);
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
    int tamanhoBalde,numeroBits,opcao;
    cout << "Digite 1 para 15 insercoes de pseudo-chaves aleatorias" << endl;
    cout << "Digite 2 para 15 insercoes de pseudo-chaves iniciadas com 01" << endl;
    cin >> opcao;
    cout << "Digite o tamanho do balde : "<<endl;
    cin >> tamanhoBalde;
    cout << "Digite o numero de bits a ser usado para as pseudo-chaves : "<<endl;
    if(opcao == 2)
        cout<<"(escolha um numero >= 6, pois as 15 pseudo-chaves nao podem ser iguais) :"<<endl;
    
    cin >> numeroBits;
    Diretorio dir(tamanhoBalde);
     if(opcao == 1){
        
        vector<string> pseudoChaves = fazVectorPCA(15,numeroBits);
        cout <<endl<<"Inserindo as seguintes pseudo-chaves: "<<endl;
        for(int i=0 ; i<pseudoChaves.size() ; i++)
            cout << pseudoChaves[i]<< " ";
        cout<<endl;
        for(int i=0 ; i<pseudoChaves.size() ; i++)
            dir.inserePseudoChave(pseudoChaves[i]);
     }else if(opcao == 2){
         vector<string> pseudoChaves = fazVectorMesmoInicio(15,numeroBits);
        cout <<endl<<"Inserindo as seguintes pseudo-chaves: "<<endl;
        for(int i=0 ; i<pseudoChaves.size() ; i++)
            cout << pseudoChaves[i]<< " ";
        cout<<endl;
        for(int i=0 ; i<pseudoChaves.size() ; i++)
            dir.inserePseudoChave(pseudoChaves[i]);

     }else return 0;

    dir.imprime();

    return 0;
}