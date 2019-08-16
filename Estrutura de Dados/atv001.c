#include <stdio.h>

/* # Variables */
int sex = 0, finished = 0, count = 0, countWoman = 0, countMan = 0;
float length = 0.0, mid = 0.0, lengthMax = 0.0, womanMidLenght = 0.0, manMidLenght = 0.0;

/* # Consts */
#define NAVBAR "#########################"

/* # Procedures */
void start;
void result;

void main(){
	start();
}

void start(){
	do {
		printf("%s\nATV001 - ED\n%s\n\nInfome o sexo (1-Masculino/2-Feminino): ", NAVBAR, NAVBAR);
		scanf("%i", &sex);

		printf("Informe a altura: \n");
		scanf("%f", &length);

		count++;

		// average lenght.
		mid = (mid+length)/count;
		// max lenght.
		if (length > lengthMax) lengthMax = length;
		// average lenght woman and man
		if (sex = 2){
			countWoman++;
			womanMidLenght = (womanMidLenght+length)/countWoman;
		} else {
			countMan++;
			manMidLenght = (manMidLenght+length)/countMan;
		}

	} while(finished != 1);
	result();
}

void result(){
	printf("\n\n%s\nAltura media: %f\nAltura maxima: %f\n"
	"Altura media das mulheres: %f\nAltura media dos homens: %f\n"
	"Quantidade de homens: %i", NAVBAR, lengthMax, womanMidLenght, manMidLenght, countMan);
}
