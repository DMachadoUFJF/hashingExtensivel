#include <vector>
#include <bits/stdc++.h>
#include "Balde.h"
#include "Diretorio.h"

using namespace std;


string retornaPseudoChaveAleatoria(int numeroBits){
    unsigned int seed = (std::chrono::system_clock::now().time_since_epoch().count())/1000;
    string pseudoChave;
    for(int i=0;i<numeroBits;i++){
        seed = (std::chrono::system_clock::now().time_since_epoch().count())/1000;
        srand (seed+i);
        pseudoChave = pseudoChave + to_string(rand()%2);
    }
    return pseudoChave;
}

int main()
{
    int tamanhoBalde,numeroBits;
    cout << "Digite o tamanho do balde : "<<endl; //
    cin >> tamanhoBalde;
    cout << "Digite o numero de bits a ser usado para as pseudo-chaves : "<<endl;
    cin >> numeroBits;
    Diretorio dir(tamanhoBalde);
    // string x = retornaPseudoChaveAleatoria(numeroBits);
    // bucketzada.inserePseudoChave(x);
    // bucketzada.removePseudoChave(x);
    // bucketzada.inserePseudoChave(retornaPseudoChaveAleatoria(numeroBits));
    // bucketzada.inserePseudoChave(retornaPseudoChaveAleatoria(numeroBits));

    
    return 0;
}


// A função principal deve solicitar ao usuário o tamanho M a ser usado 
// para os baldes e o número de bits B a ser usado para as pseudo-chaves.

// RANDOMIZA B NUMEROS DE 0 A 100 E FAZ RESTO 2 PRA FORMAR UMA 
// PSEUDO CHAVE EM FORMA DE STRING , CONCATENANDO OS B NUMEROS RANDOMIZADOS



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
