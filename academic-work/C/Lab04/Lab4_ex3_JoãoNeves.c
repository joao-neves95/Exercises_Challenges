/*
Crie um programa que, utilizando um switch:
� solicita a introdu��o do n�mero de um m�s.
� apresenta o nome desse m�s por extenso.
� Caso o n�mero n�o corresponda a um m�s v�lido, dever� mostrar a mensagem �M�s Inv�lido�.
Exemplo de intera��o com o utilizador:
Insira um numero do mes: 2
O mes 2 corresponde a fevereiro
*/
#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    printf("Insira um n�mero do m�s: ");
    short monthInput;

    scanf("%hd", &monthInput);
    printf("O m�s %hd corresponde a ", monthInput);

    switch(monthInput) {
        case 1:
            printf("janeiro");
            break;
        case 2:
            printf("fevereiro");
            break;
        case 3:
            printf("mar�o");
            break;
        case 4:
            printf("abril");
            break;
        case 5:
            printf("maio");
            break;
        case 6:
            printf("junho");
            break;
        case 7:
            printf("julho");
            break;
        case 8:
            printf("agosto");
            break;
        case 9:
            printf("setembro");
            break;
        case 10:
            printf("outubro");
            break;
        case 11:
            printf("novembro");
            break;
        case 12:
            printf("dezembro");
            break;
        default:
            printf("UM M�S INV�LIDO!.");
            return 1;
    }

    system("pause");
    return 0;
}

