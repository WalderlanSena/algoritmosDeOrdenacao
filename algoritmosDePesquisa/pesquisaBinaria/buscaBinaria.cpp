/**
 *  Algoritmo de Pesquisa Binária
 *  author  : Walderlan Sena <eu@walderlan.xyz>
 *  site    : https://github.com/WalderlanSena/algoritmosDeOrdenacao
 *  licence : MIT
 */
#include <iostream>

using namespace std;

// ---------- Protótipos das funções --------
int buscaBinaria(int value, int vet[], int tam);

/**
 *  Inicio Metódo main
 */
int main(int argc, char *argv[])
{
    int vetor[] = {1,23,35,46,58,66,75,88,999,1000};                           //Cria um vetor de 10 posições

    cout << "Valor encontrado    : " << buscaBinaria(75, vetor,10) << endl;    //Passando um valor que existe no vetor
    cout << "Valor não econtrado : " << buscaBinaria(3123, vetor, 10) << endl; //Passando um valor que não existe no vetor
}//end main

// ---------- Implementação das Funções --------

/**
 *  @param value => Valor que deseja encontrar
 *  @param vet[] => Vetor com os valores a serem buscados
 *  @param tam   => Tamanho do vetor passado
 */
int buscaBinaria(int value, int vet[], int tam)
{
    // Variaveis que recebem os posicionamentos
    int inicio = 0,
        meio   = 0, 
        fim    = 0;

    // Atribuido os valores iniciais as variaveis
    inicio     = 0;                 //Posição inicial do vetor
    fim        = tam-1;             //Tamanho do vetor -1
    meio       = (inicio+fim)/2;    //Inicio do vetor mais o fim divido por 2
    
    // Inicio do laço de verificação/Busca
    while (value != vet[meio] && inicio != fim) {   //Enquanto o valor buscado for diferente do valor iterado do vetor atual
        if (value > vet[meio]) {                    //Se o value buscado for maior que o posicionamento do vetor iterado no momento
            inicio = meio + 1;                      //O inicio recebe o meio mais um. Ou seja, obtem a posição atual e passa para o posterior
            meio   = (inicio + fim)/2;              //Recalcula o posicionamento do meio após a modifição anterior 
        } else {                                    //Caso o value que está sendo buscado não seja maior que o meio iterado
            fim    = meio;                          //O fim do vetor recebe o valor do meio atual
            meio   = (inicio + fim)/2;              //E refaz o calculo do posicionamento do meio tendo o inicio mais o fim divido por 2
        }//end if
    }//end while

    // Verificando se o valor foi encontrado
    if (value == vet[meio]) {                       //Se o valor que está sendo procurado é igual o posição do vetor iterado no momento
        return meio;                                //Retorna a posição que o valor foi encontrado
    } else {                                        //Se não for encontrado o valor pesquisado no vetor
        return -1;                                  //Retorna -1 pois o valor não foi encontrado no vetor atual
    }//end if
}//end metódo buscaBinaria
