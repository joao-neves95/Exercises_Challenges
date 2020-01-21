/*

By: Jo�o Neves (SHIVAYL)

*/
#include <stdio.h>
#include <locale.h>

int pede_numero();
void menu(int *option);
void factorial(int num);
void sum(int num);
void pair(int num);

int main()
{
    setlocale(LC_ALL, "");
    
    int num = pede_numero();
    
    int option;
    menu(&option);
    
    switch(option) {
        case 0:
            printf("Escolheu terminar o programa \n\n", option);

            system("pause");
            return 0;
            
        case 1:
            factorial(num);
            break;
            
        case 2:
            sum(num);
            break;
            
        case 3:
            pair(num);
            break;
    }

	return main();
}

int pede_numero() {
    int num;
    
    do {
        printf("Escreva um n�mero inteiro positivo: ");
        scanf("%d", &num);
        
        if (num < 0) {
            printf("O n�mero tem de ser positivo! \n\n");
        }
        
    } while (num < 0);
    
    return num;
}

void menu(int *option) {
    do {
        printf("Menu: \n");
        printf("1: Fatorial \n");
        printf("2: Soma dos inteiros \n");
        printf("3: Par \n");
        printf("0: TERMINAR PROGRAMA \n");
        
        printf("Escolha uma op��o do menu: ");
        // N�o � necess�rio o passar a referencia com "&",
        // pois um ponteiro j� � o endere�o da vari�vel.
        scanf("%d", option);
        
    } while (*option < 0 || *option > 3);
}

void factorial(int num) {
    int factorial = num;
    
    int i;
    for (i = num - 1; i > 0; --i) {
        factorial *= i;
    }
    
    printf("O factorial de %d �: %d \n\n", num, factorial);
}

void sum(int num) {
    int sum = 0;
    
    int i;
    for (i = 1; i < num; ++i) {
        sum += i;
    }
    
    printf("A soma de todos os n�meros inteiros at� %d �: %d \n\n", num, sum);
}

void pair(int num) {
    printf("O n�mero %d � ", num);
    
    if (num % 2 == 0) {
        printf("par. \n\n");

    } else {
        printf("impar. \n\n");
    }
}

