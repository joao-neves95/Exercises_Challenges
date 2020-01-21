
#include <stdio.h>
#include <locale.h>

#define INPUT_SIZE 20

void askMaxNum(int *maxValue);
int pede_numeros(int *maxValue, int *inputNumArr, size_t quantity);
void printNumArr(int *inputNumArr, size_t arrSize);

int main()
{
	setlocale(LC_ALL, "");
	int maxValue;
	int nums[INPUT_SIZE];

	askMaxNum(&maxValue);
	int sum = pede_numeros(&maxValue, nums, INPUT_SIZE);
	printNumArr(nums, INPUT_SIZE);
	
	printf("\n\nA m�dia de todos os n�meros pedidos � %.2f: ", (float)sum / INPUT_SIZE);

    return 0;
}

void askMaxNum(int *maxValue) {
    printf("Escreva o valor m�ximo: ");
    scanf("%d", maxValue);
}

/*
    Asks for n (quantity) numbers and returns the sum of all numbers.
*/
int pede_numeros(int *maxValue, int *inputNumArr, size_t quantity) {
	int sum = 0;
	int i = 0;

	do {
		printf("Escreva um n�mero menor que %d: ", *maxValue);
		scanf("%d", inputNumArr + i);

		if ( *(inputNumArr + i) > *maxValue) {
			printf("O n�mero tem que ser menor que %d! \n", *maxValue);

		} else {
			++i;
			sum += *(inputNumArr + i);
		}

	} while (i < quantity);
	
	return sum;
}

void printNumArr(int *inputNumArr, size_t arrSize) {
    printf("\n\n");

	int i;
	for (i = arrSize - 1; i >= 0; --i) {
		printf( "%d", *(inputNumArr + i) );
		
		if (i > 0) {
			printf(", ");

		} else {
		    printf(". \n\n");
		}
	}
}

