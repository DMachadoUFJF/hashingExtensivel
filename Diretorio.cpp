#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include "Diretorio.h"
using std::bitset;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

Diretorio::Diretorio(int tamanhoBalde)
{
    this->profundidadeGlobal = 1;
    this->tamanhoBalde = tamanhoBalde;
    Balde *novoBalde = new Balde(tamanhoBalde);
    for (int i = 0; i < 1 << profundidadeGlobal; i++) // 1 * 2^profundidadeGlobal
        vectorBaldes.push_back(novoBalde);            //vai criar um diretorio com 2 ponteiros pra 1 balde
}

Diretorio::Diretorio(int tamanhoBalde, int profundidadeGlobal)
{
    this->profundidadeGlobal = profundidadeGlobal;
    this->tamanhoBalde = tamanhoBalde;
    Balde *novoBalde = new Balde(tamanhoBalde);
    for (int i = 0; i < 1 << profundidadeGlobal; i++) // 1 * 2^profundidadeGlobal
        vectorBaldes.push_back(novoBalde);
}

Diretorio::~Diretorio() {}

int Diretorio::retornaIndexInteiroCorrespondenteBitsBinarios(string pseudoChave)
{
    // a profundidadeGlobal eh igual ao numero de bits da pseudoChave que precisa ser usado para identificar o balde correto
    int numeroDeBits = profundidadeGlobal;
    string convertendoPseudoChave = pseudoChave;
    while (convertendoPseudoChave.size() != numeroDeBits)
    {
        convertendoPseudoChave.pop_back();
    }
    return stoi(convertendoPseudoChave, 0, 2); //retorna index em inteiro
}

void Diretorio::inserePseudoChave(string pseudoChave)
{
    //indexBalde que a pseudoChave dever ser inserida
    int indexBalde = retornaIndexInteiroCorrespondenteBitsBinarios(pseudoChave);

    if (!vectorBaldes[indexBalde]->baldeCheio())
    { //se tem espaco , insere
        vectorBaldes[indexBalde]->inserePseudoChaveNoBalde(pseudoChave);
    }
    else
    {
        if (vectorBaldes[indexBalde]->getProfundidadeLocal() == profundidadeGlobal)
        {
            //duplica o tamanho do diretório
            duplicaDiretorio();
        }
        
        divideBalde(indexBalde,pseudoChave);
        inserePseudoChave(pseudoChave);
    }
}

string Diretorio::toBinary(int n,int numBits)
{
    string r;
    for(int i=0 ; i<numBits ; i++){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    reverse(r.begin(),r.end());
    return r;
}

void Diretorio::divideBalde(int indexBalde, string pseudoChave)
{   // vectorBaldes[indexBalde] -> será o balde a ser "dividido"
    Balde *baldeCopia = new Balde(tamanhoBalde, (vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    Balde *baldeNovo = new Balde(tamanhoBalde, (vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    baldeCopia->setBitsIniciais(vectorBaldes[indexBalde]->getBitsIniciais());
    //cout << " endereco do balde que deu overflow : "<< vectorBaldes[indexBalde]<<endl;
    //insere uma pseudoChave que estava no balde que deu overflow pra tomar ela como parametro de bitsIniciais pro baldeCopia
    baldeCopia->inserePseudoChaveNoBalde(vectorBaldes[indexBalde]->getPseudoChave(0));
    //profundidade local é a quantidade de bits que precisa na string bitsIniciais
    baldeCopia->setBitsIniciais(baldeCopia->getPseudoChave(0).substr(0,baldeCopia->getProfundidadeLocal()));
    for(int i=1 ; i<tamanhoBalde ; i++){ //distribui as chaves que estavam faltando dentro do vectorBaldes[indexBalde]
        if(vectorBaldes[indexBalde]->getPseudoChave(i).empty())
            break;
        if(baldeCopia->getBitsIniciais() == vectorBaldes[indexBalde]->getPseudoChave(i).substr(0,baldeCopia->getProfundidadeLocal()))
            baldeCopia->inserePseudoChaveNoBalde(vectorBaldes[indexBalde]->getPseudoChave(i));
        else baldeNovo->inserePseudoChaveNoBalde(vectorBaldes[indexBalde]->getPseudoChave(i));//-> baldeNovo pode ficar vazio
    }
    delete vectorBaldes[indexBalde];

    if(baldeNovo->baldeVazio()) //Ajustando bitsIniciais do baldeNovo
        baldeNovo->setBitsIniciais("");
    else baldeNovo->setBitsIniciais(baldeNovo->getPseudoChave(0).substr(0, baldeNovo->getProfundidadeLocal()));
    
    for(int i=0 ; i<vectorBaldes.size() ; i++){ // Ajusta ponteiros do diretório
        string bitsIniciaisDiretorio = toBinary(i,profundidadeGlobal).substr(0,baldeCopia->getProfundidadeLocal());
        if(bitsIniciaisDiretorio == baldeCopia->getBitsIniciais())
            vectorBaldes[i]=baldeCopia;
        else if(bitsIniciaisDiretorio == baldeNovo->getBitsIniciais()){
            vectorBaldes[i]=baldeNovo;
            cout<<vectorBaldes[i]<<" eh o balde novo"<<endl;
        }
    }
}

void Diretorio::duplicaDiretorio(){
    cout<<"SE CHEGOU AQUI EH PQ DEU MERDA";
}

void Diretorio::imprime()
{
    // o diretorio tem 2^profundidadeGlobal posicoes
    cout << "Profundidade Global do diretorio : " << getProfundidadeGlobal() << endl;
    cout << "Endereco do vectorBaldes : " << &vectorBaldes << endl;
    for (int i = 0; i < 1 << getProfundidadeGlobal(); i++)
    {
        cout << "Posicao do diretorio : " << i << " , tem o conteudo : " << vectorBaldes[i] << ", com as chaves : ";
        vectorBaldes[i]->imprimePseudoChaves();
    }
}

int Diretorio::getProfundidadeGlobal()
{
    return profundidadeGlobal;
}

int Diretorio::getTamanhoBalde()
{
    return profundidadeGlobal;
}

void buscaPseudoChave();

