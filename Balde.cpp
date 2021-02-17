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
    this->bitsIniciais = "";
    this->numeroDePseudoChavesNoBalde = 0;
}

Balde::Balde(int tamanhoBalde, int profundidadeLocal){
    this->tamanhoBalde = tamanhoBalde;
    this->profundidadeLocal = profundidadeLocal;
    this->bitsIniciais = "";
    this->numeroDePseudoChavesNoBalde = 0;
}

Balde::~Balde() {}

void Balde::inserePseudoChaveNoBalde(string pseudoChave){
    this->vectorPseudoChaves.push_back(pseudoChave);
    this->numeroDePseudoChavesNoBalde += 1;
}

bool Balde::baldeCheio(){
    if(vectorPseudoChaves.size() == tamanhoBalde)
        return true;
    else return false;
}

int Balde::getProfundidadeLocal(){
    return this->profundidadeLocal;
}

string Balde::getPseudoChave(int indice){
    return this->vectorPseudoChaves[indice];
}

void Balde::aumentaProfundidadeLocal(){
    this->profundidadeLocal = this->profundidadeLocal + 1;
}

string Balde::getBitsIniciais(){
    return this->bitsIniciais;
}

void Balde::setBitsIniciais(string bitsIniciais){
    this->bitsIniciais = bitsIniciais;
}

int Balde::getNumeroDePseudoChavesNoBalde(){
    return this->numeroDePseudoChavesNoBalde;
}

