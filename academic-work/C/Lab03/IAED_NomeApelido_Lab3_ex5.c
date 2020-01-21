#include <stdio.h>

int main()
{
	int notaTeste1 = 15;
	int notaTeste2 = 15;
	int notaTeste3 = 17;
	double media;
    // media = (notaTeste1 + notaTeste2 + notaTeste3) / 3;
    media = (notaTeste1 + notaTeste2 + notaTeste3) / 3.0;
	printf("Nota final (%%f) : %f valores\n", media);
    printf("Nota final (%%3.0f) : %3.0f valores\n", media);
    printf("Nota final (%%3.2f) : %3.2f valores\n", media);
	return 0;
}

/*
a) Compile, corra o programa e examine a sua sa�da. Concorda com o resultado? O que ter� acontecido?
O output do programa (m�dia) � 15.000000. Este valor � errado e deve.se ao facto da m�dia n�o ser
feita com um float ou decimal. Como as contas s�o feitas apenas como ints, o compilador retorna
o resultado arredondado ao n�mero decimal mais pr�ximo (floor).

b) Substitua a instru��o do c�lculo da m�dia pela instru��o seguinte e observe o que � escrito pelo programa.
media = (notaTeste1 + notaTeste2 + notaTeste3)/3.0;
Neste caso o resultado j� � 15.66666, o valor correto sem arredondamentos.

c) Na instru��o printf substitua %f por %3.0f e observe o resultado.

d) Na instru��o printf substitua %f por %3.2f e observe o resultado

e) Altere o programa de modo a que as notas dos testes sejam inseridas pelo utilizador.

*/

