/*

By: Jo�o Neves (SHIVAYL)

Escreva um programa que cria um padr�o duma pir�mide de asteriscos.
Use uma vari�vel para saber, em cada linha, quantos espa�os deve
imprimir antes dos asteriscos.

Exemplo de funcionamento:
Insira o n�mero de linhas: -1
Tem que ser um n�mero maior que 0.
Insira o n�mero de linhas: 4
   *
  * *
 * * *
* * * *

*/
#include <stdio.h>
#include <locale.h>

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");

    int inputNum;
    
    do {
        printf("Give me a positive number: ");
        scanf("%d", &inputNum);
        
        if (inputNum < 0) {
            printf("No! I want a positive number!\n\n");
        
        } else {
            printf("Thanks!\n\n");
        }
        
    } while (inputNum < 0);
    
    int numOfSpaces = inputNum - 1;
    int i;
    int j;
    for (i = 0; i < inputNum; ++i, --numOfSpaces) {
        for (j = 0; j < numOfSpaces; ++j) {
            printf(" ");
        }

        for (j = 0; j < i + 1; ++j) {
            printf("* ");
        }
        
        printf("\n");
    }
    
    printf("\n");
    system("pause");
	return 0;
}

