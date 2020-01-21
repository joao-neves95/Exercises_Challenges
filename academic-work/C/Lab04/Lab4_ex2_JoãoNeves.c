#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    int num;
    printf("Insere um n�mero para eu te falar dele: ");
    scanf("%d", &num);

    // se est� entre 0 e 100 (inclusiv�).
    if (num >= 0 && num <= 100) {
        printf("O n�mero est� entre 0 e 100 (inclusiv�)\n");
    } else {
        printf("O n�mero � menor que 0 ou maior que 100\n");
    }
    if ( !(num < 0) && !(num > 100) ) {
        printf("O n�mero est� entre 0 e 100 (inclusiv�)\n");
    } else {
        printf("O n�mero � menor que 0 ou maior que 100\n");
    }

    // se � par
    if ( num % 2 == 0 ) {
        printf("O n�mero � par\n");
    } else {
        printf("O n�mero � impar\n");
    }
    if ( !(num % 2 != 0) ) {
        printf("O n�mero � par\n");
    } else {
        printf("O n�mero � impar\n");
    }

    // se � m�ltiplo de 5 mas n�o � m�ltiplo de 2
    if (num % 5 == 0 && num % 2 != 0) {
        printf("O n�mero � m�ltiplo de 5 mas n�o � m�ltiplo de 2\n");
    }
    if ( !(num % 5 != 0) && !(num % 2 == 0) ) {
        printf("O n�mero � m�ltiplo de 5 mas n�o � m�ltiplo de 2\n");
    }

    // Se est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um
    // n�mero par
    if ( (num >= -20 && num <= -10 || num >= 10 && num <= 20) && num % 2 == 0 ) {
        printf("O n�mero est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um n�mero par\n");
    }
    if ( ( !(num < -20) && !(num > -10) || !(num < 10) && !(num > 20) ) && !(num % 2 != 0)) {
        printf("O n�mero est� entre -20 e -10 (inclusiv�) ou entre 10 e 20 (inclusiv�) e � um n�mero par\n");
    }

    // Se � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos
    int dividedBy100 = num / 100;
    if (num % 7 == 0 && num >= 0 && dividedBy100 >= 1 && dividedBy100 <= 9) {
        printf("O n�mero � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos\n");
    }
    if (!(num % 7 != 0) && !(num < 0) && !(dividedBy100 < 1) && !(dividedBy100 > 9)) {
        printf("O n�mero � um m�ltiplo de 7, n�o � negativo e tem 3 d�gitos\n");
    }

    system("pause");
    return 0;
}

