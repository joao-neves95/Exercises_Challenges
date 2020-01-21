#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    
    // short valor = 32;
    // short valor = 100;
    // short valor = 90000;
    int valor = 90000;

    int tamanho;
    tamanho = sizeof(valor);
    
    printf("Um short int : %d\n",valor);
    printf("espaco de memoria ocupado pela variavel: %d bytes", tamanho);
    return 0;
}

/*
a) Compile e execute o programa. O que aparece escrito no monitor?
Aparece o output:
"Um short int : 32
espaco de memoria ocupado pela variavel: 2 bytes"

b) Edite o programa e altere o valor 32 para um outro valor inteiro relativamente baixo, digamos 100.
Compile e corra o programa.

c) Altere o valor para 90000 e tente compilar o programa. O que � que acontece? Porqu�?
Como uma variavel de tipo short apenas pode alocar numeros entre -32768 a 32767, quando
se muda o valor desta variavel para um numero superior cria um overflow.
Neste caso o n�mero de sa�da ("valor") � 24464.

d) Edite o programa e altere a palavra �short� para �int�. Compile e corra o programa. Qual a diferen�a
entre esta e a al�nea anterior?
Se mudarmos o tipo de vari�vel de short para int, neste caso n�o acontece nenhum overflow,
pois podemos guardar numeros entre -2147483648 a 2147483647.
Neste caso, o numero de saida � efetivamente o 90000, o n�mero que queromos, ao contratio
da alinea anterior.

*/

