/*

By: Jo�o Neves (SHIVAYL)

*/
#include <stdio.h>
#include <locale.h>

int *ask2Numbers();
size_t calcula_pares(int num1, int num2);
void apresenta_resultados(int num1, int num2, size_t pairNum);

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");
    
    int *nums = ask2Numbers();
    apresenta_resultados(nums[0], nums[1], calcula_pares(nums[0], nums[1]));

    system("pause");
	return 0;
}

/*
 * Returns [num1, num2]
 */
int *ask2Numbers() {
    int nums[2];
    
    do {
        printf("Escreva um n�mero inteiro: ");
        scanf("%d", &nums[0]);
        
        printf("Escreva outro n�mero inteiro maior que o anterior: ");
        scanf("%d", &nums[1]);
        
        if (nums[0] > nums[1]) {
            printf("O segundo n�mero tem de ser maior que o primeiro! \n\n");
        }
        
    } while (nums[0] > nums[1]);
    
    return nums;
}

size_t calcula_pares(int num1, int num2) {
    size_t pairQuant = 0;
    
    while (num1 <= num2) {
        if (num1 % 2 == 0) {
            ++pairQuant;
        }

        num1 += 1;
    }
    
    return pairQuant;
}

void apresenta_resultados(int num1, int num2, size_t pairNum) {
    printf("Entre %d e %d existem %d n�meros pares. \n\n", num1, num2, pairNum);
}

