/*
Escreva um programa que solicite ao utilizador para inserir um carater.
Indique o c�digo ASCII do carater inserido.
Indique tamb�m se se trata de uma letra ou um n�mero, e se a letra � mai�scula ou min�scula.
*/

#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    printf("Escreva um caracter: ");
    char inputChar;
    scanf("%c", &inputChar);

    printf("O c�digo ASCII do carater inserido �: %d.\n", inputChar);

    if (inputChar >= 65 && inputChar <= 122) {
        const char message[] = "O caracter inserido � uma letra";

        if (inputChar <= 90) {
            printf("%s mai�scula.\n", message);

        } else if (inputChar >= 97) {
            printf("%s min�scula.\n", message);
        }

    } else if (inputChar >= 48 && inputChar <= 57) {
        printf("O caracter inserido � um n�mero.\n");
    }

    system("pause");
    return 0;
}

