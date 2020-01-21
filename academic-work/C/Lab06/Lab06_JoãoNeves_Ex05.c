/*

By: Jo�o Neves (SHIVAYL)

Defina tr�s vetores de inteiros de dimens�o 5, v_input, v_pares e v_impares.

� Inicialize v_pares e v_impares com 0.
� Preencha v_input com inteiros maiores ou iguais a 0, pedidos ao utilizador.
  Caso um dos n�meros n�o o seja, pedir novamente.
� Separe os inteiros pares e impares em vetores separados.
  Para tal, dever� ter um contador de n�meros pares e impares que vai crescendo
  � medida que encontra um n�mero par/�mpar, e assim saber qual o �ndice do �ltimo
  elemento inserido.
� Imprima os vetores, um por linha.
  Apenas imprima os campos preenchidos de v_impares/v_pares.
  Dever� utilizar o contador de n�meros pares/impares inseridos, para saber quantos
  n�meros tem o vetor v_pares/v_impares.
� Exemplo de funcionamento:
Insira um n�mero: 5
Insira um n�mero: 6
Insira um n�mero: 3
Insira um n�mero: 8
Insira um n�mero: 7
N�meros inseridos: 5 6 3 8 7
N�meros pares: 6 8
N�meros impares: 5 3 7

*/
#include <stdio.h>
#include <locale.h>

#define NUM_COUNT 5

void printIntArr(int intArr[], size_t size);

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");

    printf("Par ou Impar \n\n");
    
    int v_input[NUM_COUNT];
    // Em C, desta forma o compilador inicializa todas as ints a 0.
    // Em C++, n�o ser�a sequer necess�rio inicializar a 0, ser�a autom�tico :)
    int v_pares[NUM_COUNT] = { 0 };
    int v_impares[NUM_COUNT] = { 0 };
    
    int iPares;
    int iImpares;
    int iInput;
    for (iInput = 0, iPares = 0, iImpares = 0; iInput < NUM_COUNT; ++iInput) {
        do {
            printf("Insira um n�mero: ");
            scanf("%d", &v_input[iInput]);
    
            if (v_input[iInput] < 0) {
                printf("O n�mero tem que ser maior que 0!\n");
            }
    
        } while (v_input[iInput] < 0);
        
        if (v_input[iInput] % 2 == 0) {
            v_pares[iPares] = v_input[iInput];
            ++iPares;
        
        } else {
            v_impares[iImpares] = v_input[iInput];
            ++iImpares;
        }
    }
    
    printf("\n\n");
    printf("N�meros inseridos: ");
    printIntArr(v_input, NUM_COUNT);
    printf("\n");
    
    printf("N�meros pares: ");
    printIntArr(v_pares, iPares);
    printf("\n");
    
    printf("N�meros impares: ");
    printIntArr(v_impares, iImpares);
    printf("\n\n");
    
    system("pause");
	return 0;
}

void printIntArr(int intArr[], size_t size) {
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", intArr[i]);
    }
}

