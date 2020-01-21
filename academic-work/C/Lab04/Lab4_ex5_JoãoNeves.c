/*
Escreva um programa que solicite ao utilizador para inserir dois numeros,
o primeiro maior que o segundo.
Enquanto esta condi��o n�o se verificar, imprima uma mensagem a indicar
que n�o respeitou o requisito e volte a pedir.
*/
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int num1;
    int num2;
    do {
        printf("Insira dois n�meros.\nO primeiro tem que ser maior que o segundo.\n");

        printf("Primeiro n�mero: ");
        scanf("%d", &num1);
        printf("Segundo n�mero: ");
        scanf("%d", &num2);
        
        if (!(num1 > num2)){
            printf("Errado! ");

            if (num1 < num2) {
                printf("O segundo n�mero � maior que o primeiro!");

            } else if ( num1 == num2 ) {
                printf("Os n�meros s�o iguais!");
            }
            
            printf("\n\n");
            
        } else {
            printf("Perfeito! Obrigado!\n");
        }

    } while ( num1 <= num2 );

    system("pause");
    return 0;
}

