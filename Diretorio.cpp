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
        vector<string> pcArmazenadas;
        for (int i = 0; i < tamanhoBalde; i++)
        {
            pcArmazenadas.push_back(vectorBaldes[indexBalde]->getPseudoChave(i));
        }
        divideBalde(indexBalde,pseudoChave);
        for (int i = 0; i < pcArmazenadas.size(); i++){
            inserePseudoChave(pcArmazenadas[i]);
        }
        cout << "pseudoChave que causou OverFlow : " << pseudoChave<<endl;
        inserePseudoChave(pseudoChave);
    }
}

void Diretorio::divideBalde(int indexBalde, string pseudoChave)
{                                               // vectorBaldes[indexBalde] -> será o balde a ser "dividido"
    Balde *baldeCopia = new Balde(tamanhoBalde, (vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    Balde *baldeNovo = new Balde(tamanhoBalde, (vectorBaldes[indexBalde]->getProfundidadeLocal()+1));
    cout << " endereco do balde que deu overflow : "<< vectorBaldes[indexBalde]<<endl;
    vectorBaldes[indexBalde]=baldeCopia;
    string binario = pseudoChave.substr(0, profundidadeGlobal);
    if(*binario.end() == '1')
        *binario.end() = '0';
    else *binario.end() = '1';
    int indexBaldeNovo = retornaIndexInteiroCorrespondenteBitsBinarios(binario);
    vectorBaldes[indexBaldeNovo] = baldeNovo;
}

void Diretorio::duplicaDiretorio(){
    
    profundidadeGlobal++;

    vector<Balde*> novosBaldes;

    for (int i = 0; i < pow(2, profundidadeGlobal); i++)
    {
        novosBaldes.push_back(nullptr);
    }

    for (unsigned int i = 0; i < vectorBaldes.size(); i++)
    {
        if(i!=1)
        {
            novosBaldes[i*i] = vectorBaldes[i];
            novosBaldes[(i*i)+1] = vectorBaldes[i];
        }
        else
        {
            novosBaldes[2] = vectorBaldes[1];
            novosBaldes[3] = vectorBaldes[1];
        }
    }
    vectorBaldes = novosBaldes;
        
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

