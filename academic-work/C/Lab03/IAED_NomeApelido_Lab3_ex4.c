#include <stdio.h>
int main()
{
	char c = 'r';
	short j = 127;
	int k = 32767;
	printf("c= %c\n", c);
	c = c + 1;
	printf("c= %c\n", c);
	c = c + 1;
	printf("c= %c\n", c);
	printf("j= %d\n", j);
	j = j - 1;
	printf("j= %d\n", j);
	j++;
	printf("j= %d\n", j);
	printf("k= %d\n", k);
	k -= 4;
	printf("k= %d\n", k);
	k = k + 5;
	printf("k= %d\n", k);
	printf("Valores finais:\n\tc = %c\n\tj = %d", c, j);
	printf("\n\tk = %d\n\n", k);
	int y = 4895555;
	printf("y= %d\n", y);
	return 0;
}

/*
Corrija os erros sint�cticos do programa. Lembre-se que vari�veis s�o sens�veis �s mai�sculas, cada instru��o
deve terminar com �;�, e dentro do printf a express�o a imprimir deve estar entre aspas.
*/

