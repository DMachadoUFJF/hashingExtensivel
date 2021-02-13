#include <iostream>
#include <vector>
#include <string>
#include "Balde.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;

Balde::Balde(int tamanhoBalde){
    profundidadeLocal =0;
    this->tamanhoBalde = tamanhoBalde;
}

Balde::Balde(int tamanhoBalde, int profundidadeLocal){
    this->profundidadeLocal =profundidadeLocal;
    this->tamanhoBalde = tamanhoBalde;
}

Balde::~Balde(){}
    
void Balde::inserePseudoChaveNoBalde(string pseudoChave){
    vectorPseudoChaves.push_back(pseudoChave);
    cout<<pseudoChave<<" inserido com sucesso"<<endl;
}

int Balde::removePseudoChave(string pseudoChave){
    for(int i =0 ; i<vectorPseudoChaves.size();i++){
        if(vectorPseudoChaves[i] == pseudoChave){
            vectorPseudoChaves[i].erase();
            cout<<pseudoChave<<" removida com sucesso"<<endl;
            return 1;
        }
    }
    cout<<"Esta chave nao foi encontrada,portanto nao foi removida."<<endl;
    return 0;
}

bool Balde::baldeCheio(){
    if(vectorPseudoChaves.size() == tamanhoBalde)
        return true;
    else return false;
}

bool Balde::baldeVazio(){
    if(vectorPseudoChaves.size() == 0)
        return true;
    else return false;
}

int Balde::getProfundidadeLocal(){
    return profundidadeLocal;
}

int Balde::getTamanhoBalde(){
    return tamanhoBalde;
}

void Balde::imprimePseudoChaves(){
    for(int i=0 ; i<vectorPseudoChaves.size();i++)
        cout<< vectorPseudoChaves[i]<<"  ";
    cout<<endl;
}

bool Balde::buscaPseudoChave(string pseudoChave){
    for(int i =0 ; i<vectorPseudoChaves.size();i++){
        if(vectorPseudoChaves[i] == pseudoChave){
            cout<<pseudoChave<<" encontrada com sucesso"<<endl;
            return true;
        }
    }
    cout<<"Esta chave nao foi encontrada."<<endl;
    return false;
}

string Balde::getPseudoChave(int indexPosicaoDoBalde){
    return vectorPseudoChaves[indexPosicaoDoBalde];
}

void Balde::clearBalde(){
    vectorPseudoChaves.clear();
}

void Balde::aumentaProfundidadeLocal(){
    profundidadeLocal++;
}