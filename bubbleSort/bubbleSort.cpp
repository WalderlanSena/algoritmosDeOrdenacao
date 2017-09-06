/**
 *  Algoritmo de Ordenação e Pesquisa em c++
 *  @version:1.0.0
 *  Modo de Ordenação BubbleSort
 *  @author: Walderlan Sena <eu@walderlan.xyz>
 *
 */
#include <iostream>

using namespace std;

/** Protótipos das funções  **/
void bubbleSort(int vetor[], int size);

int main(int argc, char *argv[])
{
    int vetor[] = {153,32,13,43,15,62};

    bubbleSort(vetor, 6);

    return 0;
}//end main

/**
 *  Função que realiza a ordenação no modo bubbleSort
 */
void bubbleSort(int vetor[], int tam)
{
    int control,
        aux,
        fim = tam;

        for (int fim = tam-1; fim > 0; --fim) {
            for (int i = 0; i < fim; ++i) {
                if (vetor[i] > vetor[i+1]) {
                    int aux = vetor[i];
                    vetor[i] = vetor[i+1];
                    vetor[i+1] = aux;
                }
            }
        }
    for (int i = 0; i < tam; i++) {
        cout << vetor[i] << "  ";
    }//end for
}//end function bubbleSort
