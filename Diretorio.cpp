#include <vector>
#include <string>
#include <iostream>
#include <bitset>
#include <algorithm>
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

Diretorio::~Diretorio() {}

int Diretorio::retornaIndexInteiroCorrespondenteBitsBinarios(string pseudoChave)
{
    // a profundidadeGlobal eh igual ao numero de bits da pseudoChave que precisa ser usado para identificar o balde correto
    string convertendoPseudoChave = pseudoChave;
    while (convertendoPseudoChave.size() != profundidadeGlobal)
        convertendoPseudoChave.pop_back();
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
            //divide o balde e duplica o tamanho do diretório
            duplicarDiretorio(vectorBaldes[indexBalde], pseudoChave);
            inserePseudoChave(pseudoChave);
        }

        else if (this->profundidadeGlobal > vectorBaldes[indexBalde]->getProfundidadeLocal())
        {
            //divide o balde
            dividir(vectorBaldes[indexBalde], pseudoChave);
            inserePseudoChave(pseudoChave);
        }
    }
}

string Diretorio::toBinary(int numBits, int n)
{
    string r;
    for (int i = 0; i < numBits; i++)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}

void Diretorio::dividir(Balde *baldeOriginal, string pos)
{
    baldeOriginal->aumentaProfundidadeLocal();
    Balde *baldeCopia = new Balde(tamanhoBalde, baldeOriginal->getProfundidadeLocal());
    Balde *baldeNovo = new Balde(tamanhoBalde, baldeOriginal->getProfundidadeLocal());
    baldeNovo->setBitsIniciais("");
    baldeCopia->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(0));
    //insere uma pseudoChave que estava no balde que deu overflow pra tomar ela como parametro de bitsIniciais pro baldeCopia
    baldeCopia->setBitsIniciais(baldeCopia->getPseudoChave(0).substr(0, baldeCopia->getProfundidadeLocal()));
    //profundidade local é a quantidade de bits que precisa na string bitsIniciais
    for (int i = 1; i < baldeOriginal->getNumeroDePseudoChavesNoBalde(); i++)
    {//distribui as chaves que estavam faltando dentro do balde original
        if (baldeCopia->getBitsIniciais() == baldeOriginal->getPseudoChave(i).substr(0, baldeOriginal->getProfundidadeLocal()))
            baldeCopia->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(i));
        else
            baldeNovo->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(i));
    }

    if (baldeNovo->getNumeroDePseudoChavesNoBalde() > 0) //se o baldeNovo nao estiver vazio , seta os BitsIniciais
        baldeNovo->setBitsIniciais(baldeNovo->getPseudoChave(0).substr(0, baldeNovo->getProfundidadeLocal()));

    for (int i = 0; i < vectorBaldes.size(); i++) // Ajusta ponteiros do diretorio e seta bitsIniciais corretamente
    {
        string bitsIniciaisDiretorio = toBinary(profundidadeGlobal, i).substr(0, baldeCopia->getProfundidadeLocal());

        if (bitsIniciaisDiretorio == baldeCopia->getBitsIniciais())
        {
            vectorBaldes[i] = baldeCopia;
            vectorBaldes[i]->setBitsIniciais(bitsIniciaisDiretorio); 
        }
        else if (bitsIniciaisDiretorio == baldeNovo->getBitsIniciais())
        {
            vectorBaldes[i] = baldeNovo;
            vectorBaldes[i]->setBitsIniciais(bitsIniciaisDiretorio);
        }
    }

    //se o baldeOriginal ainda estiver no diretório, eh pq o baldeNovo
    //esta vazio, e devemos coloca-lo no lugar do baldeOriginal
    for (int i = 0; i < vectorBaldes.size(); i++)
    {
        if (vectorBaldes[i] == baldeOriginal)
        {
            vectorBaldes[i] = baldeNovo;
            vectorBaldes[i]->setBitsIniciais(toBinary(profundidadeGlobal, i).substr(0, vectorBaldes[i]->getProfundidadeLocal()));
        }
    }

    delete baldeOriginal;
}

void Diretorio::duplicarDiretorio(Balde *baldeOriginal, string pos)
{
    this->profundidadeGlobal = profundidadeGlobal + 1;
    baldeOriginal->aumentaProfundidadeLocal();
    vector<Balde *> guardaBaldes;
    Balde *baldeCopia = new Balde(tamanhoBalde, baldeOriginal->getProfundidadeLocal());
    Balde *baldeNovo = new Balde(tamanhoBalde, baldeOriginal->getProfundidadeLocal());
    baldeNovo->setBitsIniciais(baldeOriginal->getBitsIniciais());
    baldeCopia->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(0));
    baldeCopia->setBitsIniciais(baldeCopia->getPseudoChave(0).substr(0, baldeCopia->getProfundidadeLocal()));

    string novoBitsIniciais = baldeCopia->getBitsIniciais();
    if (baldeCopia->getBitsIniciais()[baldeCopia->getBitsIniciais().size() - 1] == '0')

    {
        novoBitsIniciais.pop_back();
        novoBitsIniciais.push_back('1');
        baldeNovo->setBitsIniciais(novoBitsIniciais);
    }
    else
    {
        novoBitsIniciais.pop_back();
        novoBitsIniciais.push_back('0');
        baldeNovo->setBitsIniciais(novoBitsIniciais);
    }

    for (int i = 1; i < baldeOriginal->getNumeroDePseudoChavesNoBalde(); i++)
    {
        if (baldeCopia->getBitsIniciais() == baldeOriginal->getPseudoChave(i).substr(0, baldeOriginal->getProfundidadeLocal()))
            baldeCopia->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(i));
        else
            baldeNovo->inserePseudoChaveNoBalde(baldeOriginal->getPseudoChave(i));
    }
    guardaBaldes.push_back(baldeCopia);
    guardaBaldes.push_back(baldeNovo);

    for (int i = 0; i < vectorBaldes.size(); i++)
    {
        if (vectorBaldes[i] != baldeOriginal)
            guardaBaldes.push_back(vectorBaldes[i]);
    }

    for (int i = 0; i < 1 << (profundidadeGlobal - 1); i++)
        this->vectorBaldes.push_back(nullptr);

    for (int i = 0; i < guardaBaldes.size(); i++)
    {
        for (int x = 0; x < vectorBaldes.size(); x++)
        {
            string bitsIniciaisDiretorio = toBinary(profundidadeGlobal, x).substr(0, guardaBaldes[i]->getProfundidadeLocal());

            if (bitsIniciaisDiretorio == guardaBaldes[i]->getBitsIniciais())
                vectorBaldes[x] = guardaBaldes[i];
        }
    }

    delete baldeOriginal;
}

void Diretorio::imprime()
{
    
}

Balde Diretorio::getBalde(int indice)
{
    return *this->vectorBaldes[indice];
}

int Diretorio::size()
{
    return this->vectorBaldes.size();
}

void Diretorio::buscaPseudoChave(string pseudoChave)
{
    int indexBalde = retornaIndexInteiroCorrespondenteBitsBinarios(pseudoChave);
    for (int i = 0; i < tamanhoBalde; i++)
    {
        if (vectorBaldes[indexBalde]->getPseudoChave(i) == pseudoChave)
        {
            cout << "Estou no balde de endereco : " << &vectorBaldes[indexBalde] << endl;
        }
    }
    cout << "Esta pseudo-chave nao foi encontrada" << endl;
}
