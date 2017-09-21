/**
 *  Algoritmo de Pesquisa Sequêncial
 *  author  : Walderlan Sena <eu@walderlan.xyz>
 *  site    : https://github.com/WalderlanSena/algoritmosDeOrdenacao
 *  licence : MIT
 */
#include <iostream>

using namespace std;

// ---------- Protótipos das funções --------
int buscaSequencial(int value, int vet[], int tam);

/**
 *  Inicio Metódo main
 */
int main(int argc, char *argv[])
{
    int vetor[] = {123,434,5,565,54,2,6,57,23,345};                             //Cria um vetor de 10 posições

    cout << "Valor encontrado    : " << buscaSequencial(54, vetor,10) << endl;  //Passando um valor que existe no vetor
    cout << "Valor não econtrado : " << buscaSequencial(1, vetor, 10) << endl;  //Passando um valor que não existe no vetor
}//end main

// ---------- Implementação das Funções --------

/**
 *  @param value => Valor que deseja encontrar
 *  @param vet[] => Vetor com os valores a serem buscados
 *  @param tam   => Tamanho do vetor passado
 */
int buscaSequencial(int value, int vet[], int tam)
{
    for (int i = 0; i < tam; i++)                   //For que realiza a iteração no vetor de inteiros
      if (vet[i] == value)                          //Verifica se o valor atual percorrido é equivalente ao valor passado
        return i;                                   //Caso seja retorna a posição que o mesmo se encontra
    return -1;                                      //Caso não encontre o valor retorn -1
}//end metódo buscaSequencial
