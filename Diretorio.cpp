#include "Diretorio.h"
using namespace std;
#include <vector>
#include <bits/stdc++.h>


Diretorio::Diretorio(int tamanhoBalde){
    this->profundidadeGlobal = 1;
    this->tamanhoBalde = tamanhoBalde;

    for(int i=0 ; i < 1 << profundidadeGlobal ; i++)
        vectorBaldes.push_back(new Balde(tamanhoBalde));
}


void Diretorio::inserePseudoChave(string pseudoChave){
    
}

int Diretorio::getProfundidadeGlobal(){
    return profundidadeGlobal;
}

int Diretorio::getTamanhoBalde(){
    return profundidadeGlobal;
}



        //void inserePseudoChave();
        void buscaPseudoChave();
        void divideBalde();
        void duplicaDiretorio();