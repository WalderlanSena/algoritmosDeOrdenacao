/**
 *  Algoritmo de Ordennação e Pesquisa em c++
 *  @version:1.0.0
 *  Modo de Ordenação Selection Sort
 *  @author: Walderlan Sena <eu@walderlan.xyz>
 *
 */
#include <iostream>

using namespace std;

/**
 *  Protótipos das funções
 */
void selectionSort(int vetor[], int tam);

/**
 *  Inicio método main
 */
int main(int argc, char *argv[]) {

    /**
     *  Os valores a serem impressos devem ser:
     ****************************************************
     *  0	21	1	9	8	2	80	123
     *  0	1	21	9	8	2	80	123
     *  0	1	2	9	8	21	80	123
     *  0	1	2	9	8	21	80	123
     *  0	1	2	9	8	21	80	123
     *  0	1	2	9	8	21	80	123
     *  0	1	2	9	8	21	80	123  -> Saida final com os valores Ordenados
     */
    int vet[8] = {123,21,1,9,8,2,80,0}; //Array valores a serem ordenados

    selectionSort(vet, 8);              //Chamando a função de ordenação

    return 0;                           //Retorna 0 para o sistema operacional
}//end main
/**
 *  Função que realiza a ordenação pelo método de selectionSort
 *  @params Recebe um vetor de interios a serem ordenados
 *  @params Recebe o tamanho do vetor passado
 */
void selectionSort(int vetor[], int tam)
{
    int valorMenor,  //Variavel que receberá valor valorMenororario de um vetor respectivo
        aux;         //Variavel que sempre recebe o menor valor existe no array

    for (int i = 0; i < (tam - 1); i++) {       //For que percorre o array mais +1

        aux = i;                                //Armazena o valor de i atual no laço

        for (int j = (i + 1); j < tam; j++) {
            if (vetor[aux] > vetor[j]) aux = j; //Verifica se o vetor atual e maior que o posterior
        }//end for 2

        // Realizando a substitução de valores
        valorMenor = vetor[aux];    //valorMenor recebe o valor menor encontado
        /**
         *  Realiza a substituição dos valores do menor para o maior
         */
        vetor[aux] = vetor[i];      //Vetor A recebe vetor B
        vetor[i]   = valorMenor;    //Vetor B recebe vetor A

        /**
         *  For que imprime o valor após cada possivel modificação
         */
        for (int i = 0; i < 8; i++) {
            cout << vetor[i] << "\t";   //Cout que imprime o array com um tab
        }//end for
        cout << endl;                   //Cout quebra uma linha
    }//end for 1
}//end selectionSort
