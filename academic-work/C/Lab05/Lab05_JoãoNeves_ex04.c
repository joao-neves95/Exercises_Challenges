/*

By: Jo�o Neves (SHIVAYL)

Escreva um programa que pede um inteiro positivo (se n�o o for, pe�a novamente).
Apresente no ecr� um padr�o semelhante a metade de um triangulo com n�meros.
Recorra a um ciclo que imprime os numeros de 1 a n. No entanto, em cada itera��o, 
dever� ter um segundo ciclo que repete a impress�o desse n�mero a devida quantidade de vezes.

Exemplo de funcionamento:
Insira o n�mero de linhas: -1
Tem que ser um n�mero maior que 0.
Insira o n�mero de linhas: 7
1
22
333
4444
55555
666666
7777777

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
    
    int i;
    int j;
    for (i = 1; i <= inputNum; ++i) {
        for (j = 0; j < i; ++j) {
            printf("%2d", i);
        }

        printf("\n");
    }

    system("pause");
	return 0;
}



