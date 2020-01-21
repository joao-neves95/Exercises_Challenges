/*

By: Jo�o Neves (SHIVAYL)

*/
#include <stdio.h>
#include <locale.h>

#define CITY_NUM 5

typedef struct {
    char cityName[50];
    int celcius;
    int fahrenheit;

} CityTemperature;

int main( int argc, const char* argv[] )
{
    setlocale(LC_ALL, "");
    
    CityTemperature cityTemperatures[CITY_NUM];
    
    printf("Escreva o nome de %d cidades e as suas respetiva temperatura em graus Celcius. \n", CITY_NUM);
    
    int sumCelciusTemp = 0;
    int smallestTempCityIdx = 0;
    int biggestTempCityIdx = 0;
    
    int i;
    for (i = 0; i < CITY_NUM; ++i) {
        printf("\nNome da cidade n� %d: ", i + 1);
        scanf("%s", &cityTemperatures[i].cityName);
        
        printf("Temperatura em celcius da cidade \"%s\": ", cityTemperatures[i].cityName);
        scanf("%d", &cityTemperatures[i].celcius);
        
        
        if (cityTemperatures[i].celcius < cityTemperatures[smallestTempCityIdx].celcius) {
            smallestTempCityIdx = i;
        }
        
        if (cityTemperatures[i].celcius > cityTemperatures[biggestTempCityIdx].celcius) {
            biggestTempCityIdx = i;
        }
        
        // �F = �C * 1.8 + 32
        cityTemperatures[i].fahrenheit = cityTemperatures[i].celcius * 1.8 + 32;
        sumCelciusTemp += cityTemperatures[i].celcius;
    }
    
    printf("\n\n");
    printf("A cidade com a temperatura mais baixa � \"%s\", com %d�C. \n", cityTemperatures[smallestTempCityIdx].cityName, cityTemperatures[smallestTempCityIdx].celcius);
    printf("A cidade com a temperatura mais alta � \"%s\", com %d�C. \n", cityTemperatures[biggestTempCityIdx].cityName, cityTemperatures[biggestTempCityIdx].celcius);
    printf("A temperatura temperatura m�dia � de %.2f�C.", (float)sumCelciusTemp / CITY_NUM);
    printf("\n\n\n");
    
    printf("Estas s�o todas as cidades inseridas, juntamente com as respectivas temperaturas: \n\n");
    
    for (i = 0; i < CITY_NUM; ++i) {
        printf("Cidade: %s, ", cityTemperatures[i].cityName);
        printf("%d�C, ", cityTemperatures[i].celcius);
        printf("%d�F \n", cityTemperatures[i].fahrenheit);
    }

    printf("\n\n");
    system("pause");
	return 0;
}

