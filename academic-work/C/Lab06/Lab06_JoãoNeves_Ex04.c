/*

By: Jo�o Neves (SHIVAYL)

Crie um programa que recebe uma frase introduzida pelo utilizador.
Pe�a igualmente para o utilizador inserir uma letra.
Dever� informar qual a posi��o em que esse carater aparece pela primeira vez.
Caso n�o apare�a indique a posi��o -1.
Exemplo de utiliza��o do programa:

Insira uma palavra: abracadabra
Insira uma letra a pesquisar: r
A letra a ocorre a primeira vez na posi��o 2

*/
#include <stdio.h>
#include <locale.h>

#define STRING_BUFFER_SIZE 100

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");

    printf("Posi��o da Primeira Ocorr�ncia de uma Letra \n\n");
    
    char word[STRING_BUFFER_SIZE];
    printf("Insira uma palavra: ");
    scanf("%s", word);
    
    char letter;
    printf("Insira uma letra a pesquisar: ");
    fflush(stdin);
    scanf("%c", &letter);
    
    int i;
    for (i = 0; ; ++i) {
        if (word[i] == letter) {
            break;
        
        } else if (word[i + 1] == '\0') {
            i = -1;
            break;
        }
    }
    
    printf("A letra \"%c\" ocorre a primeira vez na posi��o %d \n\n", letter, i);

    system("pause");
	return 0;
}

