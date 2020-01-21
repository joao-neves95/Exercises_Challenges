#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
	float valor = 900.25;
	int tamanho;
	tamanho = sizeof(valor);
	printf("Um float : %f\n", valor);
	printf("Um float com format��o %%E : %E\n", valor);
	printf("Um float com format��o %%e : %e\n", valor);
	printf("espaco de memoria ocupado: %d bytes", tamanho);
    return 0;
}

/*
a) Compile e execute o programa. O que aparece escrito no monitor?
Aparece o output:
"Um float : 900.250000
espaco de memoria ocupado: 4 bytes"

b) O que ir� aparecer no monitor se alterar o especificador de formato de %f para %E.
Como a formata��o do nosso valor foi alterado para nota��o cientifica,
em vez do n�mero real 900.250000, aparece o valor 9.002500E+002, com "E" grande.

c) E se alterar para %e?
Apareecer� o valor 9.002500e+002, com o "e" pequeno.

*/

