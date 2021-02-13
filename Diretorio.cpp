#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include "Diretorio.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::to_string;
using std::bitset;

Diretorio::Diretorio(int tamanhoBalde){
    this->profundidadeGlobal = 1;
    this->tamanhoBalde = tamanhoBalde;
    Balde* novoBalde = new Balde(tamanhoBalde);
    for (int i = 0; i < 1 << profundidadeGlobal; i++) // 1 * 2^profundidadeGlobal
        vectorBaldes.push_back(novoBalde); //vai criar um diretorio com 2 ponteiros pra 1 balde
}

Diretorio::Diretorio(int tamanhoBalde, int profundidadeGlobal){
    this->profundidadeGlobal = profundidadeGlobal;
    this->tamanhoBalde = tamanhoBalde;
    Balde* novoBalde = new Balde(tamanhoBalde);
    for (int i = 0; i < 1 << profundidadeGlobal; i++) // 1 * 2^profundidadeGlobal
        vectorBaldes.push_back(novoBalde);
}

Diretorio::~Diretorio(){}

int Diretorio::retornaIndexInteiroCorrespondenteBitsBinarios(string pseudoChave){
    // a profundidadeGlobal eh igual ao numero de bits da pseudoChave que precisa ser usado para identificar o balde correto
    int numeroDeBits = profundidadeGlobal;
    string convertendoPseudoChave = pseudoChave;
    while (convertendoPseudoChave.size()!= numeroDeBits){
        convertendoPseudoChave.pop_back();
    }
    return stoi(convertendoPseudoChave, 0, 2);  //retorna index em inteiro


}

void Diretorio::inserePseudoChave(string pseudoChave){
    int indexBalde= retornaIndexInteiroCorrespondenteBitsBinarios(pseudoChave);
    if(!vectorBaldes[indexBalde]->baldeCheio()){                            //se tem espaco , insere
        vectorBaldes[indexBalde]->inserePseudoChave(pseudoChave);
    }
    else{
        if(vectorBaldes[indexBalde]->getProfundidadeLocal() == profundidadeGlobal){
            //duplica o tamanho do diretório
        }
       // divideBalde(indexBalde,pseudoChave);
    }
    //verificar a pseudoChave
    //comparar o numero de bits que importa
    //
    
}

void Diretorio::divideBalde(int indexBalde,string pseudoChaveRestante){
    Balde* baldeA = new Balde(tamanhoBalde,(vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    Balde* baldeB = new Balde(tamanhoBalde,(vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    // pegar todo mundo do vectorBaldes que ta apontando pro vectorBaldes[indexBalde] e distribuir pros novos baldes
    for(int i=0 ; i<vectorBaldes.size();i++){ 
        if(vectorBaldes[i] == vectorBaldes[indexBalde]){
            if( retornaIndexInteiroCorrespondenteBitsBinarios(pseudoChaveRestante) == i ){
                //a pseudoChaveRestante deve entrar nesse balde ?  insere : nada
                baldeA->inserePseudoChave(pseudoChaveRestante); 
            }
            for(int x=0 ; x<tamanhoBalde ; x++){
                //procurar dentro do baldeAntigo , p ver se tem alguma chave dele que entraria no baldeA
                if(retornaIndexInteiroCorrespondenteBitsBinarios(vectorBaldes[indexBalde]->getPseudoChave(x))== i){
                    if(!baldeA->baldeCheio())
                        baldeA->inserePseudoChave(pseudoChaveRestante);
                    else{
                        //duplicaDiretorio
                    }
                }

            }

            //vectorBaldes[i] = baldeA;
        }

        //verifica os bits necessarios e rearranja as chaves
        
    }
}



void Diretorio::imprime(){
    // o diretorio tem 2^profundidadeGlobal posicoes
    cout << "Profundidade Global do diretorio : "<< getProfundidadeGlobal() << endl;
    cout << "Endereco do vectorBaldes : " << &vectorBaldes<<endl;
    for(int i=0 ; i < 1 << getProfundidadeGlobal() ; i++){
        cout <<"Posicao do diretorio : "<< i << " , tem o conteudo : "<<vectorBaldes[i]<<
        ", com as chaves : ";
        vectorBaldes[i]->imprimePseudoChaves();
    }
}

int Diretorio::getProfundidadeGlobal(){
    return profundidadeGlobal;
}

int Diretorio::getTamanhoBalde(){
    return profundidadeGlobal;
}

        void buscaPseudoChave();
        void duplicaDiretorio();
