using namespace std;
#include <vector>
#include <bits/stdc++.h>
#include "Diretorio.h"


Diretorio::Diretorio(int tamanhoBalde){
    this->profundidadeGlobal = 1;
    this->tamanhoBalde = tamanhoBalde;
       
    vectorBaldes.push_back(new Balde(tamanhoBalde));
    vectorBaldes.push_back(*vectorBaldes.begin());
        
}

Diretorio::Diretorio(int tamanhoBalde, int profundidadeGlobal){
    // if(profundidadeGlobal == 1){
    //     Diretorio(tamanhoBalde);
    // }
    // else{

    this->profundidadeGlobal = profundidadeGlobal;
    this->tamanhoBalde = tamanhoBalde;

    for(int i=0 ; i < 1 << profundidadeGlobal ; i++) // 1 * 2^profundidadeGlobal
        vectorBaldes.push_back(new Balde(tamanhoBalde));



    //}
}

Diretorio::~Diretorio(){
    delete &vectorBaldes;
}

int Diretorio::retornaIndexCorrespondenteBitsBinarios(string pseudoChave){
    // a profundidadeGlobal eh igual ao numero de bits da pseudoChave que precisa ser usado para identificar o balde correto
    int numeroDeBits = profundidadeGlobal;
    string convertendoPseudoChave = pseudoChave;
    while (convertendoPseudoChave.size()!= numeroDeBits){
        convertendoPseudoChave.pop_back();
    }
    return stoi(convertendoPseudoChave, 0, 2);  //retorna index em inteiro


}

void Diretorio::inserePseudoChave(string pseudoChave){
    int indexB = retornaIndexCorrespondenteBitsBinarios(pseudoChave);
    if(!vectorBaldes[indexB]->baldeCheio()){
        //insere
        vectorBaldes[indexB]->inserePseudoChave(pseudoChave);
    }
    else{
        if(vectorBaldes[indexB]->getProfundidadeLocal() == profundidadeGlobal){
            //duplica o tamanho do diretório
        }
        //divide o balde e incrementa a profundidadeLocal
    }
    //verificar a pseudoChave
    //comparar o numero de bits que importa
    //
    
}

int Diretorio::getProfundidadeGlobal(){
    return profundidadeGlobal;
}

int Diretorio::getTamanhoBalde(){
    return profundidadeGlobal;
}

void Diretorio::imprime(){
    // o diretorio tem 2^profundidadeGlobal posicoes
    cout << "Profundidade Global do diretorio : "<< getProfundidadeGlobal() << endl;
    for(int i=0 ; i < 1 << getProfundidadeGlobal() ; i++){
        cout <<"Posicao do diretorio : "<< i << " , tem o conteudo : "<<vectorBaldes[i]<<
        ", com as chaves : ";
        vectorBaldes[i]->imprimePseudoChaves();
    }
}

        //void inserePseudoChave();
        void buscaPseudoChave();
        void divideBalde();
        void duplicaDiretorio();
