#include <stdio.h>

#define NAVBAR "########################"

void start();
void convert(int minutes);

// # struct to responsable to save the convert of minutes to hours and 
typedef struct hours{
	int hour;
	int minutes;	
} hora;

void main(){
	start();
}

void start(){
	// # Main function.
	int qtdMinutes;

	printf("%s\n#\tConversor\n# Informe a quantidade em minutos: ", NAVBAR);
	scanf("%i", &qtdMinutes);

	convert(qtdMinutes);
}

void convert(int minutes){

	hora.hour = minutes/60;
	hora.minutes = minutes-(hora.hour)*60;

	printf("# %i horas e %i minutos\n", hora.hour, hora.minutes);
}
