#include <locale.h>
#include <stdio.h>
// #include <stdlib.h>

int main () {
    /*
    Adicionei o setlocale, a fim de poder imprimir caracteres especiais.

    Por alguma raz�o, adicionar "Portuguese" no setlocale, imposs�bilita
    o input de n�meros decimais com pontos e apenas admite scanfs com virgulas.
    Para resolver o problema, configurei o setlocale para a linguagem que o
    utilizador tem na sua m�quina. Testei em duas m�quinas diferentes e
    n�o se verifica o problema (o utilizador t�m que ter a sua m�quina
    configrada para portugu�s)
    */
    setlocale(LC_ALL, "");

    // Alterei a disposi��o da declara��o de vari�veis de forma l�gica.
    // (situam-se no seu devido bloco l�gico)

    // Alterei o tipo das variaveis de input de int para float, de forma
    // admitir calculos com numeros decimais.
    float n1;
    float n2;
    printf("Introduza um n�mero: ");
    scanf("%f", &n1);
    printf("Introduza outro n�mero: ");
    // Adicionei o simbolo "&" � variavel de entrada no scanf (n2),
    // de forma a enviar o seu endere�o e n�o valor, sendo possivel
    // assim o scanf criar um ponteiro para a mesma.
    scanf("%f", &n2);

    char opcao;
    printf("Introduza a opera��o (carater: +, -, *, /): ");
    /*
    Alterei a formata��o do scanf para de %d (ints) para %c (chars),
    adicionando um espa�o antes do format de forma a retirar whitespace.
    Como exemplificado abaixo, tamb�m � poss�vel fazer um fflush ao stdin,
    por�m n�o considero necess�rio importar o stdlib completo apenas devido
    a esta fun��o. Al�m do mais, assim � mais limpo, simples e certos compiladores
    n�o reconhecem o fflush.
    */
    // fflush(stdin);
    scanf(" %c", &opcao);

    printf("\n");

    float resultado;
    switch (opcao) {
            // Alterei as opera��es de soma e subtra��o pois estavam trocadas.
        case '+':
            resultado = n1 + n2;
            // Alterei a formata��o do printf de int para float.
            printf ("Resultado da soma: %.2f \n", resultado);
            break;
        case '-':
            resultado = n1 - n2;
            printf ("Resultado da subtra��o: %.2f \n", resultado);
            // Adicionei um beak.
            break;
        case '*':
            // Alterei o segundo n�mero para n2.
            resultado = n1 * n2;
            printf ("Resultado da multiplica��o: %.2f \n", resultado);
            // Adicionei um beak.
            break;
        case '/':
            // Adicionei chavetas, pois todos os blocos de c�digo, inclu�do
            // ifs, devem conte-las devido a proporcionarem melhor readability
            // e melhor manuten��o.
            //
            // Alterei a condi��o de != para == (igualdade).
            if (n2 == 0) {
                printf("Nao � possivel dividir por 0!! \n");
            }
            // Adicionei chavetas de forma a conter ambas as seguintes
            // express�es e a serem executadas, nomeadamente o printf,
            // apenas a quando da execuss�o do bloco else.
            else {
                // Alterei a ordem das vari�veis
                // (o primeiro n�mero a dividir pelo segundo).
                resultado = n1 / n2;
                printf("Resultado da divis�o: %.2f \n", resultado);
            }
            break;
        default:
            printf("Selecionou uma opera��o n�o existente.");
            // Adicionei uma pausa de sistema.
            system("pause");
            // Adicionei o return abaixo de forma a informar que o programa
            // terminou com um erro.
            return 1;
    }

    // Adicionei uma pausa de sistema de forma a ser poss�vel ver o resultado
    // antes do processo da consola terminar.
    system("pause");
    // Adicionei o return do valor 0, de forma a indicar que o programa terminou
    // sem erros.
    return 0;
}

