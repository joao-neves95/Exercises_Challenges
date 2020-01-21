/*

By: Jo�o Neves (SHIVAYL)

Crie um programa que recebe do teclado duas palavras e 
determina se estas s�o iguais.
Apenas poder� usar as fun��es scanf e printf.
Relembra-se que em C n�o � poss�vel comparar vetores,
apenas seus valores um a um.

*/
#include <stdio.h>
#include <locale.h>

#define STRING_BUFFER_SIZE 100

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");
    
    printf("Palavras Iguais \n\n");
    
    char str1[STRING_BUFFER_SIZE];
    printf("Insira uma palavra: ");
    scanf("%s", str1);
    
    char str2[STRING_BUFFER_SIZE];
    printf("Insira outra palavra: ");
    scanf("%s", str2);
    
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; ++i) {
        if (str1[i] != str2[i] ||
            str1[i + 1] == '\0' && str2[i + 1] != '\0' ||
            str2[i + 1] == '\0' && str1[i + 1] != '\0'
        ) {
            printf("As palavras s�o diferentes! \n\n");

            system("pause");
	        return 0;
        }
    }
    
    printf("As palavras s�o iguais! \n\n");

    system("pause");
	return 0;
}

