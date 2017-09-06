/**
 *  Algoritmo de Ordenação e Pesquisa em c++
 *  @version:1.0.0
 *  Modo de Ordenação Selection Sort lendo valores inteiros de um arquivo e ordenando
 *  @author: Walderlan Sena <eu@walderlan.xyz>
 *
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define NAMEFILE    "Lista01.txt"   //Nome do arquivo a ser lido

/**
 *  Protótipos das funções
 */
void readDataFile(void);
int coutLine(void);
void selectionSort(int vetor[], int tam);

/**
 *  Inicio método main
 */
int main(int argc, char *argv[])
{
    /**
     *  Chamando a função ler o arquivo e chama a função selectionSort para realizar a
     *  ordenação dos dados
     */
    readDataFile();

    return 0;                           //Retorna 0 para o sistema operacional
}//end main

void readDataFile()
{
    FILE *arquivo;          //Criando um ponteiro do tipo file, que amazenará o endereço do arquivo
    int numerosRead;        //Recebe cada linha lida em cada execução do laço
    int tam = coutLine();   //Variavel que recebe o retorno da função com a quantidade de linha do arquivo a ser ordenado
    int numTemp[tam];       //Arra que recebe as linhas lidas do arquivo
    int i = 0;              //Variavel que realiza iterações no laço while

    arquivo = fopen(NAMEFILE,"r");    //Abrir o arquivo em modo de leitura (r => read)

    if (arquivo != NULL) {                 //Verifica se foi possivel abrir o arquivo
        /**
         *  Inicio de leitura do arquivo especificado
         *  Ler o arquivo e armazenar cada linha durante a iteração na variavel numerosRead
         *  EOF => Singnifia End Of File, ou seja, enquanto for diferente do fim do arquivo
         */
        while(fscanf(arquivo, "%d", &numerosRead) != EOF){
            numTemp[i] = numerosRead;
            i++;
        }//end while
        /**
         *  Chama a função que ordena os dados
         *  @params Array com os dados a serem ordenados
         *  @params Tamanho de array passado
         */
        selectionSort(numTemp,tam);
    } else {
        cout << "Error ! Não foi possivel abrir o arquivo !" << endl;
    }//end if

    fclose(arquivo);    //Fechado o arquivo

}//end openFile

/**
 *  Função que ler a quantidade de linha contida no arquivo de texto
 */
int coutLine()
{
    int tam = 0,                                //Recebe a quantidade de linhas
        line;                                   //Armazena cada linha lida
    FILE *arq = fopen(NAMEFILE,"r");            //Abri o arquivo
    if (arq != NULL) {
        while(fscanf(arq, "%d", &line) != EOF)  //Laço que percorre as linhas do arquivo
        tam++;                                  //Incrementa a quantidade de linha obtidas
        fclose(arq);                            //Fecha o arquivo
    } else {
        cout << "Error ! Não foi posivel abrir o arquivo.." << endl;
        exit(1);                                //Retorna 1 para o sistema operacional
    }//end if
    return tam;                                  //Retona a quantidade de linha
}//end coutLine

/**
 *  Função que realiza a ordenação pelo método de selectionSort
 *  @params Recebe um vetor de interios a serem ordenados
 *  @params Recebe o tamanho do vetor passado
 */
void selectionSort(int vetor[], int tam)
{
    int valorMenor,  //Variavel que receberá valor valorMenororario de um vetor respectivo
        aux;         //Variavel que sempre recebe o menor valor existe no array

    for (int i = 0; i < (tam - 1); i++) {

        aux = i;                                //Armazena o valor de i atual no laço

        for (int j = (i + 1); j < tam; j++) {
            if (vetor[aux] > vetor[j]) aux = j; //Verifica se o vetor atual e maior que o posterior
        }//end for 2

        // Realizando a substitução de valores
        valorMenor = vetor[aux];                //valorMenor recebe o valor menor encontado

        /**
         *  Realiza a substituição dos valores do menor para o maior
         */
        vetor[aux] = vetor[i];      //Vetor A recebe vetor B
        vetor[i]   = valorMenor;    //Vetor B recebe vetor A

        /**
         *  For que imprime o valor após cada possivel modificação
         */
        for (int i = 0; i < tam; i++) {
            cout << vetor[i] << "\t";   //Cout que imprime o array com um tab
        }//end for
        cout << endl;                   //Cout quebra uma linha
    }//end for 1
}//end selectionSort
